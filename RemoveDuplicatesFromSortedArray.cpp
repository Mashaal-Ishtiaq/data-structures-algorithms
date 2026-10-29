#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int k = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != nums[k - 1])
            {
                nums[k++] = nums[i];
            }
        }

        // Output the modified nums vector
        cout << "Output: " << k << ", nums = [";
        for (int i = 0; i < k; ++i)
        {
            cout << nums[i];
            if (i < k - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;

        return k;
    }
};

int main()
{
    // Example usage
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution solution;
    int newLength = solution.removeDuplicates(nums);
    cout << "New Length: " << newLength << endl;
    return 0;
}
