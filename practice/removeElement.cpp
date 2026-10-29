#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int k = 0; // This will keep track of the position for the next non-val element.

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != val)
            {
                nums[k++] = nums[i];
            }
        }

        return k;
    }
};
