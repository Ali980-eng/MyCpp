#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int *p1, *p2;
    p1 = new int;
    *p1 = 10;
    cout<<&p1<<endl;//Location of the pointer
    cout<<"Memory location "<<p1<<endl;
    cout<<" contains "<<*p1<<endl;
    p2 = new int;
    *p2 = 20;
    cout<<&p2<<endl;//Location of the pointer
    cout<<"Memory location "<<p2<<endl;
    cout<<" contains "<<*p2<<endl;
    delete p1;
    delete p2;
    return 0;
}