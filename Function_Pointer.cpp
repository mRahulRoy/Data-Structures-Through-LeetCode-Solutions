#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
/*We are practising here Function pointer
    Function pointer is used in callback functions and call back functions are the Functions that take another function as an argument or parameter.
*/
void add(int a, int b)
{
    cout << "Ans is : " << a + b << endl;
  
}
int main()
{
    void (*fptr)(int, int);
    fptr = add;
    fptr(10, 10);

    return 0;
}