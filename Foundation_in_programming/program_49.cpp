//lesson 49 
/* 
  Function 
  - Passing Array As Parameter 
*/ 
#include <iostream> 
using namespace std; 
// void calc(int n1, int n2, int n3) 
// { 
//   cout << n1 + n2 + n3 << "\n"; 
// } 
void calc(int nums[], int count) 
{ 
  int result = 0; 
  for (int i = 0; i < count; i++) 
  { 
    result += nums[i]; 
  } 
  cout << "Result Is: " << result << "\n"; 
} 
int main() 
{ 
  // calc(10, 20, 30); 
  int arrayOfNumbers[] = {10, 20, 30, 40, 100}; 
  int numsSize = size(arrayOfNumbers); 
  calc(arrayOfNumbers, numsSize);
  return 0; 
}