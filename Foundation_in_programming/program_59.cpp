/*
  Pointers
  What Are Pointers ?
  --- A Variable That Store Memory Address Of Other Variable
  Why We Need Pointers ?
  --- To Iterate On Elements In Data Structures Like Array
  --- Pass Function To Other Function
  --- Dynamic Memory Allocation
  Benefits Of Using Pointers
  --- Reduce The Code and Increase Performance
  Note
  --- There's Raw Pointer And Smart Pointer
  Syntax
  --- Declare A Pointer
  --- Print Variable Memory Address => Reference Operator || Address Of [&]
  --- Print Value That Memory Address Point To => Dereference Operator [*]
  --- Change Variable Value With Pointer
*/
#include <iostream>
using namespace std;
int main()
{
  int num = 100;
  int *ptr = &num;
  cout << "Value: " << num << "\n";
  cout << "Address: " << &#038;num << "\n";
  cout << "Address: " << ptr << "\n";
  cout << "Value: " << *ptr << "\n";
  *ptr = 200;
  cout << "Value: " << num << "\n";
  cout << "Address: " << &#038;num << "\n";
  cout << "Address: " << ptr << "\n";
  cout << "Value: " << *ptr << "\n";
  return 0;
}