#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define Pi 3.14159
/*1. Write a C++ program to implement a class called Circle that has private member variables for radius.
Include member functions to calculate the circle's area and circumference.*/
/*class Circle {
    private:
    double radius = 0;
    public:
    void set_radius(int Radius) {
        radius = Radius;
    }
    double circumference() {
        if(radius) return (2*Pi*radius);
        else cout<<"you have set the value of radius of the circle"<<endl;
        return 0;
    }
    double area() {
        if(radius) return (Pi*pow(radius, 2));
        else cout<<"you have to set the value of radius for the circle"<<endl;
        return 0;
    }
    double get_radius() {return radius;}
};*/
/*2. Write a C++ program to create a class called Rectangle that has private member variables for length and width.
Implement member functions to calculate the rectangle's area and perimeter.*/
/*class Rectangle {
    private:
    double high, width;
    public:
    void set_values(double H, double W) {
        high = H;
        width = W;
    }
    double area() {return (*high*width);}
};*/
/*3. Write a C++ program to create a class called Person that has private member variables for name, age and country.
Implement member functions to set and get the values of these variables.*/
/*class Person {
    private:
    string Name;
    int Age;
    string Country;
    public:
    void set_values(string name, int age, string country) {
        Name = name;
        Age = age;
        Country = country;
    }
    string get_name() {return Name;}
    string get_country() {return Country;}
    int get_age() {return Age;}
    void Print_Values() {
        cout<<"Name : "<<Name<<endl;
        cout<<"Age : "<<Age<<endl;
        cout<<"Country : "<<Country<<endl;
    }
};*/
/*4. Write a C++ program to create a class called Car that has private member variables for company, model, and year.
Implement member functions to get and set these variables.*/
/*class Car {
    private:
    string Company;
    string Model;
    int Year;
    public:
    void set_velues(string company, string model, int year) {
        Company = company;
        Model = model;
        Year = year;
    }
    string get_company() {return Company;}
    string get_model() {return Model;}
    int get_year() {return Year;}
    void Print_Values() {
        cout<<"Company : "<<Company<<endl;
        cout<<"Model : "<<Model<<endl;
        cout<<"Year : "<<Year<<endl;
    }
};*/
/*5. Write a C++ program to implement a class called BankAccount that has private member variables for account number and balance.
Include member functions to deposit and withdraw money from the account.*/
/*class BankAccount {
    private:
    short int AccountSetNum = 1;
    int AccountNumber = 0;
    string PassWord;
    double balance;
    public: 
    void set_AccountNumber(int PassCode, int newAccountNum) {
        if(PassCode%2==0&&AccountSetNum) {
            PassCode /= 2;
            if(PassCode-10>0) {
                PassCode -= 10;
                if(PassCode%100>0) {
                    AccountNumber = newAccountNum;
                    AccountSetNum--;
                }
                else {
                    cout<<"wrong PassCode"<<endl;
                    return;
                }
            }
            else {
                cout<<"wrong PassCode"<<endl;
                return;
            }
        }
        else {
            cout<<"wrong PassCode"<<endl;
            return;
        }
    }
    void set_PassWord(string p_w) {
        if(AccountNumber) PassWord = p_w;
        else {
            cout<<"you don't have account to set a pass word for it"<<endl;
            return;
        }
    }
    void set_balance(string password, double NewBalance) {
        if(password == PassWord) balance = NewBalance;
        else {
            cout<<"wrong PassWord try again"<<endl;
            return;
        }
    }
    void Deposit(string password, double dnum){
        if(password == PassWord) balance += dnum;
        else {
            cout<<"wrong PassWord try again"<<endl;
            return;
        }
    }
    void Withdraw(string password, double dnum) {
        if(password == PassWord) balance -= dnum;
        else {
            cout<<"wrong PassWord try again"<<endl;
            return;
        }
    }
    double get_balance() {return balance;}
};*/
/*6. Write a C++ program to create a class called Triangle that has private member variables for the lengths of its three sides.
Implement member functions to determine if the triangle is equilateral, isosceles, or scalene.*/
/*class Triangle {
    private:
    double high, width;
    public:
    void set_values(double High, double Width) {
        high = High;
        width = Width;
    }
    double area() {return (0.5*high*width);}
};*/
/*7. Write a C++ program to implement a class called Employee that has private member variables for name, employee ID, and salary.
Include member functions to calculate and set salary based on employee performance.*/
/*class Employee {
    private:
    string Name;
    int ID;
    double Salary;
    public:
    void set_employee(string name, int id, double salary = 0) {
        Name = name;
        ID = id;
        Salary = salary;
    }
    string get_name(int Id) {
        if(ID == Id)return Name;
        else return "wrong ID";
    }
    double get_salary(int Id) {
        if(ID == Id) return Salary;
        else {
            cerr<<"wrong ID"<<endl;
            return 0;
        }
    }
    int get_ID(int PassCode) {
        if (PassCode%3 == 0) {
            if(PassCode/1000>0) {
                if((PassCode%100)-25>0) {
                    return ID;
                }
                else {
                    cout<<"wrong Pass Code."<<endl;
                    return 0;
                }
            }
            else {
                cout<<"wrong Pass Code."<<endl;
                return 0;
            }
        }
        else {
            cout<<"wrong Pass Code."<<endl;
            return 0;
        }
    }
    void  print_information(int PassCode) {
        if (PassCode%3 == 0) {
            if(PassCode/1000>0) {
                if((PassCode%100)-25>0) {
                    cout<<"Name : "<<Name<<endl;
                    cout<<"ID : "<<ID<<endl;
                    cout<<"Salary : "<<Salary<<endl;
                }
                else cout<<"wrong Pass Code."<<endl;
            }
            else cout<<"wrong Pass Code."<<endl;
        }
        else cout<<"wrong Pass Code."<<endl;
    }
};*/
/*8. Write a C++ program to implement a class called Date that has private member variables for day, month, and year.
Include member functions to set and get these variables, as well as to validate if the date is valid.*/
/*class Date {
    private:
    int Day, Week, Month, Year;
    public:
    void set_time(int day, int week, int month, int year) {
        Day = day;
        Week = week;
        Month = month;
        Year = year;
    }
};*/
int main()
{
    
    return 0;
}