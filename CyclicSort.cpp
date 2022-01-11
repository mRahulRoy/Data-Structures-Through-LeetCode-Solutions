#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
/*
                Cyclic sort Sorting Algorithm
    this is an algorithm used to sort the numbers .This can be implimented only if the
    numbers are in Range from [1-N] pr [0-N].
    Time complexity is : O(N);
*/
class Solution
{
public:
    void swap(int i, int j, vector<int> &nums)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void cyclicSort(vector<int> &nums)
    {
        int size = nums.size();
        int i = 0;
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
    }
};
int main()
{
    vector<int> nums = {5, 4, 3, 2, 1, 2};
    Solution obj;
    obj.cyclicSort(nums);
    for (int ans : nums)
    {
        cout << ans << " ";
    }

    return 0;
}