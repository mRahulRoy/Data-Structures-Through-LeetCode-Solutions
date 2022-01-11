#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
class Solution
{
public:
    void swap(int i, int j, vector<int> &nums)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    vector<int> cyclicSort(vector<int> &nums)
    {
        int size = nums.size();
        int i = 0;
        vector<int> ans;
        while (i < size)
        {
            int correct_Index = nums[i] - 1;
            if (nums[i] != nums[correct_Index])
            {
                swap(i, nums[i] - 1, nums);
            }
            else
            {
                i++;
            }
        }
        for (int i = 0; i < size; i++)
        {
            if (nums[i] != i + 1)
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {1,1,2,3,4,6,5,5};
    Solution obj;
    vector<int> ans = obj.cyclicSort(nums);
    for (int val : ans)
    {
        cout << val << " ";
    }

    return 0;
}