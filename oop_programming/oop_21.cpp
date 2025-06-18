#include <iostream>
using namespace std;
class Student
{
    private:
    int id;
    public:
    void set_id(int id)
    {
        this->id = id;
    }
    void print_id()
    {
        cout<<"ID is: "<<id<<endl;
    }
};
int main()
{
    Student st;
    st.set_id(10);
    st.print_id();
    return 0;
}