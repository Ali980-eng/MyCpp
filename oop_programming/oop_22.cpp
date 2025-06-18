//Unary operator
#include <iostream>
using namespace std;
class Unary
{
    private:
    long int x,y;
    public:
    Unary (int i=0,int j=0)
    {
        x=i;
        y=j;
    }
    void show()
    {
        cout<<"x = "<<x<<endl;
        cout<<"y = "<<y<<endl;
    }
    Unary operator++ ()
    {
        x++;
        y++;
        return *this;
    }
    Unary operator-- ()
    {
        x--;
        y--;
        return *this;
    }
    Unary operator++(int)
    {
        Unary t = *this;
        x++;
        y++;
        return t;
    }
    Unary operator--(int)
    {
        Unary t = *this;
        x--;
        y--;
        return t;
    }
    Unary operator- ()
    {
        x = -x;
        y = -y;
        return (*this);
    }
    Unary operator!()
    {
        for (int i = x-1;i>1;i--) x *= i;
        for (int j = y-1;j>1;j--) y *= j;
        return *this;
    }
};
int main()
{
    Unary v(7,10),k;
    k = v++;
    k.show();
    k = v--;
    k.show();
    k = v;
    k.show();
    //-k;
    //k.show();
    !k;
    k.show();
    return 0;
}