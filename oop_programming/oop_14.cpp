//constant object and constant member function
#include <iostream>
using namespace std;
class Time
{
    private:
    int h, m, s;
    public:
    void print() const
    {
        cout << "The Time = " << h << " : " << m << " : " << s << endl;
    }
    Time(int hours, int minutes, int seconds)
    {
        h = (hours >= 0 && hours < 24) ? hours : 0;
        m = (minutes >= 0 && minutes < 60) ? minutes : 0;
        s = (seconds >= 0 && seconds < 60) ? seconds : 0;
    }
};
int main()
{
    const Time noon(12, 0, 0);
    noon.print();
    return 0;
}