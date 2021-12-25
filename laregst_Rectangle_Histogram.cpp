/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    stack<int> st;
    void prevSmallestElement(vector<int> heights, int *arr)
    {
        for (int i = 0; i < heights.size(); i++)
        {
            while (st.size() > 0 && heights[i] < heights[st.top()])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                arr[i] = -1;
            }
            else
            {
                arr[i] = st.top();
            }
            st.push(i);
        }
        while (st.size() != 0)
        {
            st.pop();
        }
    }

    void nextSmallestElement(vector<int> heights, int *arr)
    {
        for (int i = heights.size() - 1; i >= 0; i--)
        {
            while (st.size() > 0 && heights[i] < heights[st.top()])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                arr[i] = -1;
            }
            else
            {
                arr[i] = st.top();
            }
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int> &heights)
    {
        int lb[heights.size()];
        int rb[heights.size()];
        prevSmallestElement(heights, lb);
        nextSmallestElement(heights, rb);
        int max;

        for (int i = 0; i < heights.size(); i++)
        {
            heights[i] = (rb[i] - (lb[i] - 1)) * heights[i];
        }
        cout << heights[0]<<endl;
        cout << heights[1]<<endl;
        max = heights[0];
        for (int i = 1; i < heights.size(); i++)
        {
            if (max < heights[i])
            {
                max = heights[i];
            }
        }
        return max;
    }
};

int main()
{
    vector<int> heights{2, 4};
    Solution obj;
    int ans = obj.largestRectangleArea(heights);

    cout << ans;
    return 0;
}
