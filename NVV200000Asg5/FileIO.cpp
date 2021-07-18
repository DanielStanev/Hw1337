#include "FileIO.h"
#include "Employee.h"
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>

// counts the number of lines in a file
int countLines(std::ifstream& file) {
    int numLines = 0;
    std::string line;
    while(!file.eof()) {
        std::getline(file, line);
        numLines++;
    }
    file.clear();
    file.seekg(0, std::ios::beg);
    return numLines;
} // end function countLines

// reads employees from file to array
void readEmployees(std::ifstream& file, Employee* array[], int size) {
    int i = 0;
    std::string employeeId;
    std::string lastName;
    std::string firstName;
    std::string birthDate;
    std::string genderstr;
    char gender;
    std::string startDate;
    std::string salarystr;
    double salary;

    while(i < size) {
        std::getline(file, employeeId, ' ');
        std::getline(file, lastName, ' ');
        std::getline(file, firstName, ' ');
        std::getline(file, birthDate, ' ');
        std::getline(file, genderstr, ' ');
        std::getline(file, startDate, ' ');
        std::getline(file, salarystr);

        gender = genderstr[0];
        std::istringstream(salarystr) >> salary;

        Employee* p1 = new Employee(employeeId, lastName, firstName, birthDate, gender, startDate, salary);
        array[i] = p1;

        i++;
    } // end while loop
} // end function readEmployees

// writes employees from array to file
void writeEmployees(std::ofstream& file, Employee* array[], int size) {
    int i = 0;
    while (i < size) {
        file << array[i]->getEmployeeId() << " ";
        file << array[i]->getLastName() << " ";
        file << array[i]->getFirstName() << " ";
        file << array[i]->getBirthDate() << " ";
        file << array[i]->getGender() << " ";
        file << array[i]->getStartDate() << " ";
        file << array[i]->getSalary();
        if(i != (size - 1))
            file << std::endl;

        i++;
    } // end while loop
} // end function writeEmployees