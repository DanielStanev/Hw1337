#include "Employee.h"
#include <iostream>
#include <iomanip>

// constructors
Employee::Employee() {}
Employee::Employee(std::string employeeId, std::string lastName, std::string firstName, std::string birthDate, char gender, std::string startDate, double salary) {
    this->employeeId = employeeId;
    this->lastName = lastName;
    this->firstName = firstName;
    this->birthDate = birthDate;
    this->gender = gender;
    this->startDate = startDate;
    this->salary = salary;
}

// getter methods
std::string Employee::getEmployeeId()   { return employeeId; }
std::string Employee::getLastName()     { return lastName;   }
std::string Employee::getFirstName()    { return firstName;  }
std::string Employee::getBirthDate()    { return birthDate;  }
char Employee::getGender()              { return gender;     }
std::string Employee::getStartDate()    { return startDate;  }
double Employee::getSalary()            { return salary;     }

// setter methods
void Employee::setEmployeeId(std::string employeeId) { this->employeeId = employeeId; }
void Employee::setLastName(std::string lastName)     { this->lastName = lastName;     }
void Employee::setFirstName(std::string firstName)   { this->firstName = firstName;   }
void Employee::setBirthDate(std::string birthDate)   { this->birthDate = birthDate;   }
void Employee::setGender(char gender)                { this->gender = gender;         }
void Employee::setStartDate(std::string startDate)   { this->startDate = startDate;   }
void Employee::setSalary(double salary)              { this->salary = salary;         }

// employee methods
// sorts array of employee pointers alphabetically by last name
void bubbleSort(Employee* array[], int size) {
    int i, j = size;
    Employee* temp;

    while (j > 0) {
        i = 0;
        while (i < (size -1)) {
            if (array[i]->getLastName() > array[i + 1]->getLastName()) {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
            i++;
        } // end inner while loop
        j--;
    } // end outer while loop
} // end function bubbleSort

// displays all of the employees
void displayEmployees(Employee* array[], int size) {
    int i = 0;
    std::cout << std::fixed << std::setprecision(0) << std::right;
    std::cout << std::setw(6) << "ID" << std::setw(12) << "LastName" << std::setw(12) << "FirstName" << std::setw(11) << "BirthDate";
    std::cout << std::setw(7) << "Gender" << std::setw(11) << "StartDate" << std::setw(7) << "Salary" << std::endl;

    while(i < size) {
        std::cout << std::setw(6) << array[i]->getEmployeeId();
        std::cout << std::setw(12) << array[i]->getLastName();
        std::cout << std::setw(12) << array[i]->getFirstName();
        std::cout << std::setw(11) << array[i]->getBirthDate();
        std::cout << std::setw(7) << array[i]->getGender();
        std::cout << std::setw(11) << array[i]->getStartDate();
        std::cout << std::setw(7) << array[i]->getSalary();
        std::cout << std::endl;

        i++;
    } // end while loop

    std::cout << "Press enter once or twice to continue.";
    std::cin.ignore();
    std::cin.get();
} // end function displayEmployees

// displays an employee by index
void displayEmployee(Employee* array[], int index) {
    if (index == -1) {
        std::cout << "Employee not found." << std::endl << std::endl;
        return;
    }

    std::cout << std::setw(6) << "ID" << std::setw(12) << "LastName" << std::setw(12) << "FirstName" << std::setw(11) << "BirthDate";
    std::cout << std::setw(7) << "Gender" << std::setw(11) << "StartDate" << std::setw(7) << "Salary" << std::endl;

    std::cout << std::setw(6) << array[index]->getEmployeeId();
    std::cout << std::setw(12) << array[index]->getLastName();
    std::cout << std::setw(12) << array[index]->getFirstName();
    std::cout << std::setw(11) << array[index]->getBirthDate();
    std::cout << std::setw(7) << array[index]->getGender();
    std::cout << std::setw(11) << array[index]->getStartDate();
    std::cout << std::setw(7) << array[index]->getSalary();
    std::cout << std::endl;

    std::cout << "Press enter once or twice to continue.";
    std::cin.ignore();
    std::cin.get();
} // end function display Employee

// adds an employee to the array
void addEmployee(Employee* array[], int& size) {
    std::string employeeId;
    std::string lastName;
    std::string firstName;
    std::string birthDate;
    char gender;
    std::string startDate;
    double salary;

    std::cout << "Please enter 6 digit ID: ";
    std::cin >> employeeId;
    std::cout << "Please enter a last name: ";
    std::cin >> lastName;
    std::cout << "Please enter a first name: ";
    std::cin >> firstName;
    std::cout << "Please enter a date of birth in MM/DD/YYYY: ";
    std::cin >> birthDate;
    std::cout << "Please enter a gender: ";
    std::cin >> gender;
    std::cout << "Please enter a starting date in MM/DD/YYYY: ";
    std::cin >> startDate;
    std::cout << "Please enter a salary: ";
    std::cin >> salary;

    Employee* p1 = new Employee(employeeId, lastName, firstName, birthDate, gender, startDate, salary);
    array[size] = p1;
    size++;
} // end function addEmployee

// returns the index of an employee based on id, returns -1 if not found
int lookUpEmployee(Employee* array[], int size) {
    std::string id;
    int i = 0;

    std::cout << "Enter Employee ID: ";
    std::cin >> id;
    while (i < size) {
        if (id == array[i]->getEmployeeId()) {
            return i;
        }
        i++;
    }
    return -1;
} // end function lookUpEmployee

void removeEmployee(Employee* array[], int& size, int index) {
    if(index == -1) {
        std::cout << "Employee not found." << std::endl << std::endl;
        return;
    }
    Employee* p1 = array[index];
    delete p1;
    index++;
    while(index < size) {
        array[index - 1] = array[index];
        index++;
    } // end while loop
    size--;
} // end function removeEmployee