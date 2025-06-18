//lesson 26 
#include <iostream> 
using namespace std; 
int main () 
{ 
    int num; 
    cout<<"to use the current law press 1"<<endl; 
    cout<<"to use the ohm's law press 2"<<endl; 
    cout<<"to use the voltage law press 3"<<endl; 
    cin>>num;     
    if (num==1) 
    { 
        float q,t,i; 
        cout<<"Enter the value of charge:"<<endl; 
        cin>>q; 
        cout<<"Enter the value of time:"<<endl; 
        cin>>t; 
        i=(q)/(t); 
        cout<<"the current value ="<<i<<endl; 
        return 0; 
    } 
    if (num==2) 
    { 
        float R,l,p,a; 
        cout<<"Enter the value of cross-sectional area"<<endl; 
        cin>>a; 
        cout<<"Enter the value of length"<<endl; 
        cin>>l; 
        cout<<"Enter the value of resistivity"<<endl; 
        cin>>p; 
        R=(p*l)/a; 
        cout<<"the value of the resistor="<<R<<endl; 
    } 
    if (num==3) 
    { 
        float V, R, I; 
        cout<<"Enter the value of current"<<endl; 
        cin>>I; 
        cout<<"Enter the value of resistor"<<endl; 
        cin>>R; 
        V=R*I; 
        cout<<"the value of voltage"<<V<<endl; 
        return 0; 
    } 
    return 0; 
} 