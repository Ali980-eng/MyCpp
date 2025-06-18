#include <iostream>
#include <vector>
using namespace std;
class cexception
{
 private:
    vector<int> num;
 public:
    cexception()
    {
        for(int i = 0;i<100;i++) num.push_back(i);
    }
    int getElement(int x)
    {
        if (x>=100) throw xBig();
        else if (x<0) xSmall();
        else return num[x];
    }
    class xBig {
        public:
        xBig() {}
        void big()
        {
            cout<<"Big number\n";
        }
    };
    class xSmall {
        public:
        xSmall(){}
        void small()
        {
            cout<<"small number\n";
        }
    };
};
int main()
{
    int i = 0;
    cexception a;
    try
    {
        cout<<"Choise The element : ";
        cin>>i;
        cout<<"The element : "<<a.getElement(i)<<endl;
    }
    catch (cexception::xSmall s)
    {
        s.small();
    }
    catch (cexception::xBig b)
    {
        b.big();
    }
    return 0;
}