#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <new>


typedef struct student {
    int studentID;
    std::string studentName;
    int testOne, testTwo, testThree;
    double average;
}student;

void displayMenu(int &choice) {
    while(true) {
        std::cout << "Please select one of the following options: " << std::endl;
        std::cout << "1. sort information by name" << std::endl;
        std::cout << "2. sort information by average" << std::endl;
        std::cout << "3. look up a student by ID" << std::endl;
        std::cout << "0. quit program" << std::endl;
        std::cout << "Enter selection: ";

        if(!(std::cin >> choice)) {
            std::cout << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid selection, please try again" << std::endl << std::endl;
            continue;
        }
        else if (choice > 3 || choice < 0) {
            std::cout << std::endl;
            std::cout << "Invalid selection, please try again" << std::endl << std::endl;
            continue;
        }
        else {
            break;
        }
    }
}

void bubbleSort(student *array[], int size, int selection) {
    int i, j = size;
    student* temp;

    while (j > 0) {
        i = 0;
        while (i < (size -1)) {
            if (selection == 2) {
                if (array[i]->average < array[i + 1]->average) {
                    temp = array[i];
                    array[i] = array[i+1];
                    array[i+1] = temp;
                }
            }
            else {
                if (array[i]->studentName > array[i + 1]->studentName) {
                    temp = array[i];
                    array[i] = array[i+1];
                    array[i+1] = temp;
                }
            }
            i++;
        }
        j--;
    }

    i = 0;
    std::cout << std::fixed << std::right << std::setprecision(2);
    std::cout << std::setw(20) << "Student Name";
    std::cout << std::setw(7) << "ID";
    std::cout << std::setw(7) << "Avg";
    std::cout << std::setw(7) << "Test 1" << std::setw(7) << "Test 2" << std::setw(7) << "Test 3";
    std::cout << std::endl;
    while (i < size) {
        std::cout << std::setw(20) << array[i]->studentName;
        std::cout << std::setw(7) << array[i]->studentID;
        std::cout << std::setw(7) << array[i]->average;
        std::cout << std::setw(7) << array[i]->testOne;
        std::cout << std::setw(7) << array[i]->testTwo;
        std::cout << std::setw(7) << array[i]-> testThree;
        std::cout << std::endl;

        i++;
    }
    std::cout << std::endl << std::endl;
}

void searchStudent(student *array[], int size){
    int id;
    int i = 0;

    std::cout << "Enter student ID: ";
    std::cin >> id;
    while (i < size) {
        student* currentStudent;
        currentStudent = array[i];
        if (id == currentStudent->studentID) {
            std::cout << std::endl;
            std::cout << "Student Name: " << currentStudent->studentName << std::endl;
            std::cout << std::right << std::fixed << std::setprecision(2);
            std::cout << std::setw(7) << "Average";
            std::cout << std::setw(7) << "Test 1" << std::setw(7) << "Test 2" << std::setw(7) << "Test 3" << std::endl;
            std::cout << std::setw(7) << currentStudent->average;
            std::cout << std::setw(7) << currentStudent->testOne;
            std::cout << std::setw(7) << currentStudent->testTwo;
            std::cout << std::setw(7) << currentStudent->testThree;
            std::cout << std::endl << std::endl;
            return;
        }
        i++;
    }
    std::cout << "Student not found" << std::endl << std::endl;
}

int main() {
    int i = 0;
    int id, t1, t2, t3, selection;
    student* array[100];
    std::string filename, name;
    std::ifstream file;

    while(true) {
        std::cout << "Please enter the name of the file: ";
        std::cin >> filename;
        file.open(filename.c_str());
        if(file)
            break;
        else
            std::cout << "The file could not be opened, please try again." << std::endl;
    }

    while (file >> id >> name >> t1 >> t2 >> t3) {
        student* p1 = new student;
        array[i] = p1;
        p1->studentID = id;
        p1->studentName = name;
        p1->testOne = t1;
        p1->testTwo = t2;
        p1->testThree = t3;
        p1->average = ((double)(t1 + t2 + t3))/(3.0);

        i++;
    }

    file.close();

    while (true) {
        displayMenu(selection);
        if (selection == 1 || selection == 2)
            bubbleSort(array, i, selection);
        else if (selection == 3)
            searchStudent(array, i);
        else
            return 0;
    }
}
