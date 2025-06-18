// lesson 7 
/*  
calculate your age application  
*/  
#include <iostream>  
using namespace std;  
int main ()  
{  
    cout << "==================================\n";  
     cout << "==calculate your age application==\n";  
    cout << "==================================\n"; 
    int age;  
    cin >> age;  
    int decade = age /10; 
    int months = age * 12;  
    int weeks = (months * 4) +(age*3);  
    int days = age * 365;  
    int hours = days * 24;  
    int minutes = hours * 60;  
    int seconds = minutes * 60; 
    cout<< "\n age in decade is: \n"<<decade; 
    cout << "\n age in months is: \n" << months;  
    cout << "\n age in weeks is: \n" << weeks;  
    cout << "\n age in days is: \n" << days;  
    cout << "\n age in hours is: \n" << hours; 
    cout << "\n age in minutes is: \n" << minutes;  
    cout << "\n age in seconds is: \n" << seconds; 
    return 0; 
} 