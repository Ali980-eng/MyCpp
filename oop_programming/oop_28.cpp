/*
    Constructor and destructor
    operator = () member
    friends
*/
#include <iostream>
using namespace std;
class mother
{
private:
    /* data */
public:
    mother()
    {
        cout<<"mother\n";
    }
    mother (int age)
    {
        cout<<"mother age = "<<age<<endl;
    }
};
class daughter:public mother
{
private:
    /* data */
public:
    daughter()
    {
        cout<<"daughter\n";
    }
    daughter(int age)
    {
        cout<<"daughter = "<<age<<endl;
    }
};
class son:public mother
{
private:
    /* data */
public:
    son(int age):mother(age+18)
    {
        cout<<"son age = "<<age<<endl;
    }
};
int main ()
{
    daughter sara;
    son keen(10);
    return 0;
}