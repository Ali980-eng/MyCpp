#include <iostream>
#include <vector>
using namespace std;

/*
  Join Elements
  {"Elzero", "Web", "School"} -> "Elzero, wed, School"
  {"Elzero", "Web", "School"}, " | " -> "Elzero | Web | School"
*/

string Join(vector<string> vstr,string str = ", ")
{
    size_t svec = vstr.size();
    string result_str;
    for (int i=0;i<svec;i++)
    {
        result_str += vstr[i];
        if (i != svec-1) result_str += str;
    }
    return result_str;
}

/*
  Fill Container
  (5, "Elzero") -> {"Elzero","Elzero","Elzero","Elzero","Elzero"}
*/

vector<string> Fill(string str,short int count = 3)
{
    vector<string> vec_fill;
    for (int i=0;i<count;i++)
        vec_fill.push_back(str);
    return vec_fill;
}

int main()
{
    vector<string> vstr = {"Elzero", "Web", "School"};
    cout<<Join(vstr,"| ")<<endl;
    vstr = Fill("ali");
    for (string str : vstr) cout<<str<<"\t";
    return 0;
}