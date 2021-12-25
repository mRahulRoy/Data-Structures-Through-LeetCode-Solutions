#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
                        ARRAY PARTITION 1
    Problem statemnt--
    Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

    EXAMPLE--1
    Input: nums = [1,4,3,2]
    Output: 4
    Explanation: All possible pairings (ignoring the ordering of elements) are:
    1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
    2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
    3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
    So the maximum possible sum is 4.

    EXAMPLE--2
    Input: nums = [6,2,6,5,1,2]
    Output: 9
    Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.
*/
int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,7};
    int sum = 0;
    sort(nums.begin(), nums.end());
    // approach1
    for (int i = 0; i < nums.size(); i += 2)
        sum = sum + nums[i];

    //approach2
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if(i%2==0){
    //         sum = nums[i]+sum;
    //     }
    // }
    
    cout << "Maximum Sum is : " << sum;
    return 0;
}

/*
                                                   [ logic explanation ]
        so the logic is pretty simple we will sort the array and will traverse from the 0th index and will increment the iterator by 2 each time.
        ex--1,2,3,4,5,6
        we are considering the indexes are starting from 1
        we know that array is sorted in ascending order so value present at odd indexes will always be smaller or equal to the oddthIndex+1.

        Dry Run
        index--           1  2   3   4   5   6  7   8
        values--         1   2   3   4   5   6  7   7
            odd index value is smaller or equal to odd+1 index value
        Ans is : 16

*/