#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1 = "";
        string str2 = "";
        int word1_size = word1.size();
        int word2_size = word2.size();
        for(int i = 0;i<word1_size;i++){
            str1+=word1[i];   
        }
          for(int i = 0;i<word2_size;i++){
            str2+=word2[i];
        }
        if(str1==str2){
            return true;
        }
        return false;
    }
};
int main()
{
  vector<string> str1 = {"ab","c"};
  vector<string> str2 = {"a","bc"};
  Solution obj;
  bool ans =obj.arrayStringsAreEqual(str1,str2);
  cout<<ans<<endl; 
 return 0;
}