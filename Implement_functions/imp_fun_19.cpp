#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <type_traits>
using namespace std;
int numDIN(const vector<int>& vec)
{
    int sum = 0;
    if (vec.size() < 1) return 0;
    for (size_t i=1;i<vec.size();i++)
    {
        sum += (vec[i-1]-vec[i]);
    }
    return sum;
}
template <typename T>
bool isChar(T element) {
    return (element >= 'a' && element <= 'z') || (element >= 'A' && element <= 'Z');
}
template <typename Container, typename Element>
auto EleRemover(Container container, Element element) -> typename enable_if<is_same<Container, string>::value && is_same<Element, char>::value, string>::type {
    string result, substr;
    for (char ch : container) {
        if (ch == element) {
            result += substr;
            substr.clear();
        }
        else substr += ch;
    }
    return result;
}
template <typename Container, typename Element>
auto EleRemover(Container container, Element element) -> typename enable_if<is_same<Container, vector<Element>>::value, vector<Element>>::type {
    vector<Element> result;
    for (Element item : container) {
        if (item != element)
        result.push_back(item);
    }
    return result;
}
int main()
{
    /*int num = 0;
    vector<int> vec;
    size_t num_size;
    cout<<"Enter the number of values:";
    cin>>num_size;
    cout<<"Enter the values of the vector:"<<endl;
    for (size_t i=0;i<num_size;i++)
    {
        cout<<"the value in index "<<i<<" = ";
        cin>>num;
        vec.push_back(num);
    }
    cout<<numDIN(vec);*/
    cout<<endl<<endl;
    vector<int> IntNumVec = {77, 89, 0, 88, 56, 66, 43, 2, 37};
    vector<double> DouNumVec = {1.7, 18.9, 7.01, 8.8, 3.3, 2.3};
    string str = "my name is";
    IntNumVec = EleRemover(IntNumVec, 0);
    DouNumVec = EleRemover(DouNumVec, 18.9);
    str = EleRemover(str, 'n');
    int index = 0;
    for(index=0;index<DouNumVec.size();index++) {
        if(index==0) cout<<" ["<<DouNumVec[index]<<", ";
        else if(index==DouNumVec.size()-1) cout<<DouNumVec[index]<<"] "<<endl;
        else cout<<DouNumVec[index]<<", ";
    }
    for(index=0;index<IntNumVec.size();index++) {
        if(index==0) cout<<" ["<<IntNumVec[index]<<", ";
        else if(index==IntNumVec.size()-1) cout<<IntNumVec[index]<<"] "<<endl;
        else cout<<IntNumVec[index]<<", ";
    }
    for(index=0;index<str.length();index++) {
        if(index==0) cout<<" ["<<str[index]<<", ";
        else if(index==str.size()-1) cout<<str[index]<<"] "<<endl;
        else cout<<str[index]<<", ";
    }
    return 0;
}