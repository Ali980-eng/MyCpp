#include <iostream>
#include <string>
using namespace std;
bool str_end(const string &str, const string &ending) 
{
    if (ending.size() > str.size()) return false;
    int str_pos = str.size() - 1;
    int end_pos = ending.size() - 1;
    while (end_pos >= 0) 
    {
        if (str[str_pos] != ending[end_pos])
        {
            return false;
        }
        str_pos--;
        end_pos--;
    }
    return true;
}
int main()
{
    string str, ending;
    cout << "Enter the string: ";
    cin >> str;
    cout << "Enter the test end string: ";
    cin >> ending;
    cout << endl << str_end(str, ending);
    return 0;
}