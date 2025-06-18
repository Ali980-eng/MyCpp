//lesson 38 
/* 
  String 
  - What Is String? 
  - String Types 
  --- C Style String Using 
  --- String Class Using Standard Library 
  - Test Types Size 
  - Null Terminated String 
  - \0 => Null 
  - Remember 
  --- String Is Array of Characters 
*/ 
#include <iostream> 
using namespace std; 
int main () 
{ 
  cout << "Iam Dragon\n";// 12 => Remember 
  cout << "Iam\0 Dragon\n"; // Iam 
  cout << "\n"; 
  char name_a[] = "Elzero"; 
  cout << name_a << "\n";// Elzero\0 
  cout << sizeof(name_a) << "\n"; // 7 
  cout << name_a[0] << "\n";// E 
  cout << name_a[5] << "\n";// o 
  cout << int(name_a[6]) << "\n"; // \0 => ASCII Value => 0 
  cout << int('\b') << "\n";// \b => ASCII Value => 8 
  char name_b[] = {'E', 'l', 'z', 'e', 'r', 'o', '\0'}; 
  cout << name_b << "\n";// Elzero\0 
  cout << sizeof(name_b) << "\n"; // 7 
  cout << name_b[0] << "\n";// E 
  cout << name_b[5] << "\n";// o 
  string name_c = "Elzero"; 
  cout << name_c << "\n";// Elzero\0 
  cout << sizeof(name_c) << "\n"; // 32 
  cout << name_c[0] << "\n";// E 
  cout << name_c[5] << "\n";// o 
  return 0; 
} 