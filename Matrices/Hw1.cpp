/************************************

   Author:         Daniel Stanev
   Course:         CS 1337.012
   Date:           5 Feb 2021
   Assignment:     Homework #1: Matrices
   Compiler:       MinGW-w64

   Description: Takes in matrices and
   checks for vertical additive symmetry,
   then sorts each row of each matrix.

 *************************************/


#include <iostream>
#include <fstream>
#include <algorithm>

void matrixCalculation();

void matrixCalculation(std::ifstream& file){
    // declares variables needed for function
    int row, column,colSum1 , colSum2;
    int i, j;
    int matrix[20][20];
    bool verticalAddative = true;

    // runs while loop until end of file
    while(!file.eof()) {
        verticalAddative = true;
        i = 0;
        file >> row;
        file >> column;

        std::cout << "input:" << std::endl;
        // fills up the required part of the array
        while(i < row){
            j = 0;
            while(j < column){
                file >> matrix[i][j];
                std::cout << "\t" << matrix[i][j];
                j++;
            }
            std::cout << std::endl;
            i++;
        }


        std::cout << "sums:" << std::endl;
        i = 0 ;

        // checks the sum of each column and prints it out
        while (i < column) {
            j = 0;
            colSum1 = 0;
            colSum2 = 0;
            while (j < row) {
                colSum1 += matrix[j][i];
                j++;
            }
            std::cout << "\t" <<colSum1 ;
            j = 0;
            while (j < row) {
                colSum2 += matrix[(j)][column - (i+1)];
                j++;
            }
            if (colSum1 != colSum2){
                verticalAddative = false;
            }
            i++;
        }
        std::cout << std::endl << std::endl;

        // prints out if there is vertical additvi symmetry
        std::cout << "Vertical additive symmetry: ";
        if (verticalAddative)
            std::cout << "Yes" << std::endl << std::endl;
        else
            std::cout << "No" << std::endl << std::endl;

        std::cout << "sorted:" << std::endl;
        i = 0;

        // sorts each row of the matrix
        while (i < row) {
            std::sort (matrix[i], matrix[i] + column);
            i++;
        }

        // prints out the sorted version of each matrix
        i = 0;
        while (i < row) {
            j = 0;
            while (j < column) {
                std::cout << "\t" << matrix[i][j];
                j++;
            }
            std::cout << std::endl;
            i++;
        }
        std::cout << std::endl << std::endl;
        std::cout << "Press the enter key once or twice to continue..." << std::endl; std::cin.ignore(); std::cin.get();
    }

}

int main() {
    std::ifstream matrix;

    matrix.open("matrixes.txt");

    // if matrix.txt cannot be opened
    if (!(matrix.is_open())){
        std::cout << "The file matrixes.txt could not be opened.";
        return 1;
    }

    // runs all the calculation stuff
    matrixCalculation(matrix);

    matrix.close();
    return 0;
}
