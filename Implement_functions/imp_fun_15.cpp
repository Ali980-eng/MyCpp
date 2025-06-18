#include <iostream>
#include <vector>
using namespace std;
/*
    Replace String In Vector
    {"osama", "Ah", "Ali"} -> "Ah" -> "Ahmed"
*/
vector<string> Replace_str(vector<string> vrr,string repstr,string newstr,bool allrep = true,int count = 0)
{
    if (allrep)
    {
        for (int i=0;i<vrr.size();i++)
        {
        if (repstr==vrr[i]) vrr[i]=newstr;
        else continue;
        }
        return vrr;
    }
    else
    {
        vector<string> result;
        for (int i=0;i<vrr.size();i++)
        {
        if (repstr==vrr[i]&&count>0)
        {
            vrr[i]=newstr;
            count--;
        }
        else continue;
        }
        return vrr;
    }
}
//Generate Characters
string generateChars(bool caps = true, bool lows = false, bool nums = false)
{
  string result;

  if (caps)
  {
    for (int i = 65; i < 91; i++)
    {
      result += i;
    }
  }
  if (lows)
  {
    for (int i = 97; i < 123; i++)
    {
      result += i;
    }
  }
  if (nums)
  {
    for (int i = 48; i < 58; i++)
    {
      result += i;
    }
  }
  return result;
}
int main()
{
    vector<string> str = {"Osama","Ah","Ali","Ah","Ah"};
    vector<string> newstr = Replace_str(str,"Ah","Ahmed",false,2);
    for (int i=0;i<newstr.size();i++)
    {
       cout<<newstr[i];
       if(i!=newstr.size()-1) cout<<", ";
       else cout<<endl;
    }
    return 0;
}