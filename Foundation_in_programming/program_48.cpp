//lesson 48 
#include <iostream> 
#include <string> 
using namespace std; 
void sayHello(string msg, string name, int age)  
{ 
    cout << msg << " " << name << ",\n"; 
    cout << name << "\'s age is: " << age << endl; 
} 
int main()  
{ 
    string name_ar[] = {"Osama", "Ahmed", "Sayed"}; 
    string msg_ar[] = {"Hi", "Hello", "Welcome"}; 
    int a_g[] = {40, 25, 35}; 
    for (int i = 0; i < 3; i++) 
    { // Corrected loop condition 
        sayHello(msg_ar[i], name_ar[i], a_g[i]); 
        // Pass individual elements 
    } 
    return 0; 
} 