/************************************

   Author:         Daniel Stanev
   Course:         CS 1337.012
   Date:           26 Feb 2021
   Assignment:     Homework #2: Sort by Pointers
   Compiler:       MinGW-w64

   Description: Stores data from a file
   to an array and a pointer array. Sorts
   the pointer array so that the data is
   sorted without editing original array.

 *************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

void SwapIntPtr(int* &ptr1, int* &ptr2) {
    int* temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
} // end function

void ReadIntoDataArray(std::ifstream& file, int array[], int *ptrArray[], int& i) {
    // declares necessary variables
    std::istringstream ss;
    std::string tempString;
    int tempInt;

    // stores the entire line into a string and then passes the string to an istringstream object
    std::getline(file, tempString);
    ss.str (tempString);

    // extracts integers from the string
    while (ss >> tempInt) {
        array[i] = tempInt;
        ptrArray[i] = &array[i];
        i++;
    } // end while loop
} // end function

void bubbleSort(int *ptrArray[], int size) {
    int i;

    // bubble-sorts the entire pointer array
    while (size > 0) {
        i = 0;
        while (i < (size -1)) {
            // swaps two pointers if the value of the first is greater than the second
            if (*ptrArray[i] > *ptrArray[i+1])
                SwapIntPtr(ptrArray[i], ptrArray[i + 1]);
            i++;
        } // end inner while loop
        size--;
    } // end outer while loop
} // end function

void displaySortedData(int *ptrArray[], int size) {
    int i = 0;

    // prints out sorted pointer array
    std::cout << "Sorted Array: " << std::endl;
    while (i < size) {
        std::cout << std::setw(6) << *ptrArray[i];
        i++;
    } // ends the while loop
    std::cout << std::endl;
} // end function

void displayUnsortedData(int array[], int size) {
    int i = 0;

    // prints out original unsorted array
    std::cout << "Unsorted Array: " << std::endl;
    while (i < size) {
        std::cout << std::setw(6) << array[i];
        i++;
    } // end while loop
    std::cout << std::endl;
} // end function

int main() {
    // declares all necessary variables for main
    int size;
    int array[10];
    int* ptrArray[10];
    std::ifstream file;

    file.open("arrayData.txt");

    // while the end of the file is not reached
    while (!(file.eof())) {
        size = 0; // resets the size for new array

        // reads from file and sorts pointer array
        ReadIntoDataArray(file, array, ptrArray, size);
        bubbleSort(ptrArray, size);

        // displays all the data
        displaySortedData(ptrArray, size);
        displayUnsortedData(array, size);

        // pauses the screen so the user has time to look
        std::cout << "Press the enter key once or twice to continue..." << std::endl;
        std::cin.ignore();
        std::cin.get();
    } // end while loop

    file.close(); // closes file
    return 0;
} // end function main