#include <iostream>
using namespace std;
int main()
{
    int size;
    cin >> size;
    int arr[size]; // the prob with this is that u cant create int size array at compile time it will only work during run time so its illogical and user-defined array shouldnt be created like this (stored in stacck)
}

#include <iostream>
using namespace std;
int main()
{
    int size;
    cin >> size;
    int *arr = new int[size]; // this is dynamic array and is the sol for the above static array prob (stored in heap)
    delete[] arr;
}