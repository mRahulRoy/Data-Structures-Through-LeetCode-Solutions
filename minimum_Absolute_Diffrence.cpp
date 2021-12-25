#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
// THE BRUTE FORCE APPROACH

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &vect)
    {
        sort(vect.begin(), vect.end());
        int small = INT_MAX;
        int i = 0;
        int j = 1;
        vector<vector<int>> ans;
        vector<int> t;
        while (j <= vect.size())
        {
            int temp = vect[j] - vect[i];
            if (temp < 0)
            {
                temp = temp * (-1);
            }
            if (temp <= small)
            {
                small = temp;
                t.push_back(vect[i]);
                t.push_back(vect[j]);
                ans.push_back(t);
                t.clear();
            }
            i++;
            j++;
        }
        return ans;
    }
};
int main()
{
    vector<int> vect = {4,2,1,3};
    Solution obj;
    vector<vector<int>> ans = obj.minimumAbsDifference(vect);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}
