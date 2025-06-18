#include <iostream>
using namespace std;
template<class T_1 ,class T_2>
/*Template:
*it used to make a dynamic data type.
*and make the function dynamic that takes
any data type.
*in case you want to pass two different
value in the same timethen you have to use
multiple parameter template.
*we make multiple parameter template by
diffining to class in the template.
*all class in the template will take the data type
of the value that by pass to it in the calling function.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
T_1 sum (T_1 x, T_2 y)
{
    return x+y;
}
int main()
{
    double x=0;
    int y=0;
    cout<<"enter the 1st value : ";
    cin>>x;
    cout<<"enter the 2nd value : ";
    cin>>y;
    cout<<"the sum of values : "<<sum(x,y);
    return 0;
}