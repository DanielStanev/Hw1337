#include <iostream>
#include <string>
#include <cctype>  // <--- For "std::tolower() and std::toupper()" + others.

using namespace std;  // <--- Best not to use.

int main()
{
    std::string sandwiches[]
            {
                    "",  // <--- Place holder not used.
                    "Ham    - $4",
                    "Veggie - $3",
                    "Rat    - $2"
};

    string Bacon = " Bacon - $.50";
    string Hair = " Hair - $.10";
    unsigned int choice;  // <--- Added.

    cout << "What type of sandwich do you want?\n";



    for (unsigned idx = 1; idx < sizeof(sandwiches) / sizeof(sandwiches[2]); idx++)
    {
        std::cout << ' ' << idx << ". " << sandwiches[idx] << '\n';
    }

    std::cout << "  Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "\n Would you like bacon with that? (Y/N): ";

        char response;
        cin >> response;


        if (static_cast<char>(std::toupper(static_cast<unsigned char>(response))) == 'Y')  // <--- What about 'y'??
        {
            cout << "\n Your sandwich cost is Ham with bacon    $4.50";
        }
        else
        {
            cout << "\n Your sandwich cost is Ham    $4.00";
        }
    }

    return 0;  // <--- Not required, but makes a good break point for testing.
}

