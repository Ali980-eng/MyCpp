//lesson 25 
/* 
  Control Flow 
  - Nested Ternary Operator 
  - Alternate Syntax for If Condition 
  Syntax 
  (Condition Is True)? True: False; 
*/ 
#include <iostream> 
using namespace std; 
int main () 
{ 
  int age = 15; 
  int points = 450; 
  if (age >= 18) 
  { 
    cout << "OK\n"; 
  }
  else 
  { 
    if (points >= 500) 
    { 
      cout << "OK Because Of Points\n"; 
    } 
    else 
    { 
      cout << "No Age or Points\n"; 
    } 
  } 
  cout << (age >= 18 ? "OK\n" : (points >= 500 ? "OK P\n" : "No P\n")) ; 
  cout << (points >= 500? "OK P\n": "No P\n"); 
  if (age >= 18) 
    cout << "OK\n"; 
  else 
    cout << "Not OK\n"; 
  return 0; 
} 