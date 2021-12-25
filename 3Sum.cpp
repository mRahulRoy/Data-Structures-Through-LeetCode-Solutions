#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

/*
                                            LEETCOE 15 -- 3 SUM
        Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.Notice that the solution set must not contain duplicate triplets.

    Example 1:
    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]

    Example 2:
    Input: nums = []
    Output: []

    Example 3:
    Input: nums = [0]
    Output: []
    

*/
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        /* logic is simple we are just finding the remaining two pairs for the one fixed element each time. we are simply finding other two pairs by fixing the arr[i] each time;
        */
        for (int i = 0; i < nums.size(); i++)
        {
            int first = nums[i];
            int start = i + 1;
            int end = nums.size() - 1;
            if (i != 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            while (start < end)
            {
                if (nums[start] + nums[end] == -first)
                {
                    vector<int> temp;
                    temp.push_back(first);
                    temp.push_back(nums[start]);
                    temp.push_back(nums[end]);
                    ans.push_back(temp);
                    start++;
                    end--;

                    // This while takes acre of if the previos and element present at start are equal or not if both of them are equal then just increment start by 1. becouse we dont want duplicate numbers in the result.
                    while (start < end && nums[start] == nums[start - 1])
                    {
                        start++;
                    }
                }
                else if (nums[start] + nums[end] > -first)
                {
                    end--;
                }
                else
                {
                    start++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {9, -9, 0, 8, -6, 2, 4, -8, 2, -5, 0, 5};
    Solution obj;
    vector<vector<int>> ans = obj.threeSum(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}