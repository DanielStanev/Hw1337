#include <iostream>
#include <fstream>
#include <string>
#include "Employee.h"
#include "FileIO.h"

int main() {
    std::ifstream input;
    std::ofstream output;
    int size = 0, choice, index;
    Employee* array[100];

    // opens Employee.txt if it exists and stores information inside an array
    input.open("Employee.txt");
    if(input) {
        size = countLines(input);
        readEmployees(input, array, size);
    } // end if
    input.close();

    // While loop that operates the menu of the program
    while(true) {
        std::cout << "Choose one of the following options: " << std::endl;
        std::cout << "1. Enter new employee infromation." << std::endl;
        std::cout << "2. Display all employee information in alphabetical order by last name." << std::endl;
        std::cout << "3. Look up an employee by ID." << std::endl;
        std::cout << "4. Remove an employee." << std::endl;
        std::cout << "5. Save all data to Employee.txt and exit." << std::endl << std::endl;
        std::cout << "Enter Selection: ";
        std::cin >> choice;

        if (choice == 1)
            addEmployee(array, size);
        else if (choice == 2) {
            if (size == 0) {
                std::cout << "No employees have been added yet." << std::endl << std::endl;
                continue;
            }
            bubbleSort(array, size);
            displayEmployees(array, size);
        }
        else if (choice == 3) {
            if (size == 0) {
                std::cout << "No employees have been added yet." << std::endl << std::endl;
                continue;
            }
            index = lookUpEmployee(array, size);
            displayEmployee(array, index);
        }
        else if (choice == 4) {
            if (size == 0) {
                std::cout << "No employees have been added yet." << std::endl << std::endl;
                continue;
            }
            index = lookUpEmployee(array, size);
            removeEmployee(array, size, index);
        }
        else if (choice == 5)
            break;
        else
            std::cout << "Invalid Selection, please try again." << std::endl << std::endl;
    } // end while loop

    // writes contents of array to Employee.txt
    output.open("Employee.txt");
    writeEmployees(output, array, size);
    output.close();

    return 0;
} // end main