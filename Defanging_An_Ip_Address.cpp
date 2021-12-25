#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int main()
{
   string str = "1.2.5.7.8";
   string ans ="";
   for (int i = 0; i < str.size(); i++)
   {
       if(str[i]=='.'){
           ans+="[.]";
       }else{
           ans+=str[i];
       }
   }
   cout<<ans<<endl;
    return 0;
}