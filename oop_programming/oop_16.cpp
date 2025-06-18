#include <iostream>
using namespace std;
class CRectangle
{
private:
    int width, height;
    friend CRectangle duplicate(CRectangle);
public:
    void Set_values(int,int);
    int area(void) {return (width*height);}
};//End of class def.
void CRectangle::Set_values(int a, int b)
{
    width = a;
    height = b;
}
CRectangle duplicate(CRectangle R)
{
    CRectangle T;
    T.width = R.width * 2;
    T.height = R.height * 2;
    return T;
}
int main()
{
    CRectangle rect, rectb;
    rect.Set_values(2, 3);
    cout<<"The area befor duplicate = "<<rect.area()<<endl;
    rectb = duplicate(rect);
    cout<<"The area after duplicate = "<<rectb.area()<<endl;
    return 0;
}