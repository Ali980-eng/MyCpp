#include <iostream>
#include <cstring>
using namespace std;
class phone
{
    private:
    char model[10];
    char brand[10];
    double price;
    public:
    phone()
    {
        strcpy(model,"nothing");
        strcpy(brand,"nothing");
        price = 0.0;
    }
    phone(string str)
    {
        if (str == "expensive")
        {
            strcpy(model,"iphone");
            strcpy(brand,"Apple");
            price = 1299.0;
        }
    }
    ~phone()
    {
        cout<<brand<<' '<<model<<' '<<"the phone is deleted\n";
    }
    void set_model(char u[]) {strcpy(model,u);}
    void set_brand (char n[]) {strcpy(brand,n);}
    void set_price (double a) {price=a;}
    char* get_model() {return model;}
    char* get_brand() {return brand;}
    double get_price() {return price;}
    void display()
    {
        cout<<"the model: "<<model<<endl;
        cout<<"the brand: "<<brand<<endl;
        cout<<"the price: "<<price<<endl;
    }
};
int main()
{
    phone ph1("expensive");
    ph1.display();
    return 0;
}