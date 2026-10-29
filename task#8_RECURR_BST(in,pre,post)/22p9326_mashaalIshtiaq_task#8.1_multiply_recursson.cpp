#include <iostream>
using namespace std;

int Multiply(int a, int b)
{

    if (b == 0)
        return 0; // as a number multiplied with zero is indeed zero ->will return 0 to the function which called it

    else
    {

        return a + Multiply(a, b - 1);
    }
}

int main()
{
    int a, b;
    cout << "\nEnter two positive integers: ";
    cin >> a >> b;

    if (a <= 0 || b <= 0)
    {
        cout << "Invalid input" << endl;
        return -1; // to indicate error as a and b should be positive integers
    }
    int result = Multiply(a, b);

    cout << "Product of the two positive integers is: " << result << endl;

    return 0;
}