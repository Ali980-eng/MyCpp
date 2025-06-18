//lesson 18 
#include <iostream>  
using namespace std;  
int main ()  
{ 
  int num; 
  cout<<"to use the magnetic field intensity law Press 1\n"; 
  cout<<"to use the law of permeability Press 2\n"; 
  cout<<"to use the magnetic flux density law Press 3\n"; 
  cout<<"to use the flux density law Press 4\n"; 
  cin>>num; 
  float H,i,n,l,M,m_r,B,A,F;
    if(num==1) 
    { 
        cout<<"the number of turns is:"<<endl; 
        cin>>n;  
        cout<<"the current is:"<<endl;  
        cin>>i;  
        cout<<"the leangh of the core:"<<endl;  
        cin>>l;  
        H=((i*n)/l);  
        cout<<"The magnetic field intensity ="<<H<<endl;  
    } 
    if(num==2) 
    { 
        cout<<"the permeability of the magnetic material:"<<endl;  
        cin>>m_r;  
        M=(m_r*22)/ (10000000); 
        cout<<M; 
    } 
    if(num==3) 
    { 
        cout<<"The magnetic field intensity is:"; 
        cin>>H; 
        cout<<"the M is:"; 
        cin>>M; 
        B=M*H;  
        cout<<"the magnetic flux density ="<<B<<endl;  
    } 
    if(num==4) 
    { 
        cout<<"the magnetic flux density is:"; 
        cin>>B; 
        cout<<"the cross section is:"<<endl;  
        cin>>A; 
        F=A*B;  
        cout<<"the flux density ="<<F<<endl; 
    } 
  return 0;  
} 