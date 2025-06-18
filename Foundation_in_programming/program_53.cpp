/*
  Vector
  - Access
  --- at()
  --- Square Brackets [] < Do Not Use
  - Add
  --- push_back => Add Element To The End
  - Update
  --- at()
  - Delete
  --- pop_back() => Remove Element From The End
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
  vector<int> nums = { 10, 20, 30 };
  cout << nums.at(2) << "\n";
  cout << nums[2] << "\n";
  nums.push_back(40);
  cout << nums.size() << "\n"; // 4
  cout << nums.at(3) << "\n"; // 40
  nums.at(3) = 100;
  cout << nums.at(3) << "\n"; // 100
  nums.push_back(500);
  cout << nums.size() << "\n"; // 5
  cout << nums.at(4) << "\n"; // 500
  nums.pop_back();
  cout << nums.size() << "\n"; // 4
  return 0;
}