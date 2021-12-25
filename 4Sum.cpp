#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
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
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 4; i++)
        {
            int first = nums[i];
            int start = i + 1;
            int end = nums.size() - 1;
            while (start < end)
            {
                vector<int> temp;
                temp = threeSum(start, nums, target - first);
                int sum = accumulate(temp.begin(), temp.end(), 0);
                if (sum + first == target)
                {
                    temp.insert(temp.begin(), 50);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
    vector<int> threeSum(int from, vector<int> &nums, int target)
    {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        /* logic is simple we are just finding the remaining two pairs for the one fixed element each time. we are simply finding other two pairs by fixing the arr[i] each time;
        */
        for (int i = from; i < nums.size(); i++)
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
                    ans.push_back(first);
                    ans.push_back(nums[start]);
                    ans.push_back(nums[end]);
                    start++;
                    end--;

                    // This while takes acre of if the previos and element present at start are equal or not if both of them are equal then just increment start by 1. becouse we dont want duplicate numbers in the result.
                    return ans;
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
    vector<int> arr = {2,2,2,2,2};
    Solution obj;
    int target = 8;
    vector<vector<int>> ans = obj.fourSum(arr, target);
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