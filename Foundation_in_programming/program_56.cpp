/*
  Vector
  - Iterator
  --- Traversing
  ------ begin()
  ------ end()
  ------ advance()
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
  vector<int> nums = { 10, 20, 30, 40 };
  vector<int>::iterator first = nums.begin();
  vector<int>::iterator last = nums.end() - 1;
  cout << "First Element Is: " << *first << "\n"; // 10
  cout << "Second Element Is: " << first[1] << "\n"; // 20
  cout << "Third Element Is: " << first[2] << "\n"; // 30
  cout << "Last Element Is: " << *last << "\n"; // 40
  cout << "Before Last Element Is: " << *(last - 1) << "\n"; // 30
  advance(first, 3);
  cout << "First Element Is: " << *first << "\n"; // 40
  advance(first, -2);
  cout << "First Element Is: " << *first << "\n"; // 20
  return 0;
}