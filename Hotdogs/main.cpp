#include <iostream>
#include <string>
#include <fstream>
#include <new>
#include <sstream>
#include "HotDogStandsClass.h"


int main() {
    std::string check, line, pricestr, inventorystr, soldstr, name, location;
    std::ifstream info;
    std::ifstream transactions;
    std::ifstream global;
    std::ofstream infoWrite;
    std::ofstream globalWrite;
    std::fstream didko;
    float price;
    int i = 0, numStands = 0;
    int inventory, sold, totalSold, amount;

    // opens all of the necessary files
    info.open("InfoHotDogStands.txt");
    transactions.open("InfoHotDogStandsTransactions.txt");
    global.open("InfoGlobalSold.txt");

    if(!info)
        std::cout << "file not open";


    // stores the global sales into an int and closes file1
    global >> totalSold;
    global.close();

    // counts the number of lines in file
    while(!info.eof()) {
        std::getline(info, line);
        numStands++;
    } // end while loop

    // declares an array of size = number of stands and resets to beginning of file
    HotDogStandsClass* array[numStands];
    info.clear();
    info.seekg(0, std::ios::beg);

    // generates an array of stand pointers
    while (i < numStands) {
        std::getline(info, name, ',');
        std::getline(info, location, ',');
        std::getline(info, pricestr, ',');
        std::getline(info, inventorystr, ',');
        std::getline(info, soldstr);

        std::istringstream(soldstr) >> sold;
        std::istringstream(pricestr) >> price;
        std::istringstream(inventorystr) >> inventory;

        std::cout << "Stand ID  :" << name << std::endl;
        std::cout << "Address   :" << location << std::endl;
        std::cout << "Price     :" << price << std::endl;
        std::cout << "Inventory :" << inventory << std::endl;
        std::cout << "Store Sold:" << sold << " at $" << price << " ea." << std::endl << std::endl;

        HotDogStandsClass* p1 = new HotDogStandsClass(name, location, price, inventory, sold, totalSold);
        array[i] = p1;
        i++;
    }// end while loop

    //  pauses program so user can read info
    std::cout << "Press enter once or twice to process transactions" << std::endl;
    std::cin.ignore();
    std::cin.get();


    // closes info file
    info.close();

    // processes all transactions
    while(!transactions.eof()) {
        i = 0;
        std::getline(transactions, line, ',');
        while(i < numStands) {
            if(line == array[i]->getId())
                break;
            i++;
        } // end while loop

        std::getline(transactions, line, ',');
        if(line == "buy") {
            std::getline(transactions, line);
            std::istringstream(line) >> amount;
            array[i]->hotDogsBuy(amount);
        } // end if
        else if(line == "stock inventory") {
            std::getline(transactions, line);
            std::istringstream(line) >> amount;
            array[i]->stockInventory(amount);
        } // end else if
    } // end while loop

    transactions.close();

    totalSold = array[0]->getTotalSold();

    // displays total sold
    std::cout << "The total amount of hotdogs sold is " << totalSold << std::endl;
    std::cout << "Press enter once or twice to process transactions" << std::endl;
    std::cin.ignore();
    std::cin.get();

    // opens write files and
    infoWrite.open("InfoHotDogStands.txt");
    globalWrite.open("InfoGlobalSold.txt");
    globalWrite << totalSold;

    // goes through array and writes data of each stand to file
    i = 0;
    while(i < numStands) {
        infoWrite << array[i]->getId() << ",";
        infoWrite << array[i]->getLocation() << ",";
        infoWrite << array[i]->getCost() << ",";
        infoWrite << array[i]->getInventory() << ",";
        infoWrite << array[i]->getSold() << std::endl;
        i++;
    } // end while loop

    // closes file
    infoWrite.close();


    return 0;
} // end main