//lesson 33 
#include <iostream> 
using namespace std; 
int main () 
{ 
    int x,y,z; 
    cin>>x>>y>>z; 
    if (x>y,z) 
    { 
        cout<<"x is the largest number\n"<<x%3<<endl; 
        return 0; 
    } 
    if (y>x,z) 
    { 
        cout<<"y is the largest number\n"<<y%3<<endl; 
        return 0; 
    } 
    if (z>x,y) 
    { 
        cout<<"z is the largest number\n"<<z%3<<endl; 
        return 0; 
    } 
    if (z==x||z==y||x==y) 
    { 
        cout<<"there is two numbers are equal"; 
        return 0; 
    } 
    if (x==z==y) 
    { 
        cout<<"all numbers are equal"; 
        return 0; 
    } 
    else 
    { 
        cout<<"The value you selected does not exist"; 
        return 0; 
    } 
    return 0; 
}