#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
                LEETCODE -- 976  Largest Perimeter Triangle
         Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.

Example 1:
Input: nums = [2,1,2]
Output: 5

Example 2:
Input: nums = [1,2,1]
Output: 0

Example 3:
Input: nums = [3,2,3,4]
Output: 10

Example 4:
Input: nums = [3,6,2,3]
Output: 8

Constraints:
3 <= nums.length <= 104
1 <= nums[i] <= 10

*/
class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        int a = nums.size() - 1; //this is pointing to the last index.
        int b = nums.size() - 2; // this is pointing to the second last index.
        int c = nums.size() - 3; // this is pointing to the third last index.
        sort(nums.begin(), nums.end());
        int perimeter = 0;
        int count = nums.size() - 1;
        // for (int i = nums.size() - 1; i >= 0; i--)
        while (c >= 0)
        {
            if (nums[b] + nums[c] > nums[a])
            {
                perimeter = nums[a] + nums[b] + nums[c];
                break;
            }
            else if (nums.size() == 3 && nums[b] + nums[c] <= nums[a])
            {
                return 0;
            }
            else
            {
                a--;
                b--;
                c--;
            }
        }
        return perimeter;
    }
};
int main()
{
    vector<int> vec = {3, 8, 2};
    Solution obj;
    int ans = obj.largestPerimeter(vec);
    cout << ans;
    return 0;
}