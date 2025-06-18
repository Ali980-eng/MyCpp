#include <iostream>
using namespace std;
/*
    Clean String
    "Elzero//''00wed@#$School__--" -> Elzero00WebSchool__
*/
string clean (string str,bool inc_num = true)
{
    string cl_str = "";
    if (inc_num==true)
    for (int i=0;i<str.length();i++)
    {
        if ((str[i]>=97&&str[i]<=122)||(str[i]>=48&&str[i]<=57)||(str[i]>=65&&str[i]<=90))
        cl_str += str[i];
        else continue;
    }
    else
    for (int i=0;i<str.length();i++)
    {
        if ((str[i]>=97&&str[i]<=122)||(str[i]>=65&&str[i]<=90))
        cl_str += str[i];
        else continue;
    }
    return cl_str;
}
/*
    Parse String From Query String
    name=Osama&age=43&country=Egypt
    name : Osama
    age : 40
    country : Egypt
*/
string Parse(string str)
{
    string sp = "";
    for (int i=0;i<str.length();i++)
    {
        if (str[i] == '=') sp += " : ";
        else if (str[i] == '&')sp += '\n';
        else sp += str[i];
    }
    return sp;
}
int main ()
{
    cout<<clean("Elzero//''00wed@#$School__--",false)<<endl;
    cout<<Parse("name=Osama&age=43&country=Egypt");
    return 0;
}