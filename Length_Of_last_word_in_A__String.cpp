
#include <iostream>
#include<string>
using namespace std;
/*
                                LEETCODE 58 :  Length of Last Word
        question : Given a string s consisting of some word separated by some number of spaces, return the length of the last word in the string.
        A word is a maximal substring consisting of non-space characters only.

        Example 1:
        Input: s = "Hello World"
        Output: 5
        Explanation: The last word is "World" with length 5.

        Example 2:
        Input: s = "   fly me   to   the moon  "
        Output: 4
        Explanation: The last word is "moon" with length 4.

        Example 3:
        Input: s = "luffy is still joyboy"
        Output: 6
        Explanation: The last word is "joyboy" with length 6.
        
        Constraints:
        1 <= s.length <= 104
        s consists of only English letters and spaces ' '.
        There will be at least one word in s.
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length(); // length of the entire string
        int lastLetterIdx = len-1; //to store index of last letter of the last word
        int startLetterIdx = len-1; // to store index of the start letter of last word - 1
        for(lastLetterIdx = len-1;lastLetterIdx >= 0; lastLetterIdx--){
            if (s[lastLetterIdx]!= ' ') break;
        }
        for (startLetterIdx=lastLetterIdx; startLetterIdx >= 0; startLetterIdx--){
            if (s[startLetterIdx]==' ') break;
        }
        return lastLetterIdx-startLetterIdx;
        
    }
};
int main()
{
   string str = " i am rahul";
   Solution obj;
   int ans = obj.lengthOfLastWord(str);
   cout<<ans;

    return 0;
}
