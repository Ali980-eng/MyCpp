#include <iostream>
#include <string>
using namespace std;
template<class first, class second>
first smaller(first a, second b)
{
    return (a<b ? a : b);
}
int main()
{
    int x = 89;
    double y = 56.78;
    char ch = 'a';
    string str = "ali";
    cout<<smaller(y,x)<<endl;//or smaller<double>(x, y) or smaller<double, int>(x, y)
    cout<<smaller(x, y)<<endl;
    cout<<smaller(ch,x)<<endl;
    /*conclusion:
    the conclusion is the return type depend
    on the first argument you signed*/
    return 0;
}