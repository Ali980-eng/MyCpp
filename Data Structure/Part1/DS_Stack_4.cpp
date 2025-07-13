#include <iostream>
#include <string>
#include <stack>
using namespace std;
void NewLines(short num = 2) {
    for(int i = 0;i<num;i++)
    cout<<endl;
}
bool arePair(char open, char close) {
    if(open == '('&&close == ')') return true;
    else if(open == '{'&&close == '}') return true;
    else if(open == '['&&close == ']') return true;
    return false;
}
bool AreBalanced(string str) {
    if(str.empty()) {
        cerr<<"The string must have a value"<<endl;
        return false;
    }
    char hold;
    stack<char> s;
    for(char ele : str) {
        if(ele == '('||ele == '['||ele == '{') s.push(ele);
        else if(ele == ')'||ele == ']'||ele == '}') {
            if(s.empty()||!arePair(s.top(), ele)) return false;
            else s.pop();
        }
        else continue;
    }
    return s.empty();
}
int main() {
    NewLines(10);
    string expression;
    cout<<"Enter the expression: ";
    cin>> expression;
    cout<<"The expression is ";
    if(AreBalanced(expression)) cout<<"Balanced"<<endl;
    else cout<<"Not Balanced"<<endl;
    return 0;
}