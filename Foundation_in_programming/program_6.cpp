//lesson 6 
/* 
constant variable 
    read only value 
    can't declare without value 
*/ 
#include <iostream> 
using namespace std; 
#define DAYS 9 
int main () 
{ 
    const int day = 8; 
    int salary = 799; 
    const int num = 100; 
    //num = 200; 
    cout << num; 
    cout << "\n" << DAYS; 
    cout << "\n" <<salary/30; 
    cout<<"\n" << 26/8; 
    return 0; 
} 