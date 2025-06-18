/* this
 this definition:
 is a pointer is pointing in the object that calls the function.
*/
#include <iostream>
using namespace std;
class stud
{
    private:

    public:
    void address() {cout<<this;}
};
int main()
{
    stud a, b, c;
    cout<<"The address of a: ";
    a.address();
    cout<<endl<<"The address of b: ";
    b.address();
    cout<<endl<<"The address of c: ";
    c.address();
    cout<<endl;
    return 0;
}