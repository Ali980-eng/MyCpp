#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream adelFile("sfile.txt");
    cout<<"Enter the student status\n";
    cout<<"Press ctrl+z to exit\n";
    char name[10];
    int id;
    while (cin>>name>>id)
    {
        adelFile<<name<<' '<<id<<endl;
    }
    return 0;
}