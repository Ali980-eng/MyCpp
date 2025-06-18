#include <iostream>
using namespace std;
class Csquare;
class Crectangle
{
    private:
    int width, height;
    public:
    int area(void) {return (width*height);}
    void convert(Csquare);
};
class Csquare
{
    private:
    int side;
    public:
    void set_side(int x) {side = x;}
    friend class Crectangle;
};
void Crectangle::convert(Csquare a)
{
    width = a.side;
    height = a.side;
}
int main()
{
    Csquare sqr;
    Crectangle rect;
    sqr.set_side(4);
    rect.convert(sqr);
    cout<<rect.area()<<endl;
    return 0;
}