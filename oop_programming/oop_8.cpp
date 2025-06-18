#include <iostream>
using namespace std;
class c {
    public:
    int x,y;
    char z;
    c(int a=0, int b=0) {
        x=a,y=b;
    }
    c(char c='a') {
        z=c;
    }
    void out(int a=0) {
        x=a;
        cout<<this->x+this->y<<endl;
    }
    void out(char c='b') {
        z=c;
        cout<<z<<endl;
    }
};
int main()
{

    return 0;
}