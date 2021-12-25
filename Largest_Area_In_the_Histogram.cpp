#include <iostream>
#include <stack>
#include <vector>
using namespace std;
stack<int> st;

// This function finds the Nearest previous(Left) smallest element for the Current Elements
void prevSmallestElement(int *ptr, int *ans, int size)
{
    for (int i = 0; i < size; i++)
    {
        while (st.size() > 0 && ptr[i] < ptr[st.top()])
        {
            st.pop();
        }
        if (st.size() == 0)
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(i);
    }
    while (st.size() != 0)
    {
        st.pop();
    }
}

//  This function finds the Nearest Next(Right) smallest element for the Current Elements
void nextSmallestElement(int *ptr, int *ans, int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        while (st.size() > 0 && ptr[i] < ptr[st.top()])
        {
            st.pop();
        }
        if (st.size() == 0)
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(i);
    }
}
int main()
{
    int arr[] = {2, 4};
    int size = sizeof(arr) / sizeof(int);
    int ans[size];
    int lb[size];
    int rb[size];
    prevSmallestElement(arr, lb, size);
    nextSmallestElement(arr, rb, size);

    cout << arr[1] << endl;
    for (int i = 0; i < size; i++)
    {
        arr[i] = ((rb[i] - lb[i]) - 1) * arr[i];
    }
    int max;
    max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    cout << endl
         << max;
    return 0;
}