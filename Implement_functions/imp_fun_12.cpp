#include <iostream>
#include <vector>
using namespace std;

/*
  Create Vector Range
  (5-12) -> {5,6,7,8,9,10,11,12}
  (3-5) -> {3,4,5}
*/

vector<int> createRange(int begin,int last,bool end = true)
{
    vector<int> result;
    if (end == true)
    {
        for (int i=begin;i<=last;i++)
        result.push_back(i);   
    }
    else
    {
        for (int i=begin;i<=last;i++)
        result.push_back(i);
    }
    return result;
}

/*
  String slice
  "Hello World" -> "Hello"
*/

string slice(string str, int start, int end, int step = 1, bool rev = false) 
{
    string result;
    // Ensure the provided indices are within valid range
    if (str.length() > end && start >= 0)
    {
        if (rev == false)
        {
            // Iterate forward from start to end, using the given step
            for (int i = start; i < end; i += step)
            result += str[i];
        }
        else
        {
            // Iterate backward from end to start, using the given step
            for (int i = end; i >= start; i -= step)
            result += str[i];
        }
    }
    else 
    return ""; // Return an empty string if indices are invalid
    return result;
}


int main()
{
    /*
    vector<int> vec = createRange (3,5);
    vector<int> vec = createRange (5,12);
    size_t size = vec.size();
    cout<<"\nthe new values:";
    for (int i=0;i<size;i++)
    {
        if (i!=size-1) cout<<vec[i]<<", ";
        else cout<<vec[i];
    }
    */
    cout<<endl<<slice("Hello, World",0,6);
    return 0;
}