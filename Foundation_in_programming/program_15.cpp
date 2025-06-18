//lesson 15 
#include <iostream> 
using namespace std; 
int main () 
{ 
    char a='A'; 
    cout <<a<<sizeof(a)<<endl; 
    char b='B'; 
    cout <<b<<sizeof(b)<<endl; 
    auto c='C'; 
    cout <<c<<sizeof(c)<<endl; 
    auto s="S"; 
    cout <<s<<sizeof(s)<<endl; 
    int p; 
    p=a+c; 
    cout <<p<<"\n"<<sizeof (p)<<endl; 
    cout << int (a)<<endl; 
    cout << char (85); 
    return 0; 
} 