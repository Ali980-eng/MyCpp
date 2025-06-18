#include <iostream>
#include <vector>
using namespace std;

/*
  Push Items To Vector
  {"Osama", "Ahmed", "Sayed", "Ali"} -> Size = 4
*/
vector<string> pushItem(vector<string> v, string item)
{
  // Create Vector With One More Element
  vector<string> result(v.size() + 1);
  // Copy Elements From Main Vector To The New Vector
  for (int i = 0; i < v.size(); i++)
  {
    result[i] = v[i];
  }
  // Add The Item
  result[v.size()] = item;
  return result;
}
/*
  Money Format
  100 -> 100
  1000 -> 1,000
  10000 -> 10,000
  100000 -> 100,000
  1000000 -> 1,000,000
*/
string money_format(string str) 
{
  int len = str.length();
  string result;
  int count = 0;
  for (char ch : str) 
  {
    if (!isdigit(ch)) return str;
  }
  for (int i = len - 1; i >= 0; i--) 
  {
    result = str[i] + result;
    count++;
    if (count % 3 == 0 && i != 0) result = ',' + result;
  }
  return result;
}

int main()
{
  /*vector<string> names = {"Osama", "Ahmed", "Sayed", "Ali"};
    names = pushItem(names, "Mahmoud");
    names = pushItem(names, "Gamal");
    for (string name : names)
    {
        cout << name << endl;
    }*/
  cout<<money_format("100")<<endl;
  cout<<money_format("1000")<<endl;
  cout<<money_format("10000")<<endl;
  cout<<money_format("100000")<<endl;
  cout<<money_format("1000000");
  return 0;
}