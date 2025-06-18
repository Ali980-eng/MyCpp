#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
  Ord
  This function the ASCII value of the character of a string.
  Chr
  This function returns a charactar specified by an ASCII value.
*/

vector<int> Ord_vec (string str)
{
    vector<int> vec;
    for (int i=0;i<str.length();i++)
    vec.push_back(int(str[i]));
    return vec;
}
string Chr_str(vector<int> vec)
{
    string result;
    for (int i=0;i<vec.size();i++)
    result += char(vec[i]);
    return result;
}
int Ord_int (char ch)
{
    return int(ch);
}
char Chr(int num)
{
    return char(num);
}

/*
  String starts with
  "Elzero web School" -> "Elzero" -> True
*/

bool starts(string str, string teststr,bool caseSensitive = true)
{
    if (teststr.length()>str.length()) return false;
    else 
    {
        bool test = 1;
        if (caseSensitive == ture)
        {
            for (int i=0;i<teststr.length();i++)
            {
                if(teststr[i]==str[i]) test *= 1;
                else test *= 0;
            }
            return test;  
        }
        else
        {
            for (int i=0;i<teststr.length();i++)
            {
                if(teststr[i]==str[i]||teststr[i]==toupper(str[i])||teststr[i]==tolower(str[i]))
                test *= 1;
                else test *= 0;
            }
            return test; 
        } 
    }
}

int main()
{
    cout<<Ord_int('e')<<endl;
    cout<<Chr(80)<<endl;
    vector<int> vec = Ord_vec("all");
    for (int i=0;i<vec.size();i++)
    {
        cout<<vec[i];
        if (i<vec.size()-1) cout<<", ";
        else cout<<endl;
    }
    cout<<Chr_str({100,22,99,78,87,99,67,56})<<endl;
    cout<<starts("ali lafi","ali");
    return 0;
}