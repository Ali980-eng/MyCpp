#include <iostream>
using namespace std;
template<class T>
class stack {
    private:
    struct node {
        T item;
        node* next;
    };
    node *top, *cur;
    public:
    stack() {
        top = nullptr;
    }
    void push(T newItem) {
        node* NewItemPtr = new node;
        if(NewItemPtr == nullptr) cerr<<"Stack push cannot allocat memory"<<endl;
        else {
            NewItemPtr -> item = newItem;
            NewItemPtr -> next = top;
            top = NewItemPtr;
        }
    }
    bool isEmpty() {
        return top == nullptr;
    }
    void pop() {
        if(isEmpty()) cerr<<"Stack empty on pop"<<endl;
        else {
            node *temp = top;
            top = top -> next;
            temp = temp -> next = nullptr;
            delete temp;
        }
    }
    void pop(T &stackTop) {
        if(isEmpty()) cerr<<"Stack empty on pop"<<endl;
        else {
            stackTop = top -> item;
            node* temp = top;
            top = top -> next;
            temp = temp -> next = nullptr;
            delete temp;
        }
    }
    void getTop(T &stackTop) {
        if(isEmpty()) cerr<<"Stack empty on pop"<<endl;
        else stackTop = top -> item;
    }
    void display() {
        cur = top;
        while(cur != nullptr) {
            cout<<cur -> item<<endl;
            cur = cur -> next;
        }
    }
};
int main() {
    cout<<endl<<endl;
    stack<int> s;
    s.push(100);
    s.push(200);
    s.push(300);
    s.pop();
    s.display();
    return 0;
}