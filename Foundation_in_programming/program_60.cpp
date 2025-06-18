/*
  Pointers
  -- Pointing To Array
*/
#include <iostream>
using namespace std;
int main()
{
  short int nums[]{10, 20, 30, 40};
  short int *ptr = &nums[0];
  cout << "First Element\n\n";
  cout << "Value With Index: " << nums[0] << "\n";
  cout << "Value With Pointer: " << *ptr << "\n";
  cout << "Address With Index: " << &#038;nums[0] << "\n";
  cout << "Address With Pointer: " << ptr << "\n";
  cout << "Second Element\n\n";
  cout << "Value With Index: " << nums[1] << "\n";
  cout << "Value With Pointer: " << *(ptr + 1) << "\n";
  cout << "Address With Index: " << &#038;nums[1] << "\n";
  cout << "Address With Pointer: " << ptr + 1 << "\n";
  cout << "Third Element\n\n";
  cout << "Value With Index: " << nums[2] << "\n";
  cout << "Value With Pointer: " << *(ptr + 2) << "\n";
  cout << "Address With Index: " << &#038;nums[2] << "\n";
  cout << "Address With Pointer: " << ptr + 2 << "\n";
  cout << "Fourth Element\n\n";
  cout << "Value With Index: " << nums[3] << "\n";
  cout << "Value With Pointer: " << *(ptr + 3) << "\n";
  cout << "Address With Index: " << &#038;nums[3] << "\n";
  cout << "Address With Pointer: " << ptr + 3 << "\n";
  return 0;
}