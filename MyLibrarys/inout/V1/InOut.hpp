#ifndef PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_INOUT_HPP
#define PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_INOUT_HPP
#include <iostream>
#include <string>
#include <vector>
#include <type_traits>
#include <climits>
#include <stdexcept>
/**
 * @file InOut.hpp
 * @brief Provides input/output functions and utilities for C++ programs.
 * This header file includes functions for printing values, handling errors,
 * taking user input, and formatting output.
 * It also includes type traits to check for specializations like std::vector.
 */
template <typename Test, template <typename...> class Ref>
struct is_specialization : std::false_type
{
};
/**
 * @brief Checks if a type is a specialization of a template.
 * @tparam Test The type to check.
 * @tparam Ref The template to check against.
 */
template <template <typename...> class Ref, typename... Args>
struct is_specialization<Ref<Args...>, Ref> : std::true_type
{
};
namespace io
{
    using std::cout, std::cerr, std::cin, std::endl, std::string, std::vector,
        std::true_type, std::false_type, std::out_of_range;
    /**
     * @brief Prints a number of newline characters.
     * @param num Number of new lines to print (default = 2).
     */
    void NewLines(short num = 2)
    {
        if (SHRT_MAX <= num)
            throw out_of_range("num is bigger than SHRT_MAX");
        for (short i = 0; i < num; i++)
            cout << endl;
    }
    /**
     * @brief Prints a value followed by a newline to standard output.
     * @tparam T Type of the value to print.
     * @param output The value to be printed.
     */
    template <typename T>
    void println(const T &output)
    {
        if (is_specialization<T, std::vector>::value)
            cerr << "Type Error: Cannot print vector<bool> as a vector." << endl;
        else
            cout << output << endl;
    }
    /**
     * @brief Prints a value without a newline to standard output.
     * @tparam T Type of the value to print.
     * @param output The value to be printed.
     */
    template <typename T>
    void print(const T &output)
    {
        if (is_specialization<T, std::vector>::value)
            cerr << "Type Error: Cannot print vector<bool> as a vector." << endl;
        else
            cout << output;
    }
    /**
     * @brief Prints an error message followed by a newline to standard error.
     * @tparam T Type of the message to print.
     * @param output The error message to be printed.
     */
    template <typename T>
    void println_error(const T &output)
    {
        if (is_specialization<T, std::vector>::value)
            cerr << "Type Error: Cannot print vector<bool> as a vector." << endl;
        else
            cout << output << endl;
    }
    /**
     * @brief Prints an error message without a newline to standard error.
     * @tparam T Type of the message to print.
     * @param output The error message to be printed.
     */
    template <typename T>
    void print_error(const T &output)
    {
        if (is_specialization<T, std::vector>::value)
            cerr << "Type Error: Cannot print vector<bool> as a vector." << endl;
        else
            cout << output;
    }
    /**
     * @brief Prints a prompt message and takes user input of the same type.
     * @tparam T Type of the input variable.
     * @param output The prompt message to display.
     * @return T The user input.
     */
    template <typename T>
    T input(const T &output)
    {
        if (is_vector(output))
            throw("Type Error");
        T var;
        cout << output << endl;
        cin >> var;
        return var;
    }
    /**
     * @brief Prints a number of tab characters.
     * @param num Number of tabs to print (default = 2).
     */
    void Tabs(short num = 2)
    {
        if (num >= SHRT_MAX)
            throw out_of_range("num is bigger than SHRT_MAX");
        for (short i = 0; i < num; i++)
            cout << "\t";
    }
    /**
     * @brief Prints a standardized test output.
     * @tparam T The type of the output value.
     * @param TNum The test number.
     * @param OutPut The output value to print.
     */
    template <typename T>
    void print_test(long TNum, const T &&OutPut, bool VecFun = false)
    {
        if (is_specialization<T, std::vector>::value)
        {
            cerr << "Type Error: Cannot print vector<bool> as a vector." << endl;
            return; // End of error case
        }
        if (TNum <= 0)
        {
            cerr << "The Test Number is equal or smaller than zero" << endl;
            return; // End of error case
        }
        cout << "Test(" << TNum << "): ";
        cout << OutPut;
        cout << endl; // End of print_test
    }
    /**
     * @brief Prints a standardized test output.
     * @tparam T The type of the output value.
     * @param TNum The test number.
     * @param OutPut The output value to print.
     * @param VecFun If true, skips printing the output (for use with vector
     * functions).
     */
    template <typename T>
    void print_test(long TNum, const T &OutPut, bool VecFun = false)
    {
        if (TNum <= 0)
        {
            cerr << "The Test Number is equal or smaller than zero" << endl;
            return;
        }
        cout << "Test(" << TNum << "): ";
        if constexpr (is_specialization<T, std::vector>::value)
        {
            if constexpr (std::is_same<T, std::vector<bool>>::value)
            {
                cerr << "Type Error: Cannot print vector<bool> as a vector." << endl;
                return;
            }
            cout << "[ ";
            for (const auto &el : OutPut)
                cout << el << ' ';
            cout << "]";
        }
        else
            cout << OutPut;
        cout << endl;
    }
    /**
     * @brief Prints all elements in a vector with formatting.
     * @tparam T The type of vector elements.
     * @param vec The vector to print.
     */
    template <typename T>
    void print_vec(const vector<T> &vec)
    {
        if (vec.empty())
        {
            cerr << "The vector is empty" << endl;
            return;
        }
        if (vec.size() == 1)
        {
            cout << " [" << vec[0] << "] " << endl;
            return;
        }
        for (size_t i = 0; i < vec.size(); i++)
        {
            if (i == 0)
                cout << " [" << vec[i] << ", ";
            else if (i == vec.size() - 1)
                cout << vec[i] << "] " << endl;
            else
                cout << vec[i] << ", ";
        }
    }
    /**
     * @brief Combines Test() and PrintVec() to test and print vector content.
     * @tparam T The type of vector elements.
     * @param TNum Test number.
     * @param vec The vector to test and print.
     */
    template <typename T>
    void print_test_vec(long TNum, const vector<T> &vec)
    {
        if (is_vector(vec))
        {
            cerr << "Type Error: Cannot print vector<bool> as a vector." << endl;
            return; // End of error case
        }
        if (vec.empty())
        {
            cerr << "The vector is empty" << endl;
            return;
        }
        print_test(TNum, 0, true);
        print_vec(vec);
    }
    /**
     * @brief Prints characters of a string individually starting from a given
     * index.
     * @param str The string to print.
     * @param index Starting index (default = 0). If out of range, starts from 0.
     */
    void PrintChStr(const string &str, short index = 0)
    {
        if (index < 0 || index >= str.length())
            index = 0;
        for (size_t i = index; i < str.length(); i++)
            cout << str[i] << ' ';
        cout << endl;
    }
    /**
     * @brief Prints a horizontal line using a specific character.
     * @param length The number of characters in the line.
     * @param ch The character to use (must be one of: ~, -, #, *, =).
     */
    void separator(short length, char ch = '-')
    {
        if (ch == '~' || ch == '-' || ch == '#' || ch == '*' || ch == '=')
        {
            for (int i = length; i >= 0; i--)
                cout << ch;
            cout << endl;
        }
        else
            cerr << "Invalid separator character." << endl;
    }
    /**
     * @brief Prints a decorated category title.
     * @param category The category title to print.
     */
    void PrintCategory(const string &category)
    {
        separator(2 * category.length());
        Tabs(category.length() / 10);
        cout << category << endl;
        separator(2 * category.length());
    }
};
#endif // PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_INOUT_HPP