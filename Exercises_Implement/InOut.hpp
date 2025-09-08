#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <functional>
#include <type_traits>
#include <climits>
namespace io
{
    /**
     * @brief Prints a number of newline characters.
     * @param num Number of new lines to print (default = 2).
     */
    void NewLines(short num = 2)
    {
        if (SHRT_MAX <= num)
            throw std::out_of_range("num is bigger than SHRT_MAX");
        for (short i = 0; i < num; i++)
            std::cout << std::endl;
    }
    /**
     * @brief Prints a value followed by a newline to standard output.
     * @tparam T Type of the value to print.
     * @param output The value to be printed.
     */
    template <typename T>
    inline void println(const T &output) noexcept { std::cout << output << std::endl; }
    /**
     * @brief Prints a value without a newline to standard output.
     * @tparam T Type of the value to print.
     * @param output The value to be printed.
     */
    template <typename T>
    inline void print(const T &output) noexcept { std::cout << output; }
    /**
     * @brief Prints an error message followed by a newline to standard error.
     * @tparam T Type of the message to print.
     * @param output The error message to be printed.
     */
    template <typename T>
    inline void println_error(const T &output) noexcept { std::cerr << output << std::endl; }
    /**
     * @brief Prints an error message without a newline to standard error.
     * @tparam T Type of the message to print.
     * @param output The error message to be printed.
     */
    template <typename T>
    inline void print_error(const T &output) noexcept { std::cerr << output; }
    /**
     * @brief Prints a prompt message and takes user input of the same type.
     * @tparam T Type of the input variable.
     * @param output The prompt message to display.
     * @return T The user input.
     */
    template <typename T>
    T input(const T &output) noexcept
    {
        T var;
        std::cout << output << std::endl;
        std::cin >> var;
        return var;
    }
    /**
     * @brief Prints a prompt message and takes user input of a different type.
     * @tparam T1 Type of the prompt message.
     * @tparam T2 Type of the input variable.
     * @param output The prompt message to display.
     * @return T2 The user input.
     */
    template <typename T1, typename T2>
    T2 input(const T1 &output)
    {
        T2 var;
        std::cout << output << std::endl;
        std::cin >> var;
        return var;
    }
    /**
     * @brief Prints a prompt message and takes user input for a vector of a different type.
     * @tparam T1 Type of the prompt message.
     * @tparam T2 Type of the input variable.
     * @param output The prompt message to display.
     * @param size The number of elements in the vector.
     * @return std::vector<T2> The user input vector.
     */
    template <typename T1, typename T2>
    std::vector<T2> input_vector(const T1 &output, size_t size)
    {
        if (size <= 0)
            throw std::invalid_argument("Size must be greater than zero");
        std::vector<T2> vec;
        T2 var;
        std::cout << output << std::endl;
        for (size_t i = 0; i < size; i++)
        {
            std::cin >> var;
            vec.push_back(var);
        }
        return vec;
    }
    /**
     * @brief Prints a number of tab characters.
     * @param num Number of tabs to print (default = 2).
     */
    void Tabs(short num = 2)
    {
        if (num >= SHRT_MAX)
            throw std::out_of_range("num is bigger than SHRT_MAX");
        for (short i = 0; i < num; i++)
            std::cout << "\t";
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
        if (TNum <= 0)
            throw std::invalid_argument("The Test Number is equal or smaller than zero");
        std::cout << "Test(" << TNum << "): ";
        if (VecFun)
            return;
        std::cout << OutPut;
        std::cout << std::endl; // End of print_test
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
            throw std::invalid_argument("The Test Number is equal or smaller than zero");
        std::cout << "Test(" << TNum << "): ";
        if (VecFun)
            return;
        std::cout << OutPut;
        std::cout << std::endl;
    }
    /**
     * @brief Prints all elements in a vector with formatting.
     * @tparam T The type of vector elements.
     * @param vec The vector to print.
     */
    template <typename T>
    void print_v(const std::vector<T> &vec)
    {
        if (vec.empty())
            throw std::invalid_argument("The vector is empty");
        if (vec.size() == 1)
        {
            std::cout << " [" << vec[0] << "] " << std::endl;
            return;
        }
        for (size_t i = 0; i < vec.size(); i++)
        {
            if (i == 0)
                std::cout << " [" << vec[i] << ", ";
            else if (i == vec.size() - 1)
                std::cout << vec[i] << "] " << std::endl;
            else
                std::cout << vec[i] << ", ";
        }
    }
    /**
     * @brief Combines Test() and PrintVec() to test and print vector content.
     * @tparam T The type of vector elements.
     * @param TNum Test number.
     * @param vec The vector to test and print.
     */
    template <typename T>
    void print_test_v(long TNum, const std::vector<T> &vec)
    {
        if (vec.empty())
            throw std::invalid_argument("The vector is empty");
        print_test(TNum, 0, true);
        print_vec(vec);
    }
    /**
     * @brief Prints characters of a string individually starting from a given
     * index.
     * @param str The string to print.
     * @param index Starting index (default = 0). If out of range, starts from 0.
     */
    void print_char_str(const std::string &str, short index = 0) noexcept
    {
        if (index < 0 || index >= str.length())
            index = 0;
        for (size_t i = index; i < str.length(); i++)
            std::cout << str[i] << ' ';
        std::cout << std::endl;
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
                std::cout << ch;
            std::cout << std::endl;
        }
        else
            throw std::invalid_argument("Invalid separator character.");
    }
    /**
     * @brief Prints a decorated category title.
     * @param category The category title to print.
     */
    void print_category(const std::string &category) noexcept
    {
        separator(2 * category.length());
        Tabs(category.length() / 10);
        std::cout << category << std::endl;
        separator(2 * category.length());
    }
};