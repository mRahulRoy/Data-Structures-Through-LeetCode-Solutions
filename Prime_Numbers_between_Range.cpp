#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int starting_Range = 1;
    int ending_Range = 10;
    int total_Prime = 0;
    for (int i = starting_Range; i <= ending_Range; i++)
    {
        int count = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
                count++;
        }
        if (count == 2)
        {
            cout << i << " is a Prime Number" << endl;
            total_Prime++;
        }
        else
        {
            cout << i << " is not a prime number" << endl;
        }
    }
    cout << "There are " << total_Prime << " Prime Numbers in the list" << endl;
    return 0;
}