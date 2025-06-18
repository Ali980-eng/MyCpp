#include <iostream>
using namespace std;
class CRectangle
{
    private:
    float area;
    int *width, *height;
    public:
    CRectangle()
    {
        width = new int;
        height = new int;
        *width = 10;
        *height = 5;
        area = 0.5*(*width)*(*height);
    }
    CRectangle(int y,int x)
    {
        width = new int;
        height = new int;
        *width = x;
        *height = y;
        area = 0.5*(*width)*(*height);
    }
    ~CRectangle()
    {
        delete width;
        delete height;
    }
    void print()
    {
        cout<<"width= "<<*width<<endl;
        cout<<"height= "<<*height<<endl;
        cout<<"area= "<<area<<endl;
    }
};

int main()
{
    CRectangle rec1(3,3);
    rec1.print();
    return 0;
}
