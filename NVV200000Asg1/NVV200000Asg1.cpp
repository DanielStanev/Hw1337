#include <iostream>

double seriesSum(int n) {
    double sum = 0;
    int i = 1;
    while (n >= 1) {
        sum += ((double(i))/(double(n)));
        n--;
        i++;
    }
    return sum;
}

void findNumber(int& n){
    while (true) {
        std::cout << "Please enter an integer greater 1 to calculate the sum of the series" << std::endl;
        std::cout << "Or enter 0 to end the program" << std::endl;
        if (!(std::cin >> n)) {
            std::cout << std::endl;
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(1000, '\n'); //discard input
            std::cout << "Invalid input" << std::endl;
        }
        else if (n < 0) {
            std::cout << std::endl;
            std::cout << "Invalid input" << std::endl;
        }
        else {
            break;
        }
    }
}

int main() {
    int n = 0;
    double sum = 0;

    findNumber(n);
    std::cout << std::endl;


    while (n != 0) {
        sum = seriesSum(n);
        std::cout << "When n = " << n << ", the sum of the series is: " << sum << std::endl << std::endl;
        findNumber(n);
    }

    return 0;
}