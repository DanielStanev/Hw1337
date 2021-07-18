#include <iostream>
#include <algorithm>
#include <iomanip>

int readNumbers(int list[]) {
    int x, i = 0;

    std::cout << "Please enter up to 100 positive integers and then enter 0 to end your input:" << std::endl;
    std::cout << "(Entering 0 as the first input ends program)" << std::endl;

    while(true) {

        // if the user enters an invalid input such as a char
        if (!(std::cin >> x)) {
            std::cout << "The value you entered is not valid; please enter another value" << std::endl;
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(1000, '\n'); //discard input
            continue;
        }

        // if the user enters an invalid input such as a negative number
        else if (x < 0) {
            std::cout << "The value you entered is not valid; please enter another value" << std::endl;
            continue;
        }

        // if the user enters 0
        else if (x == 0) {
            list[i] = 0;
            i++;
            break;
        }

        // if the user enters a valid input
        else {
            list[i] = x;
            i++;
        }

    }
    // returns the size of the array that is used
    return i;
}

void generateGrids(int* list, int size) {
    // declaring all variables used in the function
    int i = 0, j = 0, k = 0; // i, j, and k are counters for iterating through the arrays and matrices
    int bigSize = ((size - 1) * (size - 1));
    int additionGrid[size + 1][size + 1];
    int multiplicationGrid[size + 1][size + 1];
    int sums[bigSize];
    int products[bigSize];

    // generates the top rows of the matrices
    while (i < size) {
        additionGrid[0][i] = list[i];
        multiplicationGrid[0][i] = list[i];
        i++;
    }

    // sorts the top rows of the matrices
    std::sort(additionGrid[0], additionGrid[0] + i);
    std::sort(multiplicationGrid[0], multiplicationGrid[0] + i);

    // generates the leftmost column of the matrices
    i = 1;
    while (i < size) {
        additionGrid[i][0] = additionGrid[0][i];
        multiplicationGrid[i][0] = multiplicationGrid[0][i];
        i++;
    }

    // generates the entire rest of the matrices
    i = 1;
    while (i < size) {
        j = 1;
        while (j < size) {
            additionGrid[i][j] = additionGrid[i][0] + additionGrid[0][j];
            multiplicationGrid[i][j] = multiplicationGrid[i][0] * multiplicationGrid[0][j];
            j++;
        }
        i++;
    }


    // makes an array of all the sums and all the products
    i = 1;
    while (i < size) {
        j = 1;
        while (j < size) {
            sums[k] = additionGrid[i][j];
            products[k] = multiplicationGrid[i][j];
            k++;
            j++;
        }
        i++;
    }

    // sorts the sum and product arrays
    std::sort(sums, sums + bigSize);
    std::sort(products, products + bigSize);

    // prints out the Sum Matrix
    std::cout << std::right; // right justifies both of the matrices
    std::cout << std::endl << "Sum Grid: " << std::endl << std::endl;

    i = 0;
    while(i < size) {
        j = 0;
        while (j < size) {
            std::cout << std::setw(8) << additionGrid[i][j];
            j++;
        }
        std::cout << std::endl;
        i++;
    }

    std::cout << std::endl;

    // prints out all the unique sums and their frequency
    std::cout << std::setw(7) << "value" << std::setw(7) << "count" << std::endl;
    i = 0;
    k = 0;
    while (i < bigSize) {
        j = 1;
        while(true) {
            if (sums[i] == sums[i + 1]){
                i++;
                j++;
            }
            else
                break;
        }
        std::cout << std::setw(7) << sums[i] << std::setw(7) << j << std::endl;
        k++;
        i++;
    }
    if (k == 1)
        std::cout << std::endl << "There is only 1 unique sum." << std::endl << std::endl;
    else
        std::cout << std::endl << "There is a total of " << k << " unique sums." << std::endl << std::endl;

    // prints out the Product Matrix
    std::cout << std::endl << "Product Grid: " << std::endl << std::endl;

    i = 0;
    while(i < size) {
        j = 0;
        while (j < size) {
            std::cout << std::setw(8) << multiplicationGrid[i][j];
            j++;
        }
        std::cout << std::endl;
        i++;
    }

    std::cout << std::endl;

    // prints out all the unique products and their frequency
    std::cout << std::setw(7) << "value" << std::setw(7) << "count" << std::endl;
    i = 0;
    k = 0;
    while (i < bigSize) {
        j = 1;
        while(true) {
            if (products[i] == products[i + 1]){
                i++;
                j++;
            }
            else
                break;
        }
        std::cout << std::setw(7) << products[i] << std::setw(7) << j << std::endl;
        k++;
        i++;
    }
    if (k == 1)
        std::cout << std::endl << "There is only 1 unique product." << std::endl << std::endl;
    else
        std::cout << std::endl << "There is a total of " << k << " unique products." << std::endl << std::endl;
}

int main() {
    int size;
    int list[100];

    std::cout << "Welcome to the Number Grid Factory!" << std::endl << std::endl;

    while (true) {
        size = readNumbers(list);
        if (size == 1)
            break;
        generateGrids(list, size);
    }
    return 0;
}