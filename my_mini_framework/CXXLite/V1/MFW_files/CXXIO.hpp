#pragma once
#ifndef PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_CXXIO_HPP
#define PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_CXXIO_HPP
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
     * @brief Prompts the user for input to fill a 2D vector.
     * @tparam T The type of elements in the 2D vector.
     * @param output The prompt message to display.
     * @param rows The number of rows (must be > 0).
     * @param cols The number of columns (must be > 0).
     * @return A 2D vector filled with user input.
     * @throws std::invalid_argument if rows or cols is less than or equal to zero
     */
    template <typename T>
    std::vector<std::vector<T>> input_vector_2d(const std::string &output, size_t rows, size_t cols)
    {
        if (rows <= 0 || cols <= 0)
            throw std::invalid_argument("Rows and columns must be greater than zero");
        std::vector<std::vector<T>> vec2d;
        T var;
        std::cout << output << std::endl;
        for (size_t i = 0; i < rows; i++)
        {
            std::vector<T> row;
            for (size_t j = 0; j < cols; j++)
            {
                std::cin >> var;
                row.push_back(var);
            }
            vec2d.push_back(row);
        }
        return vec2d;
    }
    /**
     * @brief Prompts the user for input to fill a 3D vector.
     * @tparam T The type of elements in the 3D vector.
     * @param output The prompt message to display.
     * @param dim1 The size of the first dimension (must be > 0).
     * @param dim2 The size of the second dimension (must be > 0).
     * @param dim3 The size of the third dimension (must be > 0).
     * @return A 3D vector filled with user input.
     * @throws std::invalid_argument if any dimension is less than or equal to zero.
     */
    template <typename T>
    std::vector<std::vector<std::vector<T>>> input_vector_3d(const std::string &output, size_t dim1, size_t dim2, size_t dim3)
    {
        if (dim1 <= 0 || dim2 <= 0 || dim3 <= 0)
            throw std::invalid_argument("Dimensions must be greater than zero");
        std::vector<std::vector<std::vector<T>>> vec3d;
        T var;
        std::cout << output << std::endl;
        for (size_t i = 0; i < dim1; i++)
        {
            std::vector<std::vector<T>> layer;
            for (size_t j = 0; j < dim2; j++)
            {
                std::vector<T> row;
                for (size_t k = 0; k < dim3; k++)
                {
                    std::cin >> var;
                    row.push_back(var);
                }
                layer.push_back(row);
            }
            vec3d.push_back(layer);
        }
        return vec3d;
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
    void print(const std::vector<T> &vec)
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
     * @brief Prints the contents of a std::vector to the standard output in a formatted manner.
     *
     * This function outputs the elements of the given vector enclosed in square brackets and separated by commas.
     * If the vector is empty, it prints "[]".
     *
     * @tparam T The type of the elements stored in the vector.
     * @param output The vector whose contents are to be printed.
     * @note The function is marked noexcept and does not throw exceptions.
     */
    template <typename T>
    inline void println(const std::vector<T> &output) noexcept
    {
        if (output.empty())
        {
            std::cout << "[]" << std::endl;
            return;
        }
        std::cout << "[";
        for (size_t i = 0; i < output.size(); ++i)
        {
            std::cout << output[i];
            if (i != output.size() - 1)
                std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
    /**
     * @brief Prints a 2D vector to the standard output in a formatted manner.
     *
     * This function outputs the contents of a two-dimensional std::vector to std::cout,
     * formatting it as nested lists (e.g., [[1, 2], [3, 4]]). If the input vector is empty,
     * it prints "[]".
     *
     * @tparam T The type of the elements stored in the inner vectors.
     * @param output The 2D vector to be printed.
     */
    template <typename T>
    inline void print(const std::vector<std::vector<T>> &output) noexcept
    {
        if (output.empty())
        {
            std::cout << "[]" << std::endl;
            return;
        }
        std::cout << "[";
        for (size_t i = 0; i < output.size(); ++i)
        {
            std::cout << "[";
            for (size_t j = 0; j < output[i].size(); ++j)
            {
                std::cout << output[i][j];
                if (j != output[i].size() - 1)
                    std::cout << ", ";
            }
            std::cout << "]";
            if (i != output.size() - 1)
                std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
    /**
     * @brief Prints a 2D vector to the standard output in a formatted manner.
     *
     * This function outputs the contents of a two-dimensional std::vector to std::cout,
     * formatting it as nested lists (e.g., [[1, 2], [3, 4]]). If the input vector is empty,
     * it prints "[]".
     *
     * @tparam T The type of the elements stored in the inner vectors.
     * @param output The 2D vector to be printed.
     */
    template <typename T>
    inline void println(const std::vector<std::vector<T>> &output) noexcept
    {
        if (output.empty())
        {
            std::cout << "[]" << std::endl;
            return;
        }
        std::cout << "[";
        for (size_t i = 0; i < output.size(); ++i)
        {
            std::cout << "[";
            for (size_t j = 0; j < output[i].size(); ++j)
            {
                std::cout << output[i][j];
                if (j != output[i].size() - 1)
                    std::cout << ", ";
            }
            std::cout << "]";
            if (i != output.size() - 1)
                std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
    /**
     * @brief Prints a 3D vector to the standard output in a formatted manner.
     * This function outputs the contents of a three-dimensional std::vector to std::cout,
     * formatting it as nested lists (e.g., [[[1, 2], [3, 4]], [[5, 6], [7, 8]]]). If the input vector is empty,
     * it prints "[]".
     * @param output The 3D vector to be printed.
     * @tparam T The type of the elements stored in the innermost vectors.
     * @note The function is marked noexcept and does not throw exceptions.
     * @example
     * std::vector<std::vector<std::vector<int>>> vec3d = {
     *     {{1, 2}, {3, 4}},
     *     {{5, 6}, {7, 8}}
     * };
     */
    template <typename T>
    inline void print(const std::vector<std::vector<std::vector<T>>> &output) noexcept
    {
        if (output.empty())
        {
            std::cout << "[]" << std::endl;
            return;
        }
        std::cout << "[";
        for (size_t i = 0; i < output.size(); ++i)
        {
            std::cout << "[";
            for (size_t j = 0; j < output[i].size(); ++j)
            {
                std::cout << "[";
                for (size_t k = 0; k < output[i][j].size(); ++k)
                {
                    std::cout << output[i][j][k];
                    if (k != output[i][j].size() - 1)
                        std::cout << ", ";
                }
                std::cout << "]";
                if (j != output[i].size() - 1)
                    std::cout << ", ";
            }
            std::cout << "]";
            if (i != output.size() - 1)
                std::cout << ", ";
        }
        std::cout << "]";
    }
    /**
     * @brief Prints a 3D vector to the standard output in a formatted manner.
     * This function outputs the contents of a three-dimensional std::vector to std::cout,
     * formatting it as nested lists (e.g., [[[1, 2], [3, 4]], [[5, 6], [7, 8]]]). If the input vector is empty,\
     * it prints "[]".
     * @param output The 3D vector to be printed.
     * @tparam T The type of the elements stored in the innermost vectors.
     * @note The function is marked noexcept and does not throw exceptions.
     * @example
     * std::vector<std::vector<std::vector<int>>> vec3d = {
     *     {{1, 2}, {3, 4}},
     *     {{5, 6}, {7, 8}}
     * };
     */
    template <typename T>
    inline void println(const std::vector<std::vector<std::vector<T>>> &output) noexcept
    {
        if (output.empty())
        {
            std::cout << "[]" << std::endl;
            return;
        }
        std::cout << "[";
        for (size_t i = 0; i < output.size(); ++i)
        {
            std::cout << "[";
            for (size_t j = 0; j < output[i].size(); ++j)
            {
                std::cout << "[";
                for (size_t k = 0; k < output[i][j].size(); ++k)
                {
                    std::cout << output[i][j][k];
                    if (k != output[i][j].size() - 1)
                        std::cout << ", ";
                }
                std::cout << "]";
                if (j != output[i].size() - 1)
                    std::cout << ", ";
            }
            std::cout << "]";
            if (i != output.size() - 1)
                std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
    /**
     * @brief Combines Test() and PrintVec() to test and print vector content.
     * @tparam T The type of vector elements.
     * @param TNum Test number.
     * @param vec The vector to test and print.
     */
    template <typename T>
    void print_test(long TNum, const std::vector<T> &vec)
    {
        if (vec.empty())
            throw std::invalid_argument("The vector is empty");
        print_test<int>(TNum, 0, true);
        print<T>(vec);
    }
    /**
     * @brief Combines Test() and PrintVec() to test and print 2D vector content.
     * @tparam T The type of vector elements.
     * @param TNum Test number.
     * @param vec The 2D vector to test and print.
     * @note This function throws an exception if the input vector is empty.
     * @example
     * std::vector<std::vector<int>> vec2d = {
     *    {1, 2},
     *    {3, 4}
     * };
     */
    template <typename T>
    void print_test(long TNum, const std::vector<std::vector<T>> &vec)
    {
        if (vec.empty())
            throw std::invalid_argument("The vector is empty");
        print_test<int>(TNum, 0, true);
        print<T>(vec);
    }
    /**
     * @brief Combines Test() and PrintVec() to test and print 3D vector content.
     * @tparam T The type of vector elements.
     * @param TNum Test number.
     * @param vec The 3D vector to test and print.
     * @note This function throws an exception if the input vector is empty.
     * @example
     * std::vector<std::vector<std::vector<int>>> vec3d = {
     *    {{1, 2}, {3, 4}},
     *    {{5, 6}, {7, 8}}
     * };
     */
    template <typename T>
    void print_test(long TNum, const std::vector<std::vector<std::vector<T>>> &vec)
    {
        if (vec.empty())
            throw std::invalid_argument("The vector is empty");
        print_test<int>(TNum, 0, true);
        print<T>(vec);
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
    /**
     * @brief Prints a formatted category name with separators and indentation.
     *
     * This function outputs the given category string (`category_s`) to the
     * standard output stream, surrounded by separator lines of a specified
     * length and character. It also indents the category text by a given
     * number of tab characters before printing.
     *
     * @param category_s  The category name to be printed.
     * @param tabs_num    Number of tab characters to print before the category text.
     * @param seplen      The length of the separator line (number of repeated characters).
     * @param sepch       The character used to build the separator line.
     *
     * @note This function relies on external helper functions:
     *       - separator(int length, char ch): prints a separator line.
     *       - Tabs(int n): prints a number of tab characters.
     *
     * @example
     * // Example: print the word "Settings" with 1 tab,
     * // a separator of length 20 made of '=' characters:
     * print_category("Settings", 1, 20, '=');
     *
     * // Expected output:
     * ====================
     *     Settings
     * ====================
     */
    void print_category(const std::string &category_s, int tabs_num, int seplen, char sepch)
    {
        separator(seplen, sepch);
        Tabs(tabs_num);
        std::cout << category_s << std::endl;
        separator(seplen, sepch);
    }
};
#endif // PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_CXXIO_HPP