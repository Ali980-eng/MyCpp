//lesson 5
/* 
variables scope 
global variable 
local variable 
*/ 
#include <iostream> 
using namespace std; 
int a=100; //global variable 
int b=200; //global variable 
int second () 
{ 
    cout << a << "coming from second function\n"; 
    cout << b << "coming from second function\n"; 
    int z=70; //local variable for second function only 
    cout << z; 
    cout <<"\n ==========\n"; 
    cout <<z*b; 
    return 0; 
} 
int main () 
{ 
    cout << a << "coming from main function\n"; 
    cout << b << "coming from main function\n"; 
    second (); 
    int c=80; 
    cout << c;//local variable for main function only 
    cout <<"\n ==========\n";
    cout <<c+a; 
    return 0; 
} 