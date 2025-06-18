//lesson 43 
#include <iostream>  
using namespace std;  
int main()  
{  
    int a,num,even,sum;  
    cin>>a>>num>>sum;  
    even=a%2;  
    if(even==0)  
    {  
        num+=1;  
        for(int i=1;i<=100;i+=2)  
        {  
            num+=2;  
            sum+=num;  
        }  
    }  
    else if (even!=0)  
    {  
        for(int j=1;j<=100;j+=2)  
        {  
            num+=2;  
            sum+=num;  
        }  
    }  
    cout<<"the sum of all odd numbers="<<sum;  
    return 0;  
} 