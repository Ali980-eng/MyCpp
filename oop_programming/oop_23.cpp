/*
    Overloading a relational operator
    overloaded operator function usually returns an object of the
    an overloaded relational operator typically returns a true or false value
*/
#include <iostream>
using namespace std;
class Relational
{
    private:
    int x, y, z;
    public:
    Relational()
    {
        x = y = z = 0;
    }
    Relational(int i, int j, int k)
    {
        x = i;
        y = j;
        z = k;
    }
    bool operator== (Relational b)
    {
        return (x == b.x)&&(y == b.y)&&(z == b.z);
    }
};
int main()
{
    Relational a(10, 10, 10), b(10, 10, 10);
    if (a == b) cout<<"The two objects are equal\n";
    else cout<<"The two objects are not equal\n";
    Relational r(1, 2, 5), e(7, 3, 4);
    if (r == e) cout<<"The two objects are equal\n";
    else cout<<"The two objects are not equal\n";
    return 0;
}