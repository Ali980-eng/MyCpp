//Friend Operator Functions
#include <iostream>
using namespace std;
class binary
{
    private:
    int x, y;
    
    public:
    binary (int a=0, int b=0)
    {
        x = a;
        y = b;
    }
    binary operator + (binary c2)
    {
        binary c3;
        c3.x = x + c2.x;
        c3.y = y + c2.y;
        return c3;
    }
    binary operator + (int num)
    {
        binary c3;
        c3.x = x + num;
        c3.y = y + num;
        return c3;
    }
    void print()
    {
        cout<<x<<','<<y<<endl;
    }
    friend binary operator+ (int, binary);
};
binary operator+ (int num, binary r)
{
    binary result;
    result.x = r.x + num;
    result.y = r.y + num;
    return result;
}
int main()
{
    binary c1(3, 1), c2(1, 2), c3;
    c3 = c1 + c2;
    c3.print();
    c3 = c1 + 10;
    c3.print();
    c3 = 10 + c1;
    c3.print();
    return 0;
}