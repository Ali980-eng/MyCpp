//lesson 10 
#include <iostream> 
using namespace std; 
int main () 
{ 
    cout << "\n number of kilobytes is: \n"; 
    int kilobytes; 
    cin>> kilobytes; 
    cout << "\n number of bytes is: \n"; 
    int bytes; 
    bytes = kilobytes * 1024; 
    cout << bytes; 
    cout << "\n number of bit is:\n"; 
    int bit; 
    bit = bytes * 8; 
    cout << bit;
} 