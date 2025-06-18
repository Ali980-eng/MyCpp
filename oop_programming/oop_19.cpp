#include <iostream>
#include <string>
using namespace std;
class triangle
{
private:
    float width, height;
    friend float area(triangle);
public:
    triangle(float a = 0, float b=0)
    {
        width = a;
        height = b;
    }
    
    void getdata()
    {
        cout<<"Enter width\n";
        cin>>width;
        cout<<"Enter height\n";
        cin>>height;
    }
    void showdata()
    {
        cout<<"width = "<<width<<endl;
        cout<<"height = "<<height<<endl;
    }
    /*void add (triangle c1,triangle c2)
    {
        width=c1.width+c2.width;
        height=c1.height+c2.height;
    }*/
    triangle operator + (triangle c)
    {
        triangle result;
        result.width = width + c.width;
        result.height = height + c.height;
        return result;
    }
    triangle operator - (triangle c)
    {
        triangle result;
        result.width = width - c.width;
        result.height = height - c.height;
        return result;
    }
};
float area(triangle tri) {return tri.width*tri.height;}
int main()
{
    triangle c1,c2(3.5,1.5),c3;
    c1.getdata();
    c3=c1-c2;//binary operator
    c3.showdata();
    //c1++ ~~> unary operator
    cout<<"the area: "<<area(c3);
    return 0;
}