#include <iostream>
using namespace std;
void sum(int a1[],int a2[])
{
    int temp[2];
    temp[0]=a1[0]+a2[0];
    temp[1]=a1[1]+a2[1];
    cout<<temp[0]<<' '<<temp[1]<<' ';
    a1[0]=22;
}
int sub1 (int c)
{
    return 0;
}

int main()
{
    int x=7,y=6,z=5;
    (x>y>z)?cout<<(x+=2),cout<<x:cout<<x;
    int n=4;
    switch(n)
    {
        case 1:cout<<(!n);break;
        case 4:cout<<(n&&4)<<(n||4);
        default:cout<<(n=4)<<(n==4)<<" ";
    }
    int x1[2]={0,17};
    int y1[2]={0,1};
    sum(x1,y1);
    cout<<x1[0];
    return 0;
}



/* -> [main] <-

-------------------------------------------

-------------------------------------------
    int x[3]={-2,1,4};
    float y[3];
    int i=0;
    y[i]=++x[i++];
    y[i]=x[i]/2;
    y[i+1]=y[i-1];
-------------------------------------------
    int x=1;
    while(x)
    {
        for(int i=x--;i>=1;i--)
        cout<<i<<x;
        cout<<"*";
    }
-------------------------------------------
    int x=0,y=0;
    if (y||--x>10) cout<<x+5;
    else if (x==1) cout<<x;
    else cout<<!x;
-------------------------------------------
    int b=4;
    sub1(b);
-------------------------------------------
    int x[2][2]={{1},{3}};
    int s=0;
    for(int i=0;i<2;i++)
    s+=x[i][i];
    cout<<s;
-------------------------------------------
    int i=2,s=2;
    while(i++<6)
    {
        s+=i-2;
        cout<<s<<' ';
    }
-------------------------------------------
    const int a=7;
    int b=(++a)*(a++);
    cout<<a<<b;
*/