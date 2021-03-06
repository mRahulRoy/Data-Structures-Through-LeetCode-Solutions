#include <iostream>
#include<string>
using namespace std;
/*
        LEETCODE 28 -   Implement strStr().

    Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

    Clarification:
    What should we return when needle is an empty string? This is a great question to ask during an interview.  
    For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

    Example 1:
    Input: haystack = "hello", needle = "ll"
    Output: 2

    Example 2:
    Input: haystack = "aaaaa", needle = "bba"
    Output: -1

    Example 3:
    Input: haystack = "", needle = ""
    Output: 0

    Constraints:
    0 <= haystack.length, needle.length <= 5 * 104
    haystack and needle consist of only lower-case English characters.
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int index;
        if(haystack.find(needle) != string::npos){ //checking if substring needle is present then simple note it occuring index and return it else return false
            index = haystack.find(needle);
        }
        else return -1;
        
        return index;
    }
};
int main()
{
    string str ="hello";
    string goal ="bba";
    Solution obj;
    int ans = obj.strStr(str,goal);
    cout<<ans;

    return 0;
}
