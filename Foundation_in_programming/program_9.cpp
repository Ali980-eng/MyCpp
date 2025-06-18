//lesson 9 
/* 
  Data Types 
  - Ram [R]andom [A]ccess [M]emory 
  --- Computer Memory Has Locations 
  - Data Sizes 
  --- Bit => [Bi]nary Digi[t] => Smallest Unit in Storage Store Only 0 Or 1 
  --- Byte => A Group of 8 => Store Single Character 
  --- Kilo Byte => 1024 Byte 
  --- Mega Byte => 1024 Kilobytes 
  --- Giga Byte => 1024 Megabytes 
  --- Tera Byte => 1024 Gigabytes 
  - Data Types with Size 
  --- int => 2 Or 4 Bytes => Will Cover Later Why 
  --- float => 4 Bytes [18.5656565656] 
  --- double => 8 Bytes [18.5656565656] 
  ------ Number. Fractional Component 
  --- char => 1 Byte => "A" "x" "9" 
  --- Boolean => 1 Byte => true, false 
  - Double vs Float 
  - The Story Behind Creating a Variable 
  --- Declare A Variable 
  --- Tell Computer That We Need to Reserve X Bytes of Memory Depend on Data Type 
  --- Restrict Type of Data to the Type We Choosed 
  - Declare Variable Without Type 
  - See Memory Address & 
  - Application To Create 
  --- Create App Ask You to Type Number of Kilobytes 
  --- Write 3 Lines Contains 
  ------ [1] The Number of Kilobytes That User Input 
  ------ [2] The Number of Bytes 
  ------ [3] The Number of Bits 
*/ 
#include <iomanip> 
#include <iostream> 
using namespace std; 
int main () 
{ 
  cout << setprecision(13); 
  float fl = 10.1234567891; 
  cout << fl << "\n"; 
  double dob = 10.1234567891; 
  cout << dob << "\n"; 
  auto num = 10; 
  cout << num << "\n"; 
  int nums = 100; 
  cout << &nums; 
  return 0; 
} 