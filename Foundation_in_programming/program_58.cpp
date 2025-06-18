/*
  Vector
  - Use Iterator To:
  --- Sort
  --- Count
  --- Reverse
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  vector<int> nums = { 10, 500, 60, -20, 20, 20, 100, 20 };
  int val = 20;
  int countTimes = count(nums.begin(), nums.end(), val);
  cout << "Number " << val << " Found " << countTimes << " Times.\n";
  cout << "=====================\n";
  for (int &#038; n : nums)
  {
    cout << n << "\n";
  }
  cout << "=====================\n";
  sort(nums.begin(), nums.end());
  for (int &#038; n : nums)
  {
    cout << n << "\n";
  }
  cout << "=====================\n";
  reverse(nums.begin(), nums.end());
  for (int &#038; n : nums)
  {
    cout << n << "\n";
  }
  cout << "=====================\n";
  return 0;
}