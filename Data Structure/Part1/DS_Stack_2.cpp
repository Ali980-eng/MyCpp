#include <iostream>
using namespace std;
const int MaxSize = 100;
template <typename T>
class Stack {
    int top;
    T item[MaxSize];  // T can be int, double, string, etc.
    public:
    Stack() : top(-1) {}
    void push(T element) {
        if (top == MaxSize - 1) {
            cerr << "Stack full on push" << endl;
            return;
        }
        item[++top] = element;
    }
    bool isEmpty() {
        return top < 0;
    }
    void pop() {
        if (isEmpty()) {
            cerr << "Stack empty on pop" << endl;
            return;
        }
        top--;
    }
    void pop(T &element) {
        if (isEmpty()) cerr << "Stack empty on pop" << endl;
        else element = item[top--];
    }
    void getTop(T &stackTop) {
        if (isEmpty()) cerr << "Stack empty on get top" << endl;
        else stackTop = item[top];
    }
    void print() {
        for (int i = top;i>=0;--i) {
            if(i==top)cout<<" ["<<item[i]<<", ";
            else if(i==0) cout<<item[i]<<"] "<<endl;
            else cout<<item[i]<<", ";
        }
    }
};
int main() {
    // Stack of integers
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.print();  // Output: [10, 20, 30]
    // Stack of characters
    Stack<char> charStack;
    charStack.push('A');
    charStack.push('B');
    charStack.push('C');
    charStack.print();  // Output: [A, B, C]
    // Stack of strings
    Stack<string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    stringStack.print();  // Output: [Hello, World]
    return 0;
}