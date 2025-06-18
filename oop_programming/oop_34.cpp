/*Template specialization:
    to create an class specialize
    to handle with special data type
*/
#include <iostream>
using namespace std;
template<class T>
class A_char
{
    public:
    A_char(T x)
    {
        cout<<x<<" is not character"<<endl;
    }
};
template<>//Temlate specialzation
class A_char<char>
{//the special class to receive characters
    public:
    A_char(char x)
    {
        cout<<x<<" is a character"<<endl;
    }
};
int main()
{
    A_char<char> obj1('a');
    A_char<int> obj2(7);
    A_char<double> obj3(5.199);
    return 0;
}