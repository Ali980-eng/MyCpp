#include <iostream>
#include <vector>
using namespace std;
/*
Generate Range Of Letters
this function converting the numbers of rang you choose to get the ascii value from the rang
for example if you choose the rang 65 to 67 it will print:
A = 65
B = 66
c = 67
*/

void Range(int ch1 = 65,int ch2 = 70)
{
    if (ch1>=33&&ch2<126)
    {
        do
        {
            cout<<char(ch1)<<" = "<<ch1<<endl;
            ch1++;
        } while (ch1<=ch2);
    }
    else return ;
}
/*
Get Minimum Number In Vector
*/
int mini(std::vector<int> &var)
{
    //{66,57,44,25,33,77,89,30};
    int mini_num = var[0];
    for (int i=0;i<var.size();i++)
    if (var[i]<mini_num) mini_num = var[i];
    return mini_num;
}
//Get sum of numbers in vector
double Vec_op (std::vector<int> &var,char oper = '+')
{
    int result = 1;
    for (int i=0;i<var.size();i++)
    {
    switch (oper)
    {
    case '+':result += var[i];
    break;
    case '-':result -= var[i];
    break;
    case '*':result *= var[i];
    break;
    case '/':result /= var[i];
    break;
    default: continue; break;
    }
    }
    return result;
}
int main()
{
    std::vector<int> var = {100,99,77,68,67,55,88};
    Range (1,133);
    return 0;
}