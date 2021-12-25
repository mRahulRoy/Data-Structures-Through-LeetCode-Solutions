#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
// assuming only one  answer exist in this question
    vector<int> twoSum(vector<int> &arr, int target)
    {
        vector<int> ans;
        sort(arr.begin(), arr.end());
        int left = 0;
        int right = arr.size() - 1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (i != 0 && arr[i] == arr[i - 1])
            {
                continue;
            }

            int sum = arr[left] + arr[right];
            if (sum == target)
            {
                ans.push_back(arr[left]);
                ans.push_back(arr[right]);
                break;
            }
            else if (sum > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> arr = {-1, -1, 0, 1, 2, 4};
    int target = 0;
    Solution obj;
    vector<int> ans = obj.twoSum(arr, target);
    for (auto val : ans)
        cout << val << "  ";

    return 0;
}