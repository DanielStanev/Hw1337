#include <iostream>
#include <string>
#include <fstream>

typedef struct word{
    std::string 
}word;

int main() {
    std::string filename;
    std::ifstream data;

    while(true) {
        std::cout << "Please enter the name of the file containing the data or enter * to quit: ";
        std::cin >> filename;

        if (filename == "*")
            break;


        data.open(filename.c_str());

        if(!(data.is_open())) {
            std::cout << "The file could not be opened, please try again" << std::endl;
            continue;
        }

        data.close();
    }


    return 0;
}