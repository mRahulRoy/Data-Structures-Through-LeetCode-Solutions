#include<iostream>
#include<string>
using namespace std;
/*
    You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
    Return the merged string.

    Example 1:
    Input: word1 = "abc", word2 = "pqr"
    Output: "apbqcr"
    Explanation: The merged string will be merged as so:
    word1:  a   b   c
    word2:    p   q   r
    merged: a p b q c r
    
    Example 2:
    Input: word1 = "ab", word2 = "pqrs"
    Output: "apbqrs"
    Explanation: Notice that as word2 is longer, "rs" is appended to the end.
    word1:  a   b 
    word2:    p   q   r   s
    merged: a p b q   r   s
    
    Example 3:
    Input: word1 = "abcd", word2 = "pq"
    Output: "apbqcd"
    Explanation: Notice that as word1 is longer, "cd" is appended to the end.
    word1:  a   b   c   d
    word2:    p   q 
    merged: a p b q c   d
     
    Constraints:
    1 <= word1.length, word2.length <= 100
    word1 and word2 consist of lowercase English letters.
    
    -----   IMPORTANT STRING APPEND FUNCTIONS
    Note - this function does not return any value.
        Str1.append(str2);  
        Str1.append(str2,pos,len);  
        Str1.append(str2,n);
*/
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // "abc", word2 = "pqr"
        //"cdf", "q"
        int word1_size = word1.size();// noting the size of String word1
        int word2_size =word2.size();// noting the size of String word2
        int small ;
        if(word1_size >  word2_size){
            small  = word2_size;
        }else if(word1_size <  word2_size){
            small = word1_size;
        }else{
            small = word1.size();
        }
        string ans="";
        //logic
        /*
            we will iterate the loop for the small sized string and then will append the 
            remaining characters from other string,
        */
       for (int i = 0;i<small;i++) {
           ans+=word1[i]; //cdf
           ans+=word2[i]; //a
       }
       if(word1_size>word2_size){
           ans.append(word1,word2_size);
       }
       else if(word1_size<word2_size){
           ans.append(word2,word1_size);
       }
      
      return ans;
    }
};
int main(){
    string s1 ="cdf";
    string s2 ="a";
    Solution obj;
    
   string ans = obj.mergeAlternately(s1,s2);
    cout<<ans;
    
    
    
    
    
    return 0;
}