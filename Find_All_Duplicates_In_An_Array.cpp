#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
                                **--LEETCODE 442 Find All Duplicates in an Array--**

    Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
    You must write an algorithm that runs in O(n) time and uses only constant extra space.

    Example 1:
    Input: nums = [4,3,2,7,8,2,3,1]
    Output: [2,3]

    Example 2:
    Input: nums = [1,1,2]
    Output: [1]

    Example 3:
    Input: nums = [1]
    Output: []

    Constraints:
    n == nums.length
    1 <= n <= 105
    1 <= nums[i] <= n
    Each element in nums appears once or twice.
*/

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                temp.push_back(nums[i]);
            }
        }
        return temp;
    }
};
int main()
{
    Solution obj;
    vector<int> arr = {4};
    vector<int> ans;
    ans = obj.findDuplicates(arr);
    for (auto val : ans)
    {
        cout << val << "  ";
    }

    return 0;
}

/*
    n^2 Approach
    class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> temp;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[i] == nums[j] && i != j)
                {
                   auto check_Presence = find(temp.begin(),temp.end(),nums[i]);
                   if(check_Presence!=temp.end()){
                       break;
                   }
                   else{
                        temp.push_back(nums[i]);
                   }
                     
                }
            }
           

        }
        return temp;
    }
};
*/