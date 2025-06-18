#include <iostream>
#include <vector>
using namespace std;
string R_s(string &s,int &n)
{
    string re_str="";
    while (n>0)
    {
        re_str+=s;
        n--;
    }
    return re_str;
}
string to_upper (string s)
{
    string new_str = "";
    for (int i=0;i<s.length();i++)
    {
        int ch_num = s.at(i);
        if (ch_num>=97&&ch_num<=122)
        new_str += char(ch_num-32);
        else new_str += char(ch_num);
    }
    return new_str;
}
string to_lower (string s)
{
    string new_str = "";
    for (int i=0;i<s.length();i++)
    {
        int ch_num = s.at(i);
        if (ch_num>=65&&ch_num<=90)
        new_str += char(ch_num+32);
        else new_str += char(ch_num); 
    }
    return new_str;
}
string swap_case (string s)
{
    string new_str = "";
    for (int i=0;i<s.length();i++)
    {
        int ch_num = s.at(i);
        if (ch_num>=97&&ch_num<=122)
        new_str += char(ch_num-32);
        else if (ch_num>=65&&ch_num<=90)
        new_str += char(ch_num+32);
        else continue;
    }
    return new_str;
}
int main()
{
    int n;
    string s;
    /*cout<<"the name you want to repeat:"<<endl;
    cin>>s;
    cout<<"the number of repeats for the name:"<<endl;
    cin>>n;*/
    cout<<to_lower("LAFI")<<endl;
    cout<<to_upper("ali")<<endl;
    cout<<swap_case("ALi5");
    return 0;
}