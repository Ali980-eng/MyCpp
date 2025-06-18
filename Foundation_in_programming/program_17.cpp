//lesson 17 
#include <iostream> 
using namespace std; 
int main () 
{ 
    auto age = 100; 
    cout <<sizeof (age)<<endl; 
    short int new_age = 125; 
    cout <<sizeof (new_age)<<endl; 
    cout <<sizeof (short)<<endl; 
    cout <<sizeof (long)<<endl; 
    cout <<sizeof (long long) <<endl; 
    int z = 85; 
    signed int x = -60; //accept the number in (- or + or 0) 
    unsigned int y=30; //accept only positive number 
    cout<<x<<endl; 
    cout<<y<<endl; 
    using bignum = long long int; 
    bignum m_n = 200456696279; 
    cout <<m_n/z; 
    return 0;
} 