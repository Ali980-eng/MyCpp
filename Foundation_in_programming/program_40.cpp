//lesson 40 
#include <iostream> 
using namespace std; 
int main () 
{ 
    int IQ = 0; 
    int answers[6]; 
    cout <<"type the Missing Number in sequences:\n"; 
    cout<<"sequence 1\n"; 
    cout<<"2,4,6,8,10,??\n"; 
    cin>>answers[0]; 
    cout<<"sequence 2\n"; 
    cout<<"1,3,5,7,9,??\n"; 
    cin>>answers[1]; 
    cout<<"sequence 3\n"; 
    cout<<"99,199,299,399,499,??\n"; 
    cin>>answers[2]; 
    cout<<"sequence 4\n"; 
    cout<<"3,-5,7,-9,11,??\n"; 
    cin>>answers[3]; 
    cout<<"sequence 5\n"; 
    cout<<"1,4,9,16,25,??\n"; 
    cin>>answers[4]; 
    cout<<"sequence 6\n"; 
    cout<<"0,2,6,12,20,??\n"; 
    cin>>answers[5]; 
    int sequence [6][6] 
    { 
        {2,4,6,8,10,12}, 
        {1,3,5,7,9,13}, 
        {99,199,299,399,499,599}, 
        {3,-5,7,-9,11,-13}, 
        {1,4,9,16,25,36}, 
        {0,2,6,12,20,30} 
    }; 
    if (answers[0]==sequence[0][5]) 
    { 
        IQ+=20; 
    } 
    if (answers[1]==sequence[1][5]) 
    { 
        IQ+=20; 
    } 
    if (answers[2]==sequence[2][5]) 
    { 
        IQ+=20; 
    } 
    if (answers[3]==sequence[3][5]) 
    { 
        IQ+=50; 
    } 
    if (answers[4]==sequence[4][5]) 
    { 
        IQ+=20; 
    } 
    if (answers[5]==sequence[5][5]) 
    { 
        IQ+=50; 
    } 
    cout<<"your IQ is:"<<IQ<<endl; 
    return 0; 
} 