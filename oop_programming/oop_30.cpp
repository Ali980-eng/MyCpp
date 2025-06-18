/*
    Poly morphism
    pointer of the father pointing in the son but not the reverse
    pointers to base class
*/
#include <iostream>
using namespace std;
class CPolygon
{
    protected:
    int width, height;
    public:
    void set_values(int a, int b)
    {
        width = a;
        height = b;
    }
    /*pure virtual function:
    will chaning name of the class to abstract class. 
    when the class be abstract class we cannot make an object form it. 
    we can only make an pointers. 
    this is the pure virtual function ~> virtual int area(void) = 0;
    */
    //not pure virtual function
    virtual int area(void)
    {
        return(0); 
    }
    /* virtual: 
        the virtual will make the compiler see
        the other area function in the other class. 
        if you delete the keywode virtual the compiler
        will use the Polygon area function. 
    */
};
class CRectangle : public CPolygon
{
    public:
    int area(void) {return(width*height);}
};
class CTriangle : public CPolygon
{
    public:
    int area(void) {return (width*height)/2;}
};
int main()
{
    CRectangle rect;
    CTriangle trgl;
    CPolygon poly;
    CPolygon *p1, *p2, *p3;//here its Polymorphism
    p1 = &rect;
    p2 = &trgl;
    p3 = &poly;
    p1 -> set_values(4, 5);
    p2 -> set_values(8, 7);
    p3 -> set_values(0, 0);
    cout<<"area of the rectangle = "<<p1 -> area()<<endl;
    cout<<"area of the triangle = "<<p2 -> area()<<endl;
    cout<<"area of the polygon = "<<p3 -> area()<<endl;
    return 0;
}