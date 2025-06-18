#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
enum numbers {zero,one,two,three,four,five,six,seven,eight,nine,ten};
/**enum numbers zero ~~> const int zero = 0
 * When printing a variable from the enumeration, the integer number is printed.
 * The first form enumeration begin from zero.
 * Static elements that cannot be modified or entered by the user.
 * */
int main()
{
    string sarr[11] = {"zero","one","two","three","four","five","six","seven","eight","nine","ten"};
    numbers m[11] = {zero,one,two,three,four,five,six,seven,eight,nine,ten};
    for (size_t i=0;i<11;i++)
    {
        cout<<sarr[i]<<" = "<<m[i]<<endl;
    }
    return 0;
}