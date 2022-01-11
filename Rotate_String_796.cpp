#include <iostream>
#include <string>
using namespace std;

/*
        LEETCODE 796 ROTATE STRING
    Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
    A shift on s consists of moving the leftmost character of s to the rightmost position.
    For example, if s = "abcde", then it will be "bcdea" after one shift.
 
    Example 1:
    Input: s = "abcde", goal = "cdeab"
    Output: true

    Example 2:
    Input: s = "abcde", goal = "abced"
    Output: false
 
    Constraints:
    1 <= s.length, goal.length <= 100
    s and goal consist of lowercase English letters.


    logic for this solution is very easy.
    what we are doing is we are taking a temporary string "temp" and assigning it with a given string s and if our given string is not equal to the given goal then we will iterate the given string till we do not shift the extreme left charater to the extreme right to get the desired answer if we shifted all the characters by one and we did not find any match that means we did not find the answer and will simply return False.
*/
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        int i = 0;
        string temp = s;
        if (s != goal)
        {
            while (i < s.size())
            {
                temp.push_back(s[i]); //shifting the left most character to the rightmost 
                temp.erase(0, 1); //deleting the leftmost character to make it a another string.
                if (temp == goal) //checking if the newly modified string is equal or not.
                {
                    return true;
                }
                i++;
            }
        }
        return false;
    }
};
int main()
{
    string str = "abcde";
    string goal = "abced";
    Solution obj;
    bool ans = obj.rotateString(str, goal);
    cout << ans;

    return 0;
}
