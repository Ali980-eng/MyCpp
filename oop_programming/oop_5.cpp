#include <iostream>
using namespace std;
int main()
{
    int *p;
    p = new int;//To create a location for the pointer in the memory
    *p = 10;
    cout<<"the value inside the location: "<<*p<<endl;
    cout<<"the location: "<<p<<endl;
    delete p;//To delete the location in the memory
    cout<<"====================\n";
    cout<<*p<<endl;//The output in the terminal will be rubbish data
    cout<<"====================\n";
    p = new int;
    *p = 20;
    cout<<"the value inside the new location: "<<*p<<endl;
    cout<<"the new location: "<<p<<endl;
    return 0;
}