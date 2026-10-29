#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        for (int i = 0; i < nums.size(); i++)
        {

            for (int j = i + 1; j < nums.size(); j++)
            {

                if (target == (nums[i] + nums[j]))
                {

                    cout << "Output : [" << i << "," << j << " ]" << endl;
                    return {i, j};
                }
            }
        }

        cout << "Not found" << endl;
        return {};
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);
    return 0;
}