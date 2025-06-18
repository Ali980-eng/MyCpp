#include <iostream>
using namespace std;
/*
zFill
150->00150
6500->06500
11350->11350
Example String -> "6500" -> length -> 4
Example Width -> 7
*/
string zFill (string &st,int &width,string fill = "0")
{
    int len = st.length(); // 4
    if (len<width)
    {
        for (int i=0;i<(width-len);i++)
        st = fill + st;
    }
    return st;
}
/*
Example for Reverse string:
name -> eman
*/
string Reverse (string str)
{
    string result;
    for (int i = str.length()-1 ; i>=0 ; i--)
    result += str[i];
    return result;
}
int main()
{
    
    int width,num;
    cout<<"to use the zFill function press 1"<<endl;
    cout<<"to use the Reverse function press 2"<<endl;
    cin>>num;
    if (num==1)
    {
        string st;
        cout<<"the string you want to zFill:"<<endl;
        cin>>st;
        cout<<"the width of the string:"<<endl;
        cin>>width;
        cout<<zFill(st,width)<<endl;    
    }
    else if (num==2)
    {
        string str;
        cout<<"the string you want to Reverse:"<<endl;
        cin>>str;
        cout<<Reverse(str);
    }
    else
    cout<<"the number you choose has no function"<<endl;
    return 0;
}