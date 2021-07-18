#include <string>

#ifndef HOTDOGS_HOTDOGSTANDSCLASS_H
#define HOTDOGS_HOTDOGSTANDSCLASS_H


class HotDogStandsClass {
public:
    // constructor
    HotDogStandsClass(std::string idString, std::string location, float cost, int inventory, int sold, int totalSold);

    // getter methods
    std::string getId();
    std::string getLocation();
    float getCost();
    int getInventory();
    int getSold();
    int getTotalSold();

    // setter methods
    void setId(std::string name);
    void setLocation(std::string location);
    void setCost(float cost);
    void setInventory(int inventory);
    void setSold(int sold);
    void setTotalSold(int totalSold);

    // buy and stock methods
    void hotDogsBuy(int n);
    void stockInventory(int n);
private:
    std::string idString;
    std::string location;
    float cost;
    int inventory;
    int sold;
    static int totalSold;
};


#endif //HOTDOGS_HOTDOGSTANDSCLASS_H
