#include <iostream>
#include <iomanip>
#include <fstream>

// Stores all the information about each person
typedef struct person {
    char name[20];
    double salary;
    int counter;
}person;

// Stores information from file into an array
void fileToArray(std::fstream& file, person* array[], int& size) {
    char name[20];
    double salary;
    int counter;

    while (!(file.eof())) {
        person* p1 = new person;
        array[size] = p1;

        file.read(name, 20);
        file.read(reinterpret_cast<char *> (&salary), sizeof(salary));
        file.read(reinterpret_cast<char *> (&counter), sizeof(counter));

        for(int i = 0; i < 20; i++)
            p1->name[i] = ' ';
        for(int i = 0; i < 20; i++)
            p1->name[i] = name[i];
        p1->salary = salary + 100;
        p1->counter = counter;

        size++;
    }// end while loop

    // Set at index = size - 1, because the loop above reads the final person twice so I utilize that space
    for(int i = 0; i < 20; i++)
        array[size - 1]->name[i] = ' ';
    array[size - 1]->name[0] = 'N';
    array[size - 1]->name[1] = 'i';
    array[size - 1]->name[2] = 'k';
    array[size - 1]->name[3] = 'o';
    array[size - 1]->name[4] = 'l';
    array[size - 1]->name[5] = 'a';
    array[size - 1]->name[6] = 'i';
    array[size - 1]->salary = 85000.5;
    array[size - 1]->counter = size - 1;
} // end fileToArray(std::fstream&, person**, int&)

// Writes the information from the array to the file
void arrayToFile(std::fstream& file, person* array[], int size) {
    int index = 0;
    double outDouble;
    int outInt;

    file.clear();
    file.seekp(0);

    while (index < size) {
        // these values are only used to make the file.write()'s easier to read
        outDouble = array[index]->salary;
        outInt = array[index]->counter;

        file.write(array[index]->name, 20);
        file.write(reinterpret_cast<char *> (&outDouble), sizeof(outDouble));
        file.write(reinterpret_cast<char *> (&outInt), sizeof(outInt));

        index++;
    } // end while loop
} // end arrayToFile(std::fstream&, person**, int)

void displayArray(person* array[], int size) {
    int i = 0;
    std::cout << std::left << std::fixed << std::setprecision(2);

    std::cout << std::setw(20) << "Name:" << std::setw(13) <<"Salary: " << std::setw(10) << "Counter:" << std::endl;
    while(i < size) {
        for(int j = 0; j < 20; j++)
            std::cout << array[i]->name[j];
        std::cout << std::setw(13) << array[i]->salary;
        std::cout << std::setw(10) << array[i]->counter;
        std::cout << std::endl;

        i++;
    } // end while loop
} // end displayArray(person**, int)

int main() {
    person* array[100];
    int size = 0;
    std::string filename;

    std::cout << "Please enter the name of the binary file: ";
    std::cin >> filename;

    // opens file for input and output, terminates program if file could not be opened
    std::fstream file(filename.c_str(), std::ios::binary | std::ios::in | std::ios::out);
    if(!(file.is_open())) {
        std::cout << "The file could not be opened or does not exist" << std::endl;
        return 1;
    } // end if

    // reads from the file, updates the file, and then displays the data from the array
    fileToArray(file, array, size);
    arrayToFile(file, array, size);
    displayArray(array, size);

    file.close();
    return 0;
} // end main()