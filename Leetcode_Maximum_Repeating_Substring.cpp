#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
                            668. Maximum Repeating Substring
    For a string sequence, a string word is k-repeating if word concatenated k times is a substring of sequence. The word's maximum k-repeating value is the highest value k where word is k-repeating in sequence. If word is not a substring of sequence, word's maximum k-repeating value is 0.
    Given strings sequence and word, return the maximum k-repeating value of word in sequence.
     -------
     In simple words if a given string "word" is found in the given string "sequnce" then concatenate the given string "word" to itself and then again try to find if that concatenated substring is present in the string.
     Easiest example : 
     Input: sequence = "ababc", word = "ab"
     Output: 2
     Explanation: As we can see "word 'ab' "  is found in string "sequence" so we simply increment the counter by one. after incrementing we will concatenate the word "ab" to itself now word has become "abab" now we will check if "abab" is present in the string or not and whenever we will find that substring we will simply increment the counter and this procedure will keep going until we did not find the concatenated substring.
     ------
    Example 1:
    Input: sequence = "ababc", word = "ba"
    Output: 1
    Explanation: "ba" is a substring in "ababc". "baba" is not a substring in "ababc".

    Example 2:
    Input: sequence = "ababc", word = "ac"
    Output: 0
    Explanation: "ac" is not a substring in "ababc". 
    
    Constraints:
    1 <= sequence.length <= 100
    1 <= word.length <= 100
    sequence and word contains only lowercase English letters.
*/
class Solution
{
public:
    int maxRepeating(string sequence, string word)
    {
        int i = 0, count = 0;
        string temp = word;
        while (sequence.find(word) != string::npos)
        {
            count++;
            word += temp; //this adds the word each time in word
            
        }
        return count;
    }
};

int main()
{
    string str = "aaabaaaabaaabaaaabaaaabaaaabaaaaba";
    string word = "aaaba";
    Solution obj;
    int ans = obj.maxRepeating(str, word);
    cout << ans << endl;
    return 0;
}
