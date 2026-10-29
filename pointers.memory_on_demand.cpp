#include <iostream>
#include <string>
using namespace std;

int main() {
    char ch = 'y';
    string* names = nullptr; // Pointer to dynamically allocated memory
    int count = 0; // To keep track of the number of names entered

    do {
        // Prompt the user to enter a name
        cout << "Enter a name: ";
        string n;
        cin >> n;

        // Dynamically allocate memory for one more name
        string* temp = new string[count + 1];
        
        // Copy existing names to the temporary array
        for (int i = 0; i < count; ++i) {
            temp[i] = names[i];
            temp[count] = name;
        }
        
        // Add the new name to the temporary array
        //temp[count] = name;

        // Deallocate memory for the old array
        delete[] names;

        // Update the pointer to point to the new array
        names = temp;

        // Increment the count of names
        ++count;

        // Ask if the user wants to enter another name
        cout << "Enter another? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    // Print all the entered names
    cout << "Names entered:\n";
    for (int i = 0; i < count; ++i) {
        cout << names[i] << endl;
    }

    // Deallocate memory for the array of names
    delete[] names;

    return 0;
}
