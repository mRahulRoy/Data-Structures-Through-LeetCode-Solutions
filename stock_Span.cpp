#include <bits/stdc++.h>
using namespace std;
class StockSpanner
{
    stack<pair<int, int>> st;
    int index = 0;

public:
    int next(int price)
    {
        int ans = 0;
        if (index == 0)
        {
            st.push(make_pair(index, price));
            index++;
            return 1;
        }

        while (st.size() > 0 && price >= st.top().second)
        {
            st.pop();
        }
        if (st.size() == 0)
        {
            ans = index + 1;
        }
        else
        {
            ans = index - st.top().first;
        }
        st.push(make_pair(index, price));
        index++;
        return ans;
    }
};

int main()
{
    int arr[7] = {100, 80, 60, 70, 60, 75, 85};
    int ans[7];
    StockSpanner *obj = new StockSpanner();
    for (int i = 0; i < 7; i++)
    {
        ans[i] = obj->next(arr[i]);
    }

    for (int i = 0; i < 7; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}

/*
 
     stack<pair<int, int>> st;
        int index;
    int pos = 0;
    100, 80, 60, 70, 60, 75, 85
    int next(int price)
    {
        pos++;
        int ans = 0;
        if (st.size() == 0)
        {
            st.push(make_pair(pos, price));
            return 1;
        }
        else
        {
            while (st.size() > 0 && price >= st.top().second)
            {
                st.pop();
            }
            ans = pos - ((st.size() == 0) ? 0 : st.top().first);
            st.push(make_pair(pos, price));
        }
        return ans;
    }

*/