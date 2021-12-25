#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

/* 
                                                     LEETCODE 283 
                                            ****---- Move Zeroes ----****
                                            
            Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
            Note that you must do this in-place without making a copy of the array.
        
            Example 1:
            Input: nums = [0,1,0,3,12]
            Output: [1,3,12,0,0]
        
            Example 2:
            Input: nums = [0]
            Output: [0]

*/
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int lastNonZeroFoundAt = 0;
        // If the current element is not 0, then we need to
        // append it just in front of last non 0 element we found.
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[lastNonZeroFoundAt++] = nums[i];
            }
        }
        // After we have finished processing new elements,
        // all the non-zero elements are already at beginning of array.
        // We just need to fill remaining array with 0's.
        for (int i = lastNonZeroFoundAt; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};
int main()
{
    vector<int> nums = {0, 1, 1, 0};
    Solution obj;
    obj.moveZeroes(nums);
    for (auto ans : nums)
    {
        cout << ans << " ";
    }
    return 0;
}