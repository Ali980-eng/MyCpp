#include <iostream>
#include <cstring>
using namespace std;
struct exam
{
    float first;
    float second;
    float final;
};
class subject
{
private:
    char name[10];
    exam Exam;
public:
    subject()
    {
        strcpy(name,"no name");
        Exam = {0,0,0};
    }
    subject (char n[],float fir_ex,float sec_ex,float fin_ex)
    {
        strcpy(name,n);
        Exam = {fir_ex,sec_ex,fin_ex};
    }
    ~subject()
    {
        cout<<"the subject are deleted"<<endl;
    }
    void print()
    {
        cout<<"The subject: "<<name<<endl;
        cout<<"First Exam: "<<Exam.first<<endl;
        cout<<"Second Exam: "<<Exam.second<<endl;
        cout<<"Final Exam: "<<Exam.final<<endl;
    }
};
int main()
{
    subject sub1("ali lafi",21,14,48);
    sub1.print();
    return 0;
}