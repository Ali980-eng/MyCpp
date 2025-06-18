#include <iostream>
#include <fstream>
using namespace std;
/*  ios
    He has three sons.
    1-ostream. 
    2-istream. 
    3-fsreampas. 
    They inherited their qualities from the class:
    iostream
    We will use
    ostream istream
    They inherited the classics from her:
    ofstream ifstream
*/
int main()
{
    ofstream newFile,NewFile("newfile.txt");
    newFile.open("workFile.txt");
    newFile<<"hello in work file\n";
    newFile.close();
    if (newFile.is_open()&&NewFile.is_open()) cout<<"the two files is open"<<endl;
    else if (newFile.is_open()||NewFile.is_open()) cout<<"there are one file is open"<<endl;
    else cout<<"all file are closed"<<endl;
    NewFile.close();
    return 0;
}