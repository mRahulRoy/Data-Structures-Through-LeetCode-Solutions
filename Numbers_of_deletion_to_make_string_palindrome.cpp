
#include <iostream>
#include <string>

using namespace std;

int minDeletions(string str, int n)
{
    int start = 0;
    int end = n - 1;
    int count = 0;
    for (int i = 0; i < (n / 2); i++)
    {

        if (str[start] == str[end])
        {
            continue;
        }
        else
            count += 2;

        start++;
        end--;
    }

    return count;
}
int main()
{
    string str = "aebcbda";

    int ans = minDeletions(str, str.size());
    cout << ans;
    int start = 0;
    int end = 7;
    int count = 0;
    for (int i = 0; i < (7 / 2); i++)
    {

        if (str[start] == str[end])
        {
            continue;
        }
        else
            count += 2;

        start++;
        end--;
    }
    cout << count;
    return 0;
}
