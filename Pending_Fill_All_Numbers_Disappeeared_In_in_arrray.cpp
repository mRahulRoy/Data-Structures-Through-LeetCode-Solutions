#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> ans;
        int temp;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
           nums[nums[i]-1] = nums[i]*-1; 
           if(nums[i] > 0){
        
           }
        }

        return ans;
    }
};
int main()
{
    vector<int> nums = {1,2,3,45,6,7};
    Solution obj;
    vector<int> ans = obj.findDisappearedNumbers(nums);
    for (auto x : ans)
    {
        cout << x << endl;
    }
    return 0;
}