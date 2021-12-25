#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
class Solution
{
public:
    string toLowerCase(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 65 && s[i] <= 90)
            {
                s[i] = s[i] + 32;
            }
        }
        return s;
    }
};
int main()
{
    string str = "RaHuL";
    Solution obj;
    str = obj.toLowerCase(str);
    cout << str;
    return 0;
}