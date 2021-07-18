#include <iostream>
#include <string>

// Discards non-alpha numeric characters and checks if a string is a palindrome recursively
bool isPalindrome(std::string str) {
    // Makes the code more readable
    int i = str.length() - 1;

    // If the string is length 0 or 1 it is a palindrome
    if (str.length() == 0 || str.length() == 1)
        return true;

    // If there is a non alpha-numeric character it gets chopped off and the function is called again
    if (str[0] < 48 || (str[0] > 57 && str[0] < 65) || (str[0] > 90 && str[0] < 97) || str[0] > 122)
        return isPalindrome(str.substr(1));
    if (str[i] < 48 || (str[i] > 57 && str[i] < 65) || (str[i] > 90 && str[i] < 97) || str[i] > 122)
        return isPalindrome(str.substr(0, i));

    // Changes lowercase letters to capital letters to make the comparison easier
    if (str[0] >= 97 && str[0] <= 122)
        str[0] -= 32;
    if (str[i] >= 97 && str[i] <= 122)
        str[i] -= 32;

    // Returns false if the first and the last characters are not the same
    if (str[0] != str[i])
        return false;
    else
        return isPalindrome(str.substr(1, i - 1));
} // end function isPalindrome

int main() {
    std::string check;

    while (true) {
        std::cout << "Enter a string to check if it is a palindrome, or enter * to quit: ";
        std::getline(std::cin, check);

        if (check == "*")
            break;
        if(isPalindrome(check))
            std::cout << "The string \"" << check << "\" is a palindrome." << std::endl << std::endl;
        else
            std::cout << "The string \"" << check << "\" is not a palindrome." << std::endl << std::endl;
    }

    return 0;
} // end main