#include <iostream>
using namespace std;
/*
        LEETCODE 762. Prime Number of Set Bits in Binary Representation
    question :
        Given two integers left and right, return the count of numbers in the inclusive range [left, right] having a prime number of set bits in their binary representation.
    Recall that the number of set bits an integer has is the number of 1's present when written in binary.
    For example, 21 written in binary is 10101, which has 3 set bits.

    Example 1:
    Input: left = 6, right = 10
    Output: 4
    Explanation:
    6  -> 110 (2 set bits, 2 is prime)
    7  -> 111 (3 set bits, 3 is prime)
    8  -> 1000 (1 set bit, 1 is not prime)
    9  -> 1001 (2 set bits, 2 is prime)
    10 -> 1010 (2 set bits, 2 is prime)

    4 numbers have a prime number of set bits.
    Example 2:
    Input: left = 10, right = 15
    Output: 5
    Explanation:
    10 -> 1010 (2 set bits, 2 is prime)
    11 -> 1011 (3 set bits, 3 is prime)
    12 -> 1100 (2 set bits, 2 is prime)
    13 -> 1101 (3 set bits, 3 is prime)
    14 -> 1110 (3 set bits, 3 is prime)
    15 -> 1111 (4 set bits, 4 is not prime)
    5 numbers have a prime number of set bits.

    Constraints:
    1 <= left <= right <= 106
    0 <= right - left <= 104

    -----Logic for the answer------
    we are tarversing the range from left to right and checking what is the 1s bit count of that number using inbuilt function( --inbuilt_popcount(n) ) in binary representaion. and after that ,checking if the count we get is prime or not . If the count is prime then simply increment the counter by one for each prime bit count.
    

*/
class Solution {
public:
    bool isPrime(int num){
        int count=2;
        if(num==2)
        return true;
        else if(num==1){
            return false;
        }
        for(int i = 2;i<num;i++){
            if(num%i==0){
                count++;
            }
        }
        if(count==2){
            return true;
        }
      
        return false;
    }
    int countPrimeSetBits(int left, int right) {
        int count =0;
        for(int i = left;i<=right;i++){
            if(isPrime((__builtin_popcount(i)))){
                count++;
            }
        }
        return count;
    }
};

int main()
{
    int left = 842;
    int right = 888;
    Solution obj;
    int ans = obj.countPrimeSetBits(left,right);
    
   cout<<ans;

    return 0;
}
