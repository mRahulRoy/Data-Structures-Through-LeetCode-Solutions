#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*                              LEETCODE SORT BY PARITY II 
This question states that you are given an array nums and you have to replace the elements in such a way
    that even indexes must conatin only even values and odd indexes must contain odd values.
    NOTE-- do this question in inplace.
*/
class Solution
{
public:
    void swap(vector<int> &nums, int i, int j)
    {
        int temp;
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void sortArrayByParity2(vector<int> &nums)
    {
        int i = 0, j = 1;
        while (i < nums.size() && j < nums.size())
        {
            while (i < nums.size() && nums[i] % 2 == 0)
            {
                i = i + 2;
            }
            while (j < nums.size() && nums[j] % 2 == 1)
            {
                j = j + 2;
            }
            if (i < nums.size())
            {
                swap(nums, i, j);
            }
            i = i + 2;
            j = j + 2;
        }

        for (auto ans : nums)
        {
            cout << ans << " ";
        }
    }
};
int main()
{
    vector<int> nums = {4, 2, 5, 7};
    Solution obj;
    obj.sortArrayByParity2(nums);

    return 0;
}