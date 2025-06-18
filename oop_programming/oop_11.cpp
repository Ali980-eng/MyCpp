#include <iostream>
#include <string>
using namespace std;
string day[7] = {"sat","sun","mon","tue","wed","thu","fri"};
enum Days {sat = 1, sun, mon, tue, wed, thur, fri};
class week
{
private:
    Days d[7];
public:
    void setday(Days w[])
    {
        for(size_t i=0;i<7;i++) d[i] = w[i];
    }
    void print()
    {
        for(size_t i=0;i<7;i++)
        cout<<"The number of day "<<day[i]<<" = "<<d[i]<<endl;
    }
};
int main()
{
    Days d[7] = {sat, sun, mon, tue, wed, thur, fri};
    week g;
    g.setday(d);
    g.print();
    return 0;
}