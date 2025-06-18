#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int arr[20];
    int i=0;
    ifstream fin("test.txt", ios::binary);
    fin.read((char*)&arr, 10*sizeof(int));
    for (i=10;i<20;i++) arr[i]=i*10;
    for (i=0;i<20;i++) cout<<arr[i]<<endl;
    fin.close();
    return 0;
}