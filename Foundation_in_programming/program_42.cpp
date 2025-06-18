//lesson 42 
#include <iostream> 
using namespace std; 
int main() 
{ 
    int nums[]={100,200,300,400,500,600,700}; 
    int numsSize = sizeof(nums)/sizeof(nums[0]); 
    /*for (int i=0;i<numsSize;i++) 
    { 
        if (i%2==0) 
        cout<<nums[i]<<endl; 
    }*/ 
    for (int i=0;i<numsSize;i++) 
    { 
        if (i>=2) 
        cout<<nums[i]<<endl; 
    } 
    return 0; 
} 