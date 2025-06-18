#include <iostream>
using namespace std;

/*
    Count words in string
    "Hello Elzero wed school" -> 4
    "Hello#Elzero#wed#school" -> '#' -> 4
*/
int count;
int Count_words(string str,char ch = ' ')
{
    size_t len = str.length();
    count = 0;
    if (len==0) return 0;
    for (int i=0;i<len;i++)
    {
        if (str[i]==ch) count++;
        else continue;
    }
    if (str[len-1]!=ch) count++;
    else count--;
    return count;
}

/*
    Is First Letter Capital
    "Hello Elzero Web School" -> True -> All Caps
    "Hello elzero Wed School" -> False -> elzero -> [e] Small
*/

bool capital_char (string str)
{
    size_t len = str.length();
    for (int i=0;i<len;i++) 
    {
        count = 0;
        if (i==0&&str[i]>=65&&str[i]<=90) count++;
        else if (str[i]==' '&&i+1!=len-1)
        {
            if (str[i+1]==' ')continue;
            else if (str[i+1]>='A'&&str[i+1]<='Z')count++;
        }
        else continue;
    }
    return count == Count_words(str);
}

int main ()
{
    cout<<Count_words("Hello word")<<endl;
    cout<<capital_char("Hello Elzero Web School");
    return 0;
}