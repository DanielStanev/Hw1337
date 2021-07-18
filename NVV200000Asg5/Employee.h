#include <string>

#ifndef NVV200000ASG5_EMPLOYEE_H
#define NVV200000ASG5_EMPLOYEE_H


class Employee {
public:
    // constructors
    Employee();
    Employee(std::string employeeId, std::string lastName, std::string firstName, std::string birthDate, char gender, std::string startDate, double salary);

    // getter methods
    std::string getEmployeeId();
    std::string getLastName();
    std::string getFirstName();
    std::string getBirthDate();
    char getGender();
    std::string getStartDate();
    double getSalary();

    // setter methods
    void setEmployeeId(std::string employeeId);
    void setLastName(std::string lastName);
    void setFirstName(std::string firstName);
    void setBirthDate(std::string birthDate);
    void setGender(char gender);
    void setStartDate(std::string startDate);
    void setSalary(double salary);

private:
    std::string employeeId;
    std::string lastName;
    std::string firstName;
    std::string birthDate;
    char gender;
    std::string startDate;
    double salary;
};

// employee methods
void bubbleSort(Employee* array[], int size);
void displayEmployees(Employee* array[], int size);
void addEmployee(Employee* array[], int& size);
void displayEmployee(Employee* array[], int index);
int lookUpEmployee(Employee* array[], int size);
void removeEmployee(Employee* array[], int& size, int index);

#endif // NVV200000ASG5_EMPLOYEE_H
