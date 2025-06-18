//lesson 41 
#include <iostream> 
using namespace std; 
int main () 
{ 
    int num,even; 
    cout<<"enter the number you want:"; 
    cin>>num; 
    even=num%2; 
    switch (even) 
    { 
        case (0): 
        { 
            cout<<"the number is even"<<endl; 
            cout<<num/2<<endl; 
        } 
        break; 
        case (1): 
        { 
            cout<<"the number is odd"<<endl; 
            cout<<(3*num+1)/2<<endl; 
        } 
        break; 
    } 
    return 0; 
} 