#include "HotDogStandsClass.h"
#include <string>
#include <iostream>

int HotDogStandsClass::totalSold = 0;

HotDogStandsClass::HotDogStandsClass(std::string idString, std::string location, float cost, int inventory, int sold, int totalSold) {
    this->idString = idString;
    this->location = location;
    this->cost = cost;
    this->inventory = inventory;
    this->sold = sold;
    this->totalSold = totalSold;
}

void HotDogStandsClass::hotDogsBuy(int n) {
    bool valid = true;

    std::cout << "HotDog Stand Current Status:" << std::endl << std::endl;
    std::cout << "Stand ID  :" << idString << std::endl;
    std::cout << "Address   :" << location << std::endl;
    std::cout << "Price     :" << cost << std::endl;
    std::cout << "Inventory :" << inventory << std::endl;
    std::cout << "Store Sold:" << sold << " at $" << cost << " ea." << std::endl << std::endl;

    std::cout << "Transaction: " << std::endl << std::endl;
    std::cout << "Transaction Stand id : " << idString << std::endl;
    std::cout << "Transaction id       : buy" << std::endl;
    std::cout << "Transaction Argument : " << n << std::endl << std::endl;

    if (inventory == 0)
        std::cout << "*There are not any more hotdogs left to be sold.*" << std::endl << std::endl;
    else if (n > inventory)
        std::cout << "*We only have " << inventory << " hotdogs left.*" << std::endl << std::endl;
    else {
        sold += n;
        totalSold += n;
        inventory -= n;
    }
    std::cout << "HotDog Stand Status after Transaction:" << std::endl << std::endl;
    std::cout << "Stand ID  :" << idString << std::endl;
    std::cout << "Address   :" << location << std::endl;
    std::cout << "Price     :" << cost << std::endl;
    std::cout << "Inventory :" << inventory << std::endl;
    std::cout << "Store Sold:" << sold << " at $" << cost << " ea." << std::endl << std::endl;

    std::cout << "Global Sold: " << totalSold << std::endl << std::endl;

    std::cout << "Press the enter key once or twice to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();

}

void HotDogStandsClass::stockInventory(int n) {
    std::cout << "HotDog Stand Current Status:" << std::endl << std::endl;
    std::cout << "Stand ID  :" << idString << std::endl;
    std::cout << "Address   :" << location << std::endl;
    std::cout << "Price     :" << cost << std::endl;
    std::cout << "Inventory :" << inventory << std::endl;
    std::cout << "Store Sold:" << sold << " at $" << cost << " ea." << std::endl << std::endl;

    std::cout << "Transaction: " << std::endl << std::endl;
    std::cout << "Transaction Stand id : " << idString << std::endl;
    std::cout << "Transaction id       : stock inventory" << std::endl;
    std::cout << "Transaction Argument : " << n << std::endl << std::endl;

    std::cout << "HotDog Stand Status after Transaction:" << std::endl << std::endl;

    inventory += n;

    std::cout << "HotDog Stand Current Status:" << std::endl << std::endl;
    std::cout << "Stand ID  :" << idString << std::endl;
    std::cout << "Address   :" << location << std::endl;
    std::cout << "Price     :" << cost << std::endl;
    std::cout << "Inventory :" << inventory << std::endl;
    std::cout << "Store Sold:" << sold << " at $" << cost << " ea." << std::endl << std::endl;

    std::cout << "Global Sold: " << totalSold << std::endl << std::endl;

    std::cout << "Press the enter key once or twice to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
}

// accessor methods
std::string HotDogStandsClass::getId()         { return idString;  }
std::string HotDogStandsClass::getLocation()   { return location;  }
float HotDogStandsClass::getCost()             { return cost;      }
int HotDogStandsClass::getInventory()          { return inventory; }
int HotDogStandsClass::getSold()               { return sold;      }
int HotDogStandsClass::getTotalSold()          { return totalSold; }

// setter methods
void HotDogStandsClass::setId(std::string idString)            { this->idString = idString;   }
void HotDogStandsClass::setLocation(std::string location)      { this->location = location;   }
void HotDogStandsClass::setCost(float cost)                    { this->cost = cost;           }
void HotDogStandsClass::setInventory(int inventory)            { this->inventory = inventory; }
void HotDogStandsClass::setSold(int sold)                      { this->sold = sold;           }
void HotDogStandsClass::setTotalSold(int totalSold)            { this->totalSold = totalSold; }

