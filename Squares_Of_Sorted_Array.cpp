#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());

        return nums;
    }
};
int main()
{
    vector<int> nums = {-7, -3, 2, 3, 11};
    Solution obj;
    nums = obj.sortedSquares(nums);
    for (auto ans : nums)
        cout << ans << " ";
    return 0;
}