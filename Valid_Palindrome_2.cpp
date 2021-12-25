#include <iostream>
#include<string>
using namespace std;

/*                      LEETCODE 680. Valid Palindrome II
    Given a string s, return true if the s can be palindrome after deleting at most one character from it.
    Example 1:
    Input: s = "aba"
    Output: true
    
    Example 2:
    Input: s = "abca"
    Output: true
    Explanation: You could delete the character 'c'.
    
    Example 3:
    Input: s = "abc"
    Output: false
     
    Constraints:
    1 <= s.length <= 105
    s consists of lowercase English letters.
*/
class Solution
{
private:
  bool check_Palindrom (int start, int end, string str)
  {
    while (start < end)
      {
	if (str[start] == str[end])
	  {
	    start++;
	    end--;
	  }
	else
	  {
	    return false;
	  }
      }
    return true;
  }
public:
  bool validPalindrome (string str)
  {
    int start = 0;
    int end = str.size () - 1;
    /*
    Logic is very pretty simple we are simply checking for palindrome using two pointer approach
    if both the character at the ith or jth position then simply increment ith pointer by one and
    decrement jth pointer by one. if found not equal then we are allowed to skip one character atmost
    either from ith position or from jth position.But how we can do that for that we will make a another
    function that will check if we are getting the required palindrome after skipping that character.
    if equal then increment i by one and decrement j by one. if not equal that return statement will
    call another function written in OR that while skip the character from the last. 
    */
    while (start < end) 
      {
        	if (str[start] == str[end])
	         {
	             start++;
	             end--;
	         }
        	else
	          {
        	  //here if first function call returns false then it will call next function of it.
        	   return check_Palindrom (start + 1, end, str) || check_Palindrom (start, end - 1, str);
        	  }
    }
    return true;
  }
};

int
main ()
{
  string str = "abc";
  Solution obj;
  bool ans = obj.validPalindrome (str);
  cout << ans;
  return 0;
}
