#include <iostream>
#include <print>
#include <vector>
#include <string>
#include <initializer_list>
/**
 * learn c++ 11
 */
void nl(short n = 1)
{
    while (n-- > 0)
        std::cout << '\n';
}
// ########################################################
//  1. Initializer List
//   c++ 03 initializer list:
int arr[] = {1, 2, 3, 4, 5};
/*old way to initialize a vector:
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
*/
// C++ 11 extended the support of initializer:
std::vector<int> v = {1, 2, 3, 4, 5}; // Calling initializer list constructor
// All the relevant STL containers have been updated to accept initializer lists
// Define your own initializer list constructor:
class MyClass
{
    std::vector<std::string> vec;

public:
    MyClass(std::initializer_list<std::string> init) : vec(init) {} // 1st choice
};
// ########################################################
//  2. Uniform Initialization
//  C++ 11 introduced a new way to initialize objects using curly braces {}
//  C++ 03 style:
class dog
{
public:
    std::string name; // 3rd choice
    int age;
    dog(std::string n, int a) : name(n), age(a) {} // 2nd choice
};
// dog d = {"Buddy", 3}; // C++ 03 style initialization
// C++ 11 style:
dog d = {"Buddy", 3}; // Uniform initialization using {}
// ########################################################
/** Uniform Initialization Search Order:
 * 1. Initializer list constructor (if available).
 * 2. Regular constructor that takes the appropriate parameters.
 * 3. Aggregate initialization (if no constructors are defined).
 * This order helps to avoid ambiguity and ensures that the most specific constructor is chosen.
 */
// ########################################################
//  3.auto type.
std::vector<int> vec = {1, 2, 3, 4, 5};
/*c++ 03:
for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    m_vec.push_back(*it);
*/

/*c++ 11:
for (auto it = vec.begin(); it != vec.end(); ++it)
    vec.push_back(*it);
*/
// ########################################################
// 4. foreach loop
/*c++ 03:
for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    std::cout << *it << " ";
*/
/*c++ 11:
for (auto element : vec) // works on any class that has begin() and end()
    std::cout << element << " "; // readonly access
    // if you want to change the element, use reference:
for (auto &element : vec)
    element *= 2; // modify the element
*/
// ########################################################
/*5. nullptr
 * to replace NULL pointer
 */
void foo(int i) { std::printf("foo(int): {}\n", i); }
void foo(char *p) { std::printf("foo(char*): {}\n", p ? p : "nullptr"); }
// ########################################################
// 6. enum class
// C++ 03 style:
enum apple
{
    red,
    green,
    yellow
};
enum orange
{
    small,
    medium,
    large
};
// C++ 11 style:
enum class banana
{
    shorty,
    longy
};
// ########################################################
// 7. static_assert
// runtime assert:
// assert(mypointer != nullptr); // only active in debug mode
// compile time assert:
static_assert(sizeof(int) == 4, "Integers are not 4 bytes");
// ########################################################
// 8. Delegating Constructors
// C++ 11 style:
class Base
{
    int x;
    int y;

public:
    Base(int x, int y) : x(x), y(y) {}
};
class Derived : public Base
{
    int z;

public:
    Derived(int x, int y, int z) : Base(x, y), z(z) {}
};
/*c++ 03 style Cons:
 * 1. Cumbersome code.
 * 2. init() could invoked by other functions*/
int main()
{
    nl(10);
    MyClass obj = {"Hello", "World", "!"};
    MyClass obj2{"C++", "11", "Initializer", "List"}; // effectively the same
    auto x = 42;                                      // x is of type int
    auto y = 3.14;                                    // y is of type double
    auto z = x;                                       // z is of type int (same as x)
    // foo(NULL); // Ambiguous, could match either overload
    foo(nullptr); // Calls foo(char*), no ambiguity
    apple a = red;
    orange o = small; // o is small, but which enum type?
    /*if (a == o)       // Error: different enum types
        std::printf("Same color/size\n");
    else
        std::printf("Different color/size\n");*/
    return 0;
}