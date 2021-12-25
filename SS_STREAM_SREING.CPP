#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <utility> //for pairs in stl
using namespace std;
int main()
{
    string str = " i am rahul kumar roy";
    stringstream ss(str);//this splits the string into individual words that can be stored easily in vector
    vector<string> vec;
    int tot_words = 0;
    while (ss >> str)
    {
       vec.push_back(str);
        tot_words++;
    }
    cout<<"Total number of words : "<<tot_words<<endl;
    cout<<"Size of Vector : "<<vec.size()<<endl;
    vector<string>::iterator itr = vec.begin();
    while(itr!=vec.end()){
        cout<<*itr<<endl;
        itr++;
    }
    return 0;
}