#include<iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
void foo(int x) {
    cout<<x<<"  ";
}
int main() {
    cout<<endl<<endl<<endl;
    function<void(int)> f1 = foo;
    for(int i = 10;i<=20;i++) f1(i);
    cout<<endl;
    function<void(int)> f2 = [](int x) {cout<<x<<"  ";};
    for(int i = 10;i<=20;i++) f2(i);
    cout<<endl;
    struct S {
        void operator()(int x) {
            cout<<x<<"  ";
        }
    };
    S s;
    function<void(int)> f3 = s;
    for(int i = 10;i<=20;i++) f3(i);
    return 0;
}