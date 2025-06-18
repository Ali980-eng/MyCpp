#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
//this object takes the information of a country
class country
{
    private:
    long int population;
    char name[20];
    long double GDP;
    short int Mili_rank;
    public:
    country()
    {
        population = pow(10,6);
        strcpy(name,"country");
        GDP =  pow(10,9);
        Mili_rank = 100;
    }
    country(string str)
    {
        if (str == "strongest")
        {
            population = 334.9*pow(10,6);
            strcpy(name,"Usa");
            GDP = 27.36*pow(10,12);
            Mili_rank = 1;
        }
        else if (str == "smallest")
        {
            population = 764;
            strcpy(name,"vatican city");
            GDP = 21198;
            Mili_rank = 195;
        }
    }
    ~country ()
    {
        cout<<"the country has been delete\n";
    }
    void setPopulation (long int num){population = num;}
    void setName (char n[]){strcpy(name,n);}
    void setGDP(long double num1){GDP=num1;}
    void setRank(short int R){Mili_rank=R;}
    int getPopulation(){return population;}
    char* getName(){return name;}
    double getGDP(){return GDP;}
    int getRank(){return Mili_rank;}
    void display() 
    {
        cout << "Country: " << name << endl;
        cout << "Population: " << population << endl;
        cout << "GDP: " << GDP << endl;
        cout << "Military Rank: " << Mili_rank << endl;
    }
};
int main()
{
    country cou1("strongest"),cou2("smallest");
    /*cou.setName("Japan");
    cou.setGDP(4.213*pow(10,9));
    cou.setPopulation(1245*pow(10,5));
    cou.setRank(8);
    cou.display();*/
    cou1.display();
    cou2.display();
    return 0;
}