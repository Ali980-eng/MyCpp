//lesson 29 
#include <iostream> 
using namespace std; 
int main () 
{ 
    int a; 
    cin>>a; 
    if(a>0) 
    { 
        switch (a) 
        { 
            case 1: a+=3; 
            break; 
            case 3: a++; 
            break; 
            case 6: a+=6; 
            break; 
            case 8: a*=8; 
            break; 
            default: a--; 
 	    } 
    } 
    else 
    { 
        a+=2; 
    } 
    cout<<a; 
    return 0; 
} 