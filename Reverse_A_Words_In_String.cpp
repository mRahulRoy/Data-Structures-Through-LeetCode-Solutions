#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <utility>
using namespace std;
// class Solution
// {
// public:
//     string reverseWords(string s)
//     {
//         vector<string> str;
//         string temp = "";
//         stringstream ss(s);
//         while (ss >> s)
//         {
//             temp += s;
//             reverse(temp.begin(), temp.end());
//             str.push_back(temp);
//             temp = "";
//         }
//         for (int i = 0; i < str.size(); i++)
//         {
//             temp += str[i] + " ";
//         };
//         temp.pop_back();
//         return temp;
//     }
// };
// This one is the optimal or optimised 
class Solution
{
public:
    string reverseWords(string str)
    {
        int i = 0;
        int j = 0;
        int size = str.size();
        while (i < size) //traversing the all characters.
        {
            while (j < size && str[j] != ' ')//iterating until space is not encoountered , becouse word is separated by a space always.
            {
                j++;
            }
            // now j is pointing at the character space.
            reverse(str.begin() + i, str.begin() + j); //now reverse the string from i to j.
            i = j + 1;
            j = i;
        }
        return str;
    }
};
int main()
{
    string str = "Let's take LeetCode contest";
    Solution obj;
    string ans = obj.reverseWords(str);
    cout << ans << endl;
    return 0;
}

/*
    BETTER APPROACH

class Solution
{
public:
  string reverseWords(string s)
 {
     int i = 0;
     int j =0;
     while(i<str.size()){
         while(j<str.size() && str[j]!=' '){
             j++;
         }
         reverse(str.begin()+i;str.end()+j);
         i = j+1;
         j = i;
     }
 }
};
*/