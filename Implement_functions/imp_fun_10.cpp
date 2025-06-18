#include <iostream>
#include <string>
using namespace std;
string remove_vowels(const string &str)
{
    string newstr = "";
    for (int i=0;i<str.length();i++)
    {
        char ch = str[i];
        if (ch=='e'||ch=='a'||ch=='u'||ch=='o'||ch=='i')
        continue;
        else newstr += str[i];
    }
    return newstr;
}
bool solution(string const &str,string const &ending)
{
   short int endlen = ending.length(),len = str.length();
    bool test = 1;
    if (endlen==0) return true;
    else
    {
        for (int i=len-endlen;i<len;i++)
        {
            if (str[i]==ending[i]) test *= 1;
            else test *= 0;
        }
    }
  return test;
}
int main()
{
    string str;
    cout<<"enter the string:";
    cin>>str;
    //cout<<remove_vowels(str);
    string test_str;
    cout<<"enter the test string:";
    cin>>test_str;
    cout<<solution(str,test_str);
    return 0;
}