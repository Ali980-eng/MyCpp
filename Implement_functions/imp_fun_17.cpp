#include <iostream>
#include <string>
using namespace std;
string vaporcode(const string &str)
{
    string result;
    int len = str.length();
    for (int i=0;i<len;i++)
    {
        if (str[i]>='A'&&str[i]<='Z') 
        {
            result += str[i];
            result += "  ";
        }
        else if (str[i]>='a'&&str[i]<='z')
        {
            result += toupper(str[i]);
            result += "  ";
        }
        else
        {
            if (str[i]!=' ') 
            {
                result += str[i];
                result += "  ";
            }
            else continue;
        }
    }
    return result;
}
int main()
{
    string str1 = "Let's go to the movies";
    cout<<vaporcode(str1)<<endl;
    string str2 = "Why isn't my code working?";
    cout<<vaporcode(str2)<<endl;
    return 0;
}