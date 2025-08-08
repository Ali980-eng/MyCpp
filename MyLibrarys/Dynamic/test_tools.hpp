#pragma once
#ifndef PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_TEST_TOOLS_HPP
#define PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_TEST_TOOLS_HPP
#include <functional>
#include "InOut.hpp"

using namespace std;
unsigned int test_count = 1;
constexpr const char *test_message(bool test_result)
{
    return test_result ? "Success" : "Failed";
}
template <typename T>
constexpr void test(T realvalue, T expvalue, bool detalis = true, int seplen = 25, int white_space = 1)
{
    io::print_test(test_count, test_message(realvalue == expvalue));
    if (detalis)
    {
        io::println("details of the test (" + to_string(test_count) + "): ");
        io::separator(seplen);
        io::print("real value: ");
        io::println(realvalue);
        io::print("expected value: ");
        io::println(expvalue);
        io::separator(seplen);
        io::NewLines(white_space);
    }
    test_count++;
}
template <typename T1, typename T2>
void test_function(function<T1(T2)> fx, T1 expected, T2 value, bool detalis = true, int seplen = 25, int white_space = 1)
{
    test<T1>(fx(value), expected, detalis, seplen, white_space);
}
#endif // PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_TEST_TOOLS_HPP