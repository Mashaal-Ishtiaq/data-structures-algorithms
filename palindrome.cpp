#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(const char* str) {
    int length = strlen(str);
    char* arr = new char[length]; // Allocate memory for a dynamic character array (+1 for null terminator)
    
    // Copy characters from the string to the array
    for (int i = 0; i < length; ++i) {
        arr[i] = str[i];
    }
   

    int left = 0; // Pointer to the first character
    int right = left+length - 1; // Pointer to the last character

    while (left < right) {
        if (arr[left] != arr[right]) {
         
            return false;
        }
        left++; // Move left pointer to the right
        right--; // Move right pointer to the left
    }

    delete[] arr; // Free dynamically allocated memory
    return true;
}

int main() {
    char input[100];
    cout << "Enter string: ";
    cin >> input;

    if (isPalindrome(input)) {
        cout << "The string is a palindrome.\n";
    } else {
        cout << "The string is not a palindrome.\n";
    }

    return 0;
}
