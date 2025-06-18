//lesson 36 
/* 
  Arrays 
  - Useful Methods 
  --- at 
  --- front 
  --- back 
  --- fill 
  --- size 
  --- empty 
*/ 
#include <array> 
#include <iostream> 
using namespace std; 
int main () 
{ 
  array<int, 4> nums = {100, 200, 300, 400}; 
  cout << nums[0] << "\n";// 100 
  cout << nums.front() << "\n"; // 100 
  cout << nums[3] << "\n";// 400 
  cout << nums.back() << "\n"; // 400 
  cout << nums.at(1) << "\n"; // 200 
  cout << nums.size() << "\n"; // 4 
  cout << nums.empty() << "\n"; // 0 => False 
  return 0; 
} 