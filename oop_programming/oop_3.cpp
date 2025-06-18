#include <iostream>
using namespace std;
/**
 * Hor ~~ It's short for horizontal
 * Dir ~~ It's short for Direction
 * Ver ~~ It's short for Vertical
 * Pos ~~ It's short for Position
 */
struct Distance
{
    //if it ture the positive Direction
    double Hor;
    bool Hor_Dir;
    double Ver;
    bool Ver_Dir;
};
Distance Total(Distance &Pos1,Distance &Pos2)
{
    Distance total;
    total.Hor = Pos1.Hor + Pos2.Hor;
    total.Ver = Pos1.Ver + Pos2.Ver;
    return total;
}
int main()
{
    Distance Pos1,Pos2,total;
    cout<<"Enter the horizontal distance for the 1st position:";
    cin>>Pos1.Hor;
    cout<<"Enter the horizontal distance for the 2nd position:";
    cin>>Pos2.Hor;
    cout<<"Enter the vertical distance for the 1st position:";
    cin>>Pos1.Ver;
    cout<<"Enter the vertical distance for the 2nd position:";
    cin>>Pos2.Ver;
    total = Total(Pos1,Pos2);
    cout<<"the total horizontal distance: "<<total.Hor<<endl;
    cout<<"the total vertical distance: "<<total.Ver<<endl;
    return 0;
}