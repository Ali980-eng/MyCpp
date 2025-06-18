#include <iostream>
using namespace std;
/*
Trim [Left|Right] Characters
###Name### -> All -> Name
###Name### -> Left -> Name###
###Name### -> Right -> ###Name
*/
string Trim (string Name,char ch = ' ',string str = "All")
{
    string NewName = "";
    int i,len = Name.length();
    int last_count = 0,first_count = 0;
    for(i=0;i<len-1;i++)
    {
        if (Name[i] == ch) first_count++;
        else break;
    }
    for(i=len-1;i>=0;i--)
    {
        if (Name[i] == ch) last_count++;
        else break;
    }
    if (str == "Left")
    {
        for (i=first_count;i<len;i++)
        NewName += Name[i];
    }
    else if (str == "Right")
    {
        for (i=0;i<len-last_count;i++)
        NewName += Name[i];
    }
    else if (str == "All")
    {
        for (i=0;i<len-1;i++) 
        {
            if (Name[i]!=ch) 
            NewName+=Name[i];
        }
    }
    return NewName;
}
//Get sub string
string substr(string str,int start,int end,bool inc_end)
{
    string sudstr = "";
    int i=start;
    if (inc_end == true)
    {
    for (;i<=end;i++)
    sudstr += str[i];
    }
    else
    {
    for (;i<end;i++)
    sudstr += str[i];
    }
    return sudstr;
}
int main ()
{
    cout<<Trim("##ali####",'#',"Right")<<endl;
    cout<<substr ("Elzero wed school",0,8,true);
    return 0;
}