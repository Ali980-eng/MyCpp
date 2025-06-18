#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int arr[10];
    int j = 0;
    for (int i = 0;i<10;i++)
    {
        j = i*10;
        arr[i] = j;
    }
    for (int i = 0;i<10;i++) cout<<arr[i]<<endl;
    ofstream fout("test.txt",ios::binary);
    fout.write(reinterpret_cast<char*>(arr),10*sizeof(int));
    fout.close();
    return 0;
}