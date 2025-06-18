#include <iostream>
#include <cstring>
using namespace std;
//define how many object create
class Student
{
    private:
    static int count;
    char name[20];
    int first, second, final, total, ID;
    public:
    Student() //constructor
    {
        strcpy(name, "No name");
        ID = 0;
        first = second = final = 0;
        count++;
        print_count();
    } 
    static void print_count()
    {
        cout<<"Students constructed: "<<count<<endl;
    }
}; //end of class
int Student::count = 0;
int main()
{
    cout<<"\nConstruct 2 objects\n";
    Student s1,s2;
    cout<<"\nConstruct 3 objects\n";
    Student st[3];
    //Student::print_count() ~~> or s1.print_count()
    return 0;
} // end of main