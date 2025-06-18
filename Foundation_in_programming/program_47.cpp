//lesson47 
#include <iostream> 
using namespace std; 
int main() 
{ 
    int nums[]={10,99,88,66,79,-50,97,22,-78,-12,68,99,100,-199,-77}; 
    int a_s = sizeof(nums)/sizeof(nums[0]); 
    cout<<"the size of the array="<<a_s<<endl; 
    cout<<"the sum of all even and postive number:"<<endl; 
    int even; 
    double sum; 
    for (int i=0;i<a_s;i++) 
    { 
        even=nums[i]%2; 
        if (even==0&&nums[i]>=0) 
        { 
            cout<<nums[i]; 
            if (even==0&&nums[i]>=0&&i<12) 
            cout<<"+"; 
            sum+=nums[i]; 
        } 
    } 
    cout<<"="<<sum; 
    return 0; 
} 