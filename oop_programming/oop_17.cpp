#include <iostream>
using namespace std;
class Tri;
class CRectangle
{
    private:
    int width, height;
    public:
    void set_values(int a, int b) {width=a,height=b;}
    friend int Sum(Tri,CRectangle);
};
class Tri
{
    private:
    int W, H;
    public:
    Tri(int a, int b) {W=a,H=b;}
    friend int Sum(Tri,CRectangle);
};
int Sum(Tri T,CRectangle R) {return T.W+R.width;}
int main()
{
    CRectangle r;
    r.set_values(2,3);
    Tri l(5,10);
    cout<<Sum(l,r)<<endl;
    return 0;
}