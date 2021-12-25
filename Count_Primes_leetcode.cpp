#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
class Solution
{
public:
    int countPrimes(int n)
    {
        int count = 0, ans = 0;
        for (int i = 2; i < n; i++)
        {
            count = 0;
            for (int j = 1; j < n; j++)
            {
                if (i % j == 0)
                {
                    count++;
                }
            }
            if (count == 2)
            {
                ans++;
            }
        }
        return ans;
    }
};
int main()
{
    int n = 455;
    Solution obj;
    int ans = obj.countPrimes(n);
    cout << ans;
    return 0;
}