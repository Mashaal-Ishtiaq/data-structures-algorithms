#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();    // row
        int n = matrix[0].size(); // col

        int i = 0;
        int j = n - 1;

        while (i < m && j >= 0)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            else if (matrix[i][j] < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return false;
    }
};

int main()
{
    Solution solution;

    // Example usage
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};
    int target = 3;

    bool found = solution.searchMatrix(matrix, target);
    if (found)
    {
        cout << "Target " << target << " found in the matrix." << endl;
    }
    else
    {
        cout << "Target " << target << " not found in the matrix." << endl;
    }

    return 0;
}
