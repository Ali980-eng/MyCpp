#include <iostream>
#include <cstring>
using namespace std;
class Student
{
    private:
    char name[20];
    int ID;
    public:
    Student()
    {
        strcpy(name,"No name");
        ID = 0;
    }
    Student(char n[],int id)
    {
        strcpy(name,n);
        ID = id;
    }
    ~Student()
    {
        cout<<' ';
    }
    void print()
    {
        cout<<"name: "<<name<<"\t"<<"ID: "<<ID<<endl;
    }
};
int main()
{
    /* V.I.N: the array is constant pointer
    because of that we can not make on it:
    (post increment and pre increment)
    or
    (post discrement and pre discrement)
    */
    int arr[5] = {77,89,87,66,10};
    //cout<<"the address of the first element: "<<arr<<endl;
    //cout<<"the value of the first element: "<<*arr<<endl;
    //if we used the (*) sign the compiler will get the value not the address
    //cout<<"the address of the secend element: "<<arr+1<<endl;
    //cout<<"the value of the secend element: "<<*(arr+1)<<endl;
    //the address of any element will follow the formula (arr+index)
    for(int i=0;i<5;i++)
    {
        cout<<"arr"<<i<<" = "<<*(arr+i)<<endl;
        cout<<"&arr"<<i<<" = "<<(arr+i)<<endl;
    }
    int *p;
    p = arr; //or p = &arr[0]
    for(int j=0;j<5;j++)
    {
        cout<<"p"<<j<<" = "<<*(p+j)<<endl;
        cout<<"&p"<<j<<" = "<<(p+j)<<endl;
    }
    Student stu1("ali lafi",778935),stu2("ahmad",645897),stu3("adel",145067);
    //stu1.print();
    //stu2.print();
    Student Sarr[3] = {stu1,stu2,stu3};
    for (int i1=0;i1<3;i1++) Sarr[i1].print();
    return 0;
}