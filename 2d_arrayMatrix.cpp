#include <iostream>
#include <vector>

using namespace std;

// Function to find the sum of all neighbors of a given cell in the matrix
double findNeighborsSum(const vector<vector<int>> &input, int i, int j)
{
    int row = input.size();
    int col = input[0].size();
    double sum = 0;

    for (int x = -1; x <= 1; x++)
    {
        for (int y = -1; y <= 1; y++)
        {
            int newI = i + x;
            int newJ = j + y;

            // Check if the new indices are within the matrix bounds
            if (newI >= 0 && newI < row && newJ >= 0 && newJ < col && !(x == 0 && y == 0))
            {
                sum += input[newI][newJ];
            }
        }
    }

    return sum;
}

int main()
{
    // Input matrix
    vector<vector<int>> input = {
        {1, 2, 1, 2, 2, 1},
        {2, 1, 1, 1, 3, 1},
        {1, 1, 1, 1, 1, 1},
        {2, 1, 1, 2, 1, 1},
        {1, 1, 2, 1, 1, 1},
        {2, 1, 2, 1, 1, 2}};

    // Get the row and column indices from the user
    int row, col;
    cout << "Enter the row index: ";
    cin >> row;
    cout << "Enter the column index: ";
    cin >> col;

        // Check if the indices are within the matrix bounds
    if (row >= 0 && row < input.size() && col >= 0 && col < input[0].size())
    {
        // Compute the sum of neighbors for the specified index
        double sum = findNeighborsSum(input, row, col);

        // Get the value of the center cell
        int centerValue = input[row][col];

        cout << "The sum of neighbors for the specified index is: " << sum / centerValue << endl;
    }
    else
    {
        cout << "The specified index is out of bounds." << endl;
    }

    return 0;
}