//lesson 27 
#include <iostream> 
using namespace std; 
int main () 
{ 
    int day; 
    cout<<"Choose A Day From 1 To 25\n"; 
    cin >>day; 
    /*if (day==1) 
    { 
        cout<<"Open From 8:00 To 14:00\n"; 
    } 
    else if (day==2) 
    { 
        cout<<"Open From 8:00 To 14:00\n"; 
    } 
    else if (day==3) 
    { 
        cout<<"Open From 10:00 To 16:00\n"; 
    } 
    else 
    { 
        cout<<"Closed\n"; 
    }*/ 
    switch (day) 
    { 
        case 1: 
        case 2: 
        cout<<"Open From 8:00 To 14:00"; 
        break; 
        case 3: 
        cout<<"Open From 10:00 To 16:00"; 
        break; 
        default: 
        cout<<"Closed"; 
    } 
    return 0;  
} 