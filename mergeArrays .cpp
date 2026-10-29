// void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[], int &mergedSize)
// {
//     mergedSize = 0;

//     if (arr1[0] == 0)
//     {

//         for (int i = 0; i < size1; ++i)
//         {
//             merged[mergedSize++] = arr1[i];
//         }
//     }
//     else
//     {

//         for (int i = 0; i < size1; ++i)
//         {
//             if (arr1[i] != 0)
//             {
//                 merged[mergedSize++] = arr1[i];
//             }
//         }
//     }

//     int newSize = mergedSize + 1;

//     for (int i = 0; i < size2; ++i)
//     {
//         if (arr2[i] != 0)
//         {
//             merged[newSize++] = arr2[i];
//         }
//     }
// }
class Solution
{
public:
    void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[], int &mergedSize)
    {
        mergedSize = 0;

        // Add non-zero elements of arr1 to merged
        for (int i = 0; i < size1; ++i)
        {
            if (arr1[i] != 0)
            {
                merged[mergedSize++] = arr1[i];
            }
        }

        // Add non-zero elements of arr2 to merged
        for (int i = 0; i < size2; ++i)
        {
            if (arr2[i] != 0)
            {
                merged[mergedSize++] = arr2[i];
            }
        }
    }
};
int main()
{
    Solution sol;
    int arr1[] = {1, 0, 3, 0, 5};
    int arr2[] = {0, 2, 0, 4, 0};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int merged[size1 + size2]; // Maximum possible size
    int mergedSize;

    sol.mergeArrays(arr1, size1, arr2, size2, merged, mergedSize);

    // Print merged array
    for (int i = 0; i < mergedSize; ++i)
    {
        cout << merged[i] << " ";
    }
    return 0;
}
