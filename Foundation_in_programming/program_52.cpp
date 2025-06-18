/*
  Vector
  --- Vector vs Array
  - Vector
  --- It Need A Standard Header To Work
  --- Can Be Resized After Insertion Or Deletion Of Elements
  --- Not Index Based And Elements Accessed By Iterators
  --- Vectors Are Slower Than Arrays
  --- Vectors Occupy More Memory
  --- Available In C++ Only
  - Array
  --- C-Array Is Language Construct
  --- Cannot Be Resized After Its Defined
  --- Elements Accessed By Indexes
  --- Arrays Are Faster Than Vectors
  --- Arrays Occupy Less Memory
  --- Available In C & C++
  When To Use Vector
  --- When We Don't Know The Size Of The List
  When We Use Array
  --- When It Comes To Performance & Speed
  [1] After Learning Pointers There Will Be More Things To Compare
  [2] You Can Still Create Dynamic Array But Vector Is Better
*/
#include <iostream>
#include <vector>
#include <array>
using namespace std;
void calc(vector<int> numsVector)
{
  int result = 0;
  for (int i = 0; i < numsVector.size(); i++)
  {
    result += numsVector[i];
  }
  cout << "Result Is: " << result << "\n";
}
int main()
{
  int nums[4] = { 10, 20, 30 };
  cout << nums[2] << "\n";
  nums[3] = 100;
  cout << nums[3] << "\n";
  cout << "=========\n";
  array<int, 4> numsArray = { 10, 20, 30 };
  cout << numsArray[2] << "\n";
  numsArray[3] = 100;
  cout << numsArray[3] << "\n";
  cout << "=========\n";
  vector<int> arrayOfNumbers = { 10, 20, 30, 40, 100, 300 };
  calc(arrayOfNumbers);
  return 0;
}