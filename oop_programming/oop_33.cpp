//class Templates
#include <iostream>
using namespace std;
template<class T>
class number
{
    private:
    T first, second;
    public:
    number (T anum, T bnum)
    {
        first = anum;
        second = bnum;
    }
    T max();
};
template<class T>
T number<T>::max()
{
    return (first>second?first:second);
}
int main()
{
    number<float> ob1(10.5, 20.5), ob2(0.3, 0.25);
    cout<<ob1.max()<<endl;
    cout<<ob2.max()<<endl;
    return 0;
}