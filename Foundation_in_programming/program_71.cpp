#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
/*9. override (for virtual functions)
//To avoid inadvertently creating a new function in derived classes.
// c++03
class dog
{
    virtual void A(int);
    virtual void B() const;
};
class yellowdog : public dog
{
    virtual void A(float); // Created a new function
    virtual void B();    // Created a new function
};
// c++11
class dog
class dog
{
    virtual void A(int);
    virtual void B() const;
    void C();
};
class yellowdog : public dog
{
    virtual void A(float) override; // Error: A has different parameter type
    virtual void B() const override;    // Error: B is not const in base class
    void C() override; // Error: C is not virtual in base class
};*/
/*10. final (for virtual functions and for class)
class dog final {
};
class dog {
    virtual void bark(int) final; // bark cannot be overridden in derived classes
};*/
/* 11. Compiler Generated Default constructor.
class dog {
    dog(int age) {}
};
dog d1; // Error: no default constructor
// C++11
class dog {
    dog(int age) {}
    dog() = default; // Request compiler to generate default constructor
};
dog d1; // OK
*/
/*12.delete
class dog {
    dog(int age) {}
};
dog a(2);
dog b(3.0); // 3.0 is coverted form double to int
a = b; // compiler generates assignment operator with int parameter
// C++11:
class dog {
    dog(int age) {}
    dog(double age) = delete; // Prevent conversion from double to int
    dog& operator=(const dog&) = delete; // Prevent assignment
};
*/
/*13. constexpr
int arr[6]; // ok
int A() { return 5; }
int arr2[A() + 1]; // Error: A is not a constant expression
// C++11:
constexpr int A() { return 5; } // Force A to be a constant expression
                                // at compile time
int arr2[A() + 1]; // Create an array of size 6
// Write faster program with constexpr
constexpr int square(int x) { return x * x; }
int y = square(5); // computed at compile time
*/
/*14. New String Literals
// C++ 03;
char* a = "string";
// C++11:
char* a = u8"string"; // UTF-8 string literal
char16_t* b = u"string"; // UTF-16 string literal
char32_t* c = U"string"; // UTF-32 string literal
char* d = R"(C:\myfolder\myfile.txt)"; // Raw string literal
*/
/*15. lambda function*/
template <typename func>
void filter(func f, std::vector<int> v)
{
    for (auto x : v)
    {
        if (f(x))
            std::cout << x << " ";
    }
    std::cout << std::endl;
}
int main()
{
    for (int i = 0; i < 5; i++)
        std::cout << std::endl;
    std::cout << [](int x, int y)
    { return x + y; }(2, 3) << std::endl; // prints 5
    auto f = [](int x, int y)
    { return x + y; };
    std::cout << f(5, 6) << std::endl; // prints 11
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    filter([](int x)
           { return x % 2 == 0; }, v); // prints even numbers
    filter([](int x)
           { return x % 2 != 0; }, v); // prints odd numbers
    filter([](int x)
           { return x > 5; }, v); // prints numbers greater than 5
    filter([](int x)
           { return x <= 5; }, v); // prints numbers less than or equal to 5
    int y = 3;
    filter([&](int x)
           { return x > y; }, v); // prints numbers greater than y
    return 0;
}