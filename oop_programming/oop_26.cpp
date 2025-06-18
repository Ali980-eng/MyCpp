/*  Inheritance
    the benefit of concept
    reyouzabilate
    base class ~~> derived class
    super class ~~> sub class
    member private can access from the same class
    member protected can access from the derived class and at the same class
    member public can access from any where
*/
#include <iostream>
using namespace std;
class CPolygon
{
    protected:
    int width, height;
    public:
    void set_values (int a, int b)
    {
        width=a;
        height=b;
    }
};
class CRectangle : public CPolygon
{//here this is Inheritance
    protected:
    // the class Inheritance the intgers for CPolygon width and height
    public:
    // the class Inheritance the function set_values
    int area()
    {
        return (width*height);
    }
};
class CTriangle : public CPolygon
{//the same Inheritance in CRectangle
public:
    int area()
    {
        return (width*height)/2;
    }
};
int main()
{
    CRectangle rect;
    CTriangle trgl;
    rect.set_values(4,5);
    trgl.set_values(4,5);
    cout<<rect.area()<<endl;//20
    cout<<trgl.area()<<endl;//10
    return 0;
}
/*
    CPolygon::width ~~> protected access
    CRectangle::width ~~> protected access
    CPolygon::set_values() ~~> public access
    CRectangle::set_values() ~~> public access
*/