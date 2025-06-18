#include <iostream>
#include <vector>
using namespace std;

//Parse Integer From String
/*
for example : "He110" -> Integer: 110
*/
int P_I (std::string str)
{
    int result = 0;
    for (int i=0;i<str.length();i++)
    {
        int ch_num = str.at(i);
        if (ch_num>=48&&ch_num<=57)
        result = result * 10 +(str.at(i)-'0');
        else continue;
    }
    return result;
}
// isNaN -> Is Not A Number
/*
    for example:
    "123G4" -> Is Not A Number -> True
    "1234" -> Is Number -> False
*/
bool isNaN (string str)
{
    int count=0;
    for (int i=0;i<str.length();i++)
    {
        int ch_num = str.at(i);
        if (ch_num>=48&&ch_num<=57) count++;
        else continue;
    }
    if (str.length()==count) return false;
    else return true;
}
int main()
{
    cout<<isNaN("1220")<<endl;
    cout<<isNaN("He110")<<endl;
    return 0;
}