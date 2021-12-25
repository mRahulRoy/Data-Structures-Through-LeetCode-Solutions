#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
/*
                        Leetcode-1356, Sort Integer By The Number Of 1 Bits
    Question:--  
        You are given an array nums, you have to sort the integers in the array inascending order by the number of 1s in their binary representation and in case of two or more integers have the same number of 1s, you have to sort them in ascending order.
        Return the sorted array.

    Example 1:
    Input: arr = [0,1,2,3,4,5,6,7,8]
    Output: [0,1,2,4,8,3,5,6,7]
    Explantion: [0] is the only integer with 0 bits.
    [1,2,4,8] all have 1 bit.
    [3,5,6] have 2 bits.
    [7] has 3 bits.
    The sorted array by bits is [0,1,2,4,8,3,5,6,7]

    Example 2:
    Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
    Output: [1,2,4,8,16,32,64,128,256,512,1024]
    Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.

    Example 3:
    Input: arr = [10000,10000]
    Output: [10000,10000]
*/
class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        vector<int> ans;
        vector<pair<int, int>> p;
        for (int i = 0; i < arr.size(); i++)
        {
            p.push_back(make_pair(__builtin_popcount(arr[i]), arr[i]));
        }
        sort(p.begin(), p.end());
        for (int i = 0; i < arr.size(); i++)
        {
            ans.push_back(p[i].second);
        }
        return ans;
    }
};
int main()
{

    vector<int> arr = {0,1,2,3,4,5,6,7,8};
    Solution obj;
    vector<int> ans = obj.sortByBits(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " " << endl;
    }

    return 0;
}

/*
    logic--
    we will use __builtin_popcount(val). This function gives the total number of 1s present in the binary code
    example - binary of 4 is 100 and there is only 1 , 1 is present. I hope it is clear.
    The main logic is pretty simple. We will create a pair and will store the setBits in first and arr[i] in the second storage of the pair. it means all the setBits are stored corresponding to the value presnt at the arr[i]. After that we will sort that pair ,after sorting the pair the stBits and values at arr[i] gets sorted corresponding to each other.
    dot first storage will be sorted in amount of 1s and in the second storage values of arr[i] will be stored. After that we create a ans vector and will push the each second value of the pair.
    now we are done.

    Practical 
    given array =  [0,1,2,3,4,5,6,7,8];
    vector<pair<int,int>> p;
    will assign the setBits to first and array values to second, just like this.

         BEFORE  SORTING 
    First               Second
    0                   0
    1                   1
    1                   2
    2                   3
    1                   4
    2                   5   
    2                   6
    3                   7
    1                   8

       AFTER  SORTING   
  First               Second
    0                   0
    1                   1
    1                   2
    2                   4
    1                   8
    2                   3   
    2                   5
    3                   6
    1                   7    
  now we are close to  the answer.
  store the value of second in a new answer vector.
*/