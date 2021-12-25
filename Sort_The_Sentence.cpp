#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
/*
Input: s = "is2 sentence4 This1 a3"
Output: "This is a sentence"
Explanation: Sort the words in s to their original positions "This1 is2 a3 sentence4", then remove the numbers.
*/
/*
	logic:
	Logic is pretty simple we will use a indexed vector of fixed size and will iterate the given string and when we will 	encounter a number or index attached at the last of the word like this "this4" we will move this word in the vector 		at index4 or at the respected index attached with the word. But how we will know what size of the word is to se send 		in the vector created. we will be using ASCII values we know that ASCII of integers start from 48 to 57 (0-9). so we 		will make a check for the number present in the string if the present character in the loop is not a number then 	store the present character in another string till we didnot meet the number. And when we get that the number strore 	that in a respected index.

	subtracting 
	48 = 0
	49 = 1
	50 = 2
	51 = 3
	52 = 4
	53 = 5
	54 = 6
	55 = 7 
	56 = 8
	57 = 9
	
	So if 4 is attached at the last of the word then word should be stored at index 4 of the temp vector. by following 	this. (0-9)-48; will give the index for the value. 
*/
class Solution
{
public:
    string sortSentence(string s)
    {
        string str = "";
        string ans = "";
        vector<string> temp(10);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 48 && s[i] <= 57) //This condition will check if str[i] is number or not.
            {
                temp[s[i] - 48] = str + " ";
                str = ""; //initialised with a empty string to store another new string.
                i++;      //incremented by 1 because next element is a extra space.
            }
            else
            {
                str += s[i];
            }
        }

        for (string st : temp)
        {
            ans += st; //here we are concatinating the strings present in the vector
        }
        ans.pop_back(); //THIS STATEMENT WILL REMOVE THE TRAILING SPACE CAUSED BY LINE 37
        return ans;
    }
};
int main()
{
    string str = "Myself2 Me1 I4 and3";
    Solution obj;
    string ans = obj.sortSentence(str);
    cout << ans;
    return 0;
}