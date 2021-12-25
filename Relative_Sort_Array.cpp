#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> ans;
        map<int, int> mp;
        for (auto a : arr1)
        {
            mp[a] = mp[a] + 1;
        }

        for (auto temp : arr2)
        {
            if (mp.find(temp) != mp.end())
            {
                auto x = mp.find(temp);
                int count = x->second;
                vector<int> vec(count, temp);
                ans.insert(ans.end(), vec.begin(), vec.end());
                mp.erase(temp);
            }
        }

        for (auto x : mp)
        {
            int val = x.first;
            int count = x.second;
            vector<int> v(count, val);
            ans.insert(ans.end(), v.begin(), v.end());
        }
        return ans;
    }
};
int main()
{
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};
    Solution obj;
    arr1 = obj.relativeSortArray(arr1, arr2);
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << " ";
    }

    return 0;
}