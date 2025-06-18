#include <iostream>
#include <string>
using namespace std;
//static mean the common thing in the program
void fun()
{
    int x = 0;
    x++;
    cout<<x;
}
void fun(int y)
{
    static int x = y;
    x++;
    cout<<x;
}
int main()
{
    for (int i=0;i<5;i++)
    {
        fun();// with out static ~~> the value will be absorbed in every loop
        fun(0);//with static ~~> the value will increase in ever loop
        cout<<endl;
    }
    return 0;
}