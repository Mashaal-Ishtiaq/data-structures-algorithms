#include <iostream>
#include <string>
using namespace std;

class Brackets
{
public:
    bool isValid(const string &s)
    {
        int countRound = 0, countSquare = 0, countCurly = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            char ch = s[i];
            if (ch == '(')
            {
                countRound++;
            }
            else if (ch == ')')
            {
                countRound--;
            }
            else if (ch == '[')
            {
                countSquare++;
            }
            else if (ch == ']')
            {
                countSquare--;
            }
            else if (ch == '{')
            {
                countCurly++;
            }
            else if (ch == '}')
            {
                countCurly--;
            }

            if (countRound < 0 || countSquare < 0 || countCurly < 0)
            {
                return false;
            }
        }

        return countRound == 0 && countSquare == 0 && countCurly == 0;
    }
};

int main()
{
    Brackets B1;
    string input;
    int choice;

    while (true)
    {
        cout << "1. Enter a string containing round, curly, and square brackets" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter the string: ";
            cin.ignore(); // Ignore any remaining newline characters in the input buffer
            getline(cin, input);

            if (B1.isValid(input))
            {
                cout << "The string is valid." << endl;
            }
            else
            {
                cout << "The string is not valid." << endl;
            }
        }
        else if (choice == 2)
        {
            return 0;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
