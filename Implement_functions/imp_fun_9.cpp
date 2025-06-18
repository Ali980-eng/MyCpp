#include <iostream>
#include <vector>
using namespace std;
/*
    In Array -> In Container
    In_Array({1,2,3,4,5},5) -> True
    In_Array({1,2,3,4,5},6) -> False
*/
bool in_array(vector<int> vrr,int in = 0)
{
    for (int i=0;i<vrr.size();i++)
    if (vrr[i]==in) return true;
    return false;
}
/*
    Round
    Floor
    Ceil
*/
int Round(float x)
{
    float z = 0.0;
    for(float i = x;i>1;i--)  z = i-1;
    if (z<1&&z>0)
    {
        if (z>=0.5) x += (1-z);
        else  if (z<0.5)x -= z;
        else return 0.0;
    } 
    return x;
}
int Floor(float x)
{
    float z = 0.0;
    for(float i = x;i>1;i--)  z = i-1;
    return x -= z;
}
int Ceil(float x)
{
    float z = 0.0;
    for(float i = x;i>1;i--)  z = i-1;
    return x += (1-z);
}
int main()
{
    vector<int> vec = {12,23,43,56,76,78,98,0,44};
    //cout<<in_ary(vec,100);
    cout<<Round(15.98)<<endl;
    cout<<Round(10.19)<<endl;
    cout<<Floor(20.85)<<endl;
    cout<<Ceil(29.22);
    return 0;
}