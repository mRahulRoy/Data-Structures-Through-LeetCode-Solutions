#include <iostream>
#include <algorithm>
#include <vector>

/*
                  ----------- LEETCODE -1051  HEIGHT CHECKER ---------
    A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in non-decreasing order by height. Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.
    You are given an integer array heights representing the current order that the students are standing in. Each heights[i] is the height of the ith student in line (0-indexed).

    Return the number of indices where heights[i] != expected[i].

    Example 1:
    Input: heights = [1,1,4,2,1,3]
    Output: 3
    Explanation: 
    heights:  [1,1,4,2,1,3]
    expected: [1,1,1,2,3,4]
    Indices 2, 4, and 5 do not match.

    Example 2:
    Input: heights = [5,1,2,3,4]
    Output: 5
    Explanation:
    heights:  [5,1,2,3,4]
    expected: [1,2,3,4,5]
    All indices do not match.

    Example 3:
    Input: heights = [1,2,3,4,5]
    Output: 0
    Explanation:
    heights:  [1,2,3,4,5]
    expected: [1,2,3,4,5]
    All indices match.

                    LOGIC EXPLANATION
    supppose you are given a array of height of students . Teacher wants student to stand in non decresing order that means ith student's height must be greater than or equal to the height of ith+1 student.
    consider this exapmple for better understanding.
    ex--- [1,1,4,2,1,3] --> this is the height of the student array given to us. so if we want students to stand in non decreasing order then this array given to us should look like this [1,1,1,2,3,4] or this is our expectaion height.
    so question is pretty easy . we will create a another vector and will assign the given height to this vector and will sort that vector in non decreasing order. After sorting that expected vector we will loop the given array and will compare if the ith height of given array equal or not to the ith height of expected array , if both values or heights are same then dont do anything if not same then take a counter and increment it by 1 each time you get not correct value.

    dryRun of example -- [1,1,4,2,1,3]
       Expected array -- [1,1,1,2,3,4]
              Indexes -- [0,1,2,3,4,5]
              we can clearly see that height at indexes 2 ,4 and 5 are not equal so our answer would be five.
*/
using namespace std;
class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        int count = 0;
        vector<int> expected;
        expected = heights;
        sort(expected.begin(), expected.end());
        for (int i = 0; i < heights.size(); i++)
        {
            if (heights[i] != expected[i])
            {
                count++;
            }
        }
        return count;
    }
};
int main()
{
    vector<int> heights = {1, 2, 3, 4, 5};
    Solution obj;
    int ans = obj.heightChecker(heights);
    cout << ans;
    return 0;
}