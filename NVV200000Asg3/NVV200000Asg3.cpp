#include <iostream>
#include <fstream>
#include <string>

void sortAndPrint(std::ifstream& file, double array[]) {
    // declares variables in sortAndPrint
    double currentValue;
    int maxIndex = 0, i = 0, j = 0;

    // stores the first value in array[0]
    file >> currentValue;
    array[0] = currentValue;

    while (file >> currentValue) {

        // finds out at what index the current value needs to be placed in
        while (i <= maxIndex) {
            if (currentValue > array[i])
                i++;
            else
                break;
        } // end while loop

        // moves up all the values that are greater than the current value if any
        j = maxIndex;
        while (j >= i) {
            array[j+1] = array[j];
            j--;
        } // end while loop

        // places the current value at its index, resets counter i and increments the max index counter
        array[i] = currentValue;
        i = 0;
        maxIndex++;
    } // end while loop

    // prints out the sorted array
    while (i <= maxIndex) {
        std::cout << array[i] << std::endl;
        i++;
    } // end while loop
} // end function sortAndPrint

int main() {
    // declaring all variables for the main method
    std::string filename;
    double array[100];
    std::ifstream file;

    while (true) {
        // prompts the user for the file name
        std::cout << "Please enter the name of the file you wish to sort, or enter an asterisk to terminate" << std::endl;
        std::cin >> filename;

        // checks if the terminate character was used
        if(filename == "*")
            return 0;
        else
            file.open(filename.c_str()); // standard streams only accept c-strings

        // error message if the file cannot be opened, else runs function sortAndPrint
        if(!(file.is_open()))
            std::cout << "The file could not be opened" << std::endl;
        else
            sortAndPrint(file, array);


        file.close(); // closes the file after finishing
    } // end while loop
} // end function main