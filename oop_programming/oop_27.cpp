#include <iostream>
using namespace std;
class base
{
    private:
    int i;
    protected:
    int h;
    public:
    int j, k;
    void seti (int x)
    {
        i=x;
    }
    int geti ()
    {
        return i;
    }
};
class derived : private base
{
    private:
    /* all function and bata types declared
     in base will Inheritance for private in derived*/
    public:
    base :: j; //this make the pirvate inheritance to public
    base :: seti;
    base :: geti;
    base :: h;
    //base :: i; // ~~> illegal, you cannot elevate access
    int a;
};
int main()
{
    derived ob;
    ob.j = 20;
    ob.a = 40;
    ob.seti(10);
    cout<<ob.geti()<<' ';
    cout<<ob.j<<' '<<ob.a<<endl;
    return 0;
}