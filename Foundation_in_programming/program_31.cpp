//lesson 31 
/* 
  Arrays 
  - Access Array Elements 
  - Check Element Location 
*/ 
#include <iostream> 
using namespace std; 
int main () 
{ 
  int nums[] {100, 200, 300}; 
  cout << "First Element: " << nums[0] << "\n"; 
  cout << "Last Element: " << nums[2] << "\n"; // Number of Elements - 1 
  cout << "Location: " << &#038;nums[0] << "\n"; 
  cout << "Location: " << &#038;nums[1] << "\n"; 
  cout << "Location: " << &#038;nums[2] << "\n"; 
  return 0; 
} 