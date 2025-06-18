//lesson 13 
/* 
  Primitive Data Types 
  - float => Floating Point Number 
  --- Test Integer Value in Float Variable 
  --- We Make Sure Its Float Not Double by Adding Suffix "f" Or "F" 
  --- Test With Auto 
  --- 7 Decimal Precision 
  - double => Double the Float 
  --- 15 Decimal Precision 
*/  
#include <iostream> 
using namespace std;  
int main () 
{ 
  int num = 10; 
  num = 20.5; 
  cout << sizeof(num) << endl; // 4 
  cout << num << endl;         // 20 
  double dob = 10; 
  dob = 20.5; 
  cout << sizeof(dob) << endl; // 8 
  cout << dob << endl;         // 20.5 
  float fl = 10.5f + 9.5f; 
  cout << sizeof(fl) << endl; // 4 
  cout << fl << endl;         // 20 
  auto mix = 10.f; 
  return 0; 
} 