#include <fstream>
#include "Employee.h"

#ifndef NVV200000ASG5_FILEIO_H
#define NVV200000ASG5_FILEIO_H

// functions for reading and writing employees to file
int countLines(std::ifstream& file);
void readEmployees(std::ifstream& file, Employee* array[], int size);
void writeEmployees(std::ofstream& file, Employee* array[], int size);


#endif // NVV200000ASG5_FILEIO_H
