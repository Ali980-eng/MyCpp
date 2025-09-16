#include <iostream>
#include <print>
#include <string>
#include <vector>
/*c++ 11: Rvalue Reference
        1. Moving Semantics.
        2. Perfect Forwarding.
    Prerequisite: understanding rvalue and lvalue*/
void print_int(int &i) { std::cout << "lvalue reference: " << i << std::endl; }
void print_int(int &&i) { std::cout << "rvalue reference: " << i << std::endl; }
/*
 * Note 1 : the most useful place rvalue reference is overloading copy
 * constructor and copy assignment operator. to achieve move semantics.
 */
/**Note 2 : Move semantics is implemented for all STL containers, which means:
 *          a. Move to C++ 11, Your code will be faster without changing a thing.
 *          b. Passing-by-value can be used for STL containers.
 */
/** Move consteructor/Move Assignment Operator:
 * Purpose: conveniently avoid costly and unnecessary deep copying
 * 1. They are particularly powerful where passing by reference and passing by value are both used.
 * 2. They give you finer control of which part of your object to be moved.
 */
int main()
{
    for (int i = 0; i < 10; i++)
        std::cout << std::endl;
    int a = 5;   // a is a lvalue
    int &b = a;  // b is a lvalue refernce(reference)
    int &&c = 0; // c is a rvalue refernce
    print_int(b);
    print_int(c);
    return 0;
}