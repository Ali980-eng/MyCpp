#pragma once
#ifndef PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_LAB_TESTING_HPP
#define PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_LAB_TESTING_HPP
#include "InOut.hpp"
#include <chrono>
#include <thread>
namespace test
{
    namespace time
    {
        /**
         * @brief A utility class for measuring code execution time.
         * This class can be used to time code blocks or functions, either automatically
         * when instantiated with `in_structure` set to true, or manually by calling
         * the `start_time()` and `stop_time()` methods.
         */
        template <bool in_structure>
        class code_timer
        {
        private:
            bool started = false;
            std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
            std::chrono::duration<float> mycodetime;

        public:
            code_timer()
            {
                if (in_structure)
                    start = std::chrono::high_resolution_clock::now();
            }
            float get_duration() const
            {
                return mycodetime.count();
            }
            void start_time()
            {
                if (in_structure)
                    throw std::logic_error("is running by default");
                start = std::chrono::high_resolution_clock::now();
                started = true;
            }
            void stop_time()
            {
                if (in_structure)
                    throw std::logic_error("is running by default");
                if (!started)
                    throw std::logic_error("Timer is not running");
                end = std::chrono::high_resolution_clock::now();
                mycodetime = end - start;
                started = false;
            }
            ~code_timer()
            {
                if (in_structure)
                {
                    end = std::chrono::high_resolution_clock::now();
                    mycodetime = end - start;
                    float ms = mycodetime.count() * 1000.0f;
                    std::cout << "time code duration: " << ms << "ms\n";
                }
            }
        };
        template <typename T>
        float execution_time(std::function<T()> func)
        {
            code_timer<false> timer;
            timer.start_time();
            func();
            timer.stop_time();
            return timer.get_duration();
        } // typename... Args
        template <typename T>
        float execution_time(std::function<T(T)> func, T arg)
        {
            code_timer<false> timer;
            timer.start_time();
            func(arg);
            timer.stop_time();
            return timer.get_duration();
        }
        template <typename T1, typename T2>
        float execution_time(std::function<T1(T2, T2)> func, T2 arg1, T2 arg2)
        {
            code_timer<false> timer;
            timer.start_time();
            func(arg1, arg2);
            timer.stop_time();
            return timer.get_duration();
        }
        template <typename T1, typename T2>
        float execution__time(std::function<T1(T2)> func, T2 arg)
        {
            code_timer<false> timer;
            timer.start_time();
            func(arg);
            timer.stop_time();
            return timer.get_duration();
        }
        template <typename T1, typename T2, typename T3>
        float execution__time(std::function<T1(T2, T3)> func, T2 arg1, T3 arg2)
        {
            code_timer<false> timer;
            timer.start_time();
            func(arg1, arg2);
            timer.stop_time();
            return timer.get_duration();
        }
        void big_O1() noexcept
        {
            return;
        }
        void logn(int num, int n) noexcept
        {
            while (num > 0)
                num /= n;
        }
        void big_On(int num) noexcept
        {
            for (int i = 0; i < num; i++)
                ;
        }
        void logn_n(int num, int n) noexcept
        {
            for (int i = 0; i < num; i++)
            {
                int temp = num;
                while (temp > 0)
                    temp /= n;
            }
        }
        void big_On2(int num) noexcept
        {
            for (int i = 0; i < num; i++)
                for (int j = 0; j < num; j++)
                    ;
        }
        void big_On3(int num) noexcept
        {
            for (int i = 0; i < num; i++)
                for (int j = 0; j < num; j++)
                    for (int k = 0; k < num; k++)
                        ;
        }
        std::string execution_type(float time, int num, int logbase = 10) noexcept
        {
            std::function<void()> O1 = big_O1;
            std::function<void(int, int)> log_n = logn;
            std::function<void(int)> On = big_On;
            std::function<void(int, int)> log_n_n = logn_n;
            std::function<void(int)> On2 = big_On2;
            std::function<void(int)> On3 = big_On3;
            if (time < execution_time<void>(O1))
                return "O(1)";
            else if (time < execution__time<void, int, int>(log_n, num, logbase))
                return "O(log n)";
            else if (time < execution__time<void, int>(On, num))
                return "O(n)";
            else if (time < execution__time<void, int, int>(log_n_n, num, logbase))
                return "O(n log n)";
            else if (time < execution__time<void, int>(On2, num))
                return "O(n^2)";
            else if (time < execution__time<void, int>(On3, num))
                return "O(n^3)";
            else
                return "O(2^n) or O(n!)";
        }
    }
    namespace size
    {
        template <typename T>
        constexpr size_t mata_data(T &object) noexcept
        {
            return sizeof(object);
        }
        template <typename T>
        constexpr size_t heap_data(const std::vector<T> &v)
        {
            return sizeof(T) * v.capacity();
        }
        size_t heap_data(const std::string &s)
        {
            return sizeof(char) * s.capacity();
        }
        template <typename T>
        size_t function_data(std::function<T()> f)
        {
            PROCESS_MEMORY_COUNTERS info1, info2;
            GetProcessMemoryInfo(GetCurrentProcess(), &info1, sizeof(info1));
            f();
            GetProcessMemoryInfo(GetCurrentProcess(), &info2, sizeof(info2));
            if (info2.WorkingSetSize > info1.WorkingSetSize)
                return info2.WorkingSetSize - info1.WorkingSetSize;
            else
                return 0;
        }
        template <typename T>
        size_t function_data(std::function<T(T)> f, T input)
        {
            PROCESS_MEMORY_COUNTERS info1, info2;
            GetProcessMemoryInfo(GetCurrentProcess(), &info1, sizeof(info1));
            f(input);
            GetProcessMemoryInfo(GetCurrentProcess(), &info2, sizeof(info2));
            if (info2.WorkingSetSize > info1.WorkingSetSize)
                return info2.WorkingSetSize - info1.WorkingSetSize;
            else
                return 0;
        }
        template <typename T1, typename T2>
        size_t function__data(std::function<T1(T2)> f, T2 input)
        {
            PROCESS_MEMORY_COUNTERS info1, info2;
            GetProcessMemoryInfo(GetCurrentProcess(), &info1, sizeof(info1));
            f(input);
            GetProcessMemoryInfo(GetCurrentProcess(), &info2, sizeof(info2));
            if (info2.WorkingSetSize > info1.WorkingSetSize)
                return info2.WorkingSetSize - info1.WorkingSetSize;
            else
                return 0;
    }
    /**
     * @brief Structure to keep track of test counts for different categories.
     *
     * This structure contains counters for various test categories:
     * - function: Number of function-related tests.
     * - vector: Number of vector-related tests.
     * - basic: Number of basic tests.
     *
     * The default value for each counter is 1.
     */
    struct count
    {
        unsigned int function = 1;
        unsigned int vector = 1;
        unsigned int basic = 1;
    } index;
    /**
     * @brief Returns a message indicating the result of a test.
     *
     * This function returns "Success" if the test_result is true,
     * otherwise it returns "Failed".
     *
     * @param test_result The result of the test (true for success, false for failure).
     * @return const char* A string message representing the test result.
     * @note This function is noexcept and guarantees not to throw exceptions.
     */
    const char *test_message(bool test_result) noexcept
    {
        return test_result ? "Success" : "Failed";
    }
    /**
     * @brief Performs a basic test by comparing a real value to an expected value.
     *
     * This function prints the result of the comparison and, if requested, provides detailed output
     * including the real and expected values, separated by a visual separator. The test index is incremented
     * after each call.
     *
     * @tparam T Type of the values to compare.
     * @param realvalue The actual value to test.
     * @param expvalue The expected value to compare against.
     * @param detalis If true, prints detailed information about the test (default: false).
     * @param seplen Length of the separator line in the detailed output (default: 25).
     * @param white_space Number of new lines to add after the detailed output (default: 1).
     * @return true if realvalue equals expvalue, false otherwise.
     * @note This function is noexcept and increments the test index after each call.
     */
    template <typename T>
    bool basic(T realvalue, T expvalue, bool detalis = false, int seplen = 25, int white_space = 1) noexcept
    {
        io::print_test(index.basic, test_message(realvalue == expvalue));
        if (detalis)
        {
            io::println("details of the test (" + std::to_string(index.basic) + "): ");
            io::separator(seplen);
            io::print("real value: ");
            io::println(realvalue);
            io::print("expected value: ");
            io::println(expvalue);
            io::separator(seplen);
            io::NewLines(white_space);
        }
        index.basic++;
        return realvalue == expvalue;
    }
    bool basic(std::string realvalue, std::string expvalue, bool detalis = false, int seplen = 25, int white_space = 1) noexcept
    {
        io::print_test(index.basic, test_message(realvalue == expvalue));
        if (detalis)
        {
            io::println("details of the test (" + std::to_string(index.basic) + "): ");
            io::separator(seplen);
            io::print("real value: ");
            io::println(realvalue);
            io::print("expected value: ");
            io::println(expvalue);
            io::separator(seplen);
            io::NewLines(white_space);
        }
        index.basic++;
        return realvalue == expvalue;
    }
    /**
     * @brief Compares two vectors element-wise and prints detailed test results.
     *
     * This function compares the contents of two vectors, `real_v` and `expected_v`, element by element.
     * If either vector is empty, it throws an `std::invalid_argument` exception.
     * If the vectors differ in size, it performs a basic test on their sizes and returns the result.
     * Otherwise, it performs a basic test on each corresponding element and prints detailed results if requested.
     * The function also prints separators and an overall result message.
     *
     * @tparam T Type of the elements in the vectors.
     * @param real_v The vector containing actual values.
     * @param expected_v The vector containing expected values.
     * @param detalis If true, prints detailed comparison information (default: false).
     * @param seplen Length of the separator line for output formatting (default: 25).
     * @param white_space Amount of whitespace for output formatting (default: 1).
     * @return true if all elements match; false otherwise.
     * @throws std::invalid_argument if either vector is empty.
     */
    template <typename T>
    bool vector(std::vector<T> real_v, std::vector<T> expected_v, bool detalis = false, int seplen = 25, int white_space = 1)
    {
        if (real_v.empty() || expected_v.empty())
            throw std::invalid_argument("The vectors are empty");
        bool result = true;
        if (real_v.size() != expected_v.size())
        {
            result = basic(real_v.size(), expected_v.size(), detalis, seplen, white_space);
            return result;
        }
        io::println("vector test(" + std::to_string(index.vector) + ") details: ");
        io::separator(seplen);
        for (size_t i = 0; i < real_v.size(); i++)
            result &= basic(real_v[i], expected_v[i], detalis, seplen, white_space);
        io::separator(seplen);
        io::println<std::string>("Overall result: " + std::string(test_message(result)));
        std::cout << std::endl;
        index.vector++;
        return result;
    }
    /**
     * @brief Compares two 2D vectors for equality and prints detailed test results.
     *
     * This function checks if the provided 2D vectors `real_2dv` and `expected_2dv` are equal.
     * It prints detailed information about the comparison if `detalis` is set to true.
     * The function also prints separators and overall test results.
     *
     * @tparam T The type of elements stored in the vectors.
     * @param real_2dv The actual 2D vector to be tested.
     * @param expected_2dv The expected 2D vector to compare against.
     * @param detalis If true, prints detailed comparison information (default: false).
     * @param splen The length of the separator line (default: 25).
     * @param white_space The amount of whitespace used in formatting (default: 1).
     * @return true if the vectors are equal, false otherwise.
     * @throws std::invalid_argument if either vector is empty.
     */
    template <typename T>
    bool vector_2d(std::vector<std::vector<T>> real_2dv, std::vector<std::vector<T>> expected_2dv, bool detalis = false, int splen = 25, int white_space = 1)
    {
        if (real_2dv.empty() || expected_2dv.empty())
            throw std::invalid_argument("The vectors are empty");
        bool result = true;
        if (real_2dv.size() != expected_2dv.size())
        {
            result &= basic(real_2dv.size(), expected_2dv.size(), detalis, splen, white_space);
            return result;
        }
        io::println("vector 2D test(" + std::to_string(index.vector) + ") details: ");
        io::separator(splen * 2);
        for (size_t i = 0; i < real_2dv.size(); i++)
            result &= vector(real_2dv[i], expected_2dv[i], detalis, splen, white_space);
        io::separator(splen * 2);
        io::println<std::string>("Overall result: " + std::string(test_message(result)));
        std::cout << std::endl;
        index.vector++;
        return result;
    }
    /**
     * @brief Compares two 3D vectors for equality and optionally prints detailed test results.
     *
     * This function checks if the provided 3D vectors `real_3dv` and `expected_3dv` are equal in size and content.
     * If the vectors are empty, it throws an std::invalid_argument exception.
     * If the sizes differ, it performs a basic test and returns the result.
     * Otherwise, it iterates through each 2D slice and compares them using `vector_test_2d`.
     * Optionally prints detailed information about the test process.
     *
     * @tparam T Type of the elements stored in the 3D vectors.
     * @param real_3dv The actual 3D vector to test.
     * @param expected_3dv The expected 3D vector to compare against.
     * @param detalis If true, prints detailed comparison information (default: false).
     * @param seplen Length of the separator line for output formatting (default: 25).
     * @param white_space Amount of whitespace for output formatting (default: 1).
     * @return true if all elements and sizes match; false otherwise.
     * @throws std::invalid_argument if either vector is empty.
     */
    template <typename T>
    bool vector_3d(std::vector<std::vector<std::vector<T>>> real_3dv, std::vector<std::vector<std::vector<T>>> expected_3dv, bool detalis = false, int seplen = 25, int white_space = 1)
    {
        if (real_3dv.empty() || expected_3dv.empty())
            throw std::invalid_argument("The vectors are empty");
        bool result = true;
        if (real_3dv.size() != expected_3dv.size())
        {
            result &= basic(real_3dv.size(), expected_3dv.size(), detalis, seplen, white_space);
            return result;
        }
        io::println("vector 3D test(" + std::to_string(index.vector) + ") details: ");
        io::separator(seplen * 3);
        for (size_t i = 0; i < real_3dv.size(); i++)
            result &= vector_2d(real_3dv[i], expected_3dv[i], detalis, seplen, white_space);
        io::separator(seplen * 3);
        io::println<std::string>("Overall result: " + std::string(test_message(result)));
        std::cout << std::endl;
        return result;
    }
    /**
     * @brief Tests a function by comparing its return value to an expected value.
     *
     * This template function executes the provided function object `fx`, compares its result to `expected`,
     * and returns the result of the comparison. Optionally, it can print detailed output.
     *
     * @tparam T The return type of the function to be tested.
     * @param fx The function object to be tested.
     * @param expected The expected result to compare against.
     * @param detalis If true, prints detailed output (default: false).
     * @param seplen The length of the separator line in the output (default: 25).
     * @param white_space The amount of whitespace in the output (default: 1).
     * @return true if the function's return value matches the expected value, false otherwise.
     * @note This function increments the `index.function` counter.
     * @noexcept This function does not throw exceptions.
     */
    template <typename T>
    bool function(std::function<T()> fx, T expected, bool detalis = false, int seplen = 25, int white_space = 1) noexcept
    {
        index.function++;
        return basic(fx(), expected, detalis, seplen, white_space);
    }
    /**
     * @brief Tests a function by comparing its output to an expected value.
     *
     * This function applies the provided function `fx` to the input `value`, then compares
     * the result to `expected` using `basic_test`. Optionally, it can display detailed output.
     *
     * @tparam T The type of the input and output values.
     * @param fx The function to test, taking and returning a value of type T.
     * @param expected The expected result of applying `fx` to `value`.
     * @param value The input value to pass to `fx`.
     * @param detalis If true, enables detailed output (default: false).
     * @param seplen The length of the separator in the output (default: 25).
     * @param white_space The amount of whitespace in the output (default: 1).
     * @return true if the test passes, false otherwise.
     * @note Increments the function test index counter.
     * @noexcept This function does not throw exceptions.
     */
    template <typename T>
    bool function(std::function<T(T)> fx, T expected, T value, bool detalis = false, int seplen = 25, int white_space = 1) noexcept
    {
        index.function++;
        return basic(fx(value), expected, detalis, seplen, white_space);
    }
    /**
     * @brief Tests a function by comparing its output to an expected value.
     *
     * @tparam T1 The return type of the function to test.
     * @tparam T2 The argument type of the function to test.
     * @param fx The function to test, accepting a value of type T2 and returning T1.
     * @param expected The expected result to compare against.
     * @param value The input value to pass to the function.
     * @param detalis If true, prints detailed test output (default: false).
     * @param seplen The length of the separator in the output (default: 25).
     * @param white_space The amount of whitespace in the output (default: 1).
     * @return true if the function output matches the expected value, false otherwise.
     * @note Increments the function test index counter.
     * @noexcept This function does not throw exceptions.
     */
    template <typename T1, typename T2>
    bool function(std::function<T1(T2)> fx, T1 expected, T2 value, bool detalis = false, int seplen = 25, int white_space = 1) noexcept
    {
        index.function++;
        return basic(fx(value), expected, detalis, seplen, white_space);
    }
    /**
     * @brief Tests a binary function by comparing its output to an expected value.
     *
     * This function invokes the provided std::function with two arguments and compares
     * the result to the expected value using basic_test. Optionally, it can print details
     * about the test.
     *
     * @tparam T1 Return type of the function.
     * @tparam T2 Type of the first argument to the function.
     * @tparam T3 Type of the second argument to the function.
     * @param fx The function to test, accepting two arguments of types T2 and T3, returning T1.
     * @param expected The expected result to compare against.
     * @param value1 The first argument to pass to the function.
     * @param value2 The second argument to pass to the function.
     * @param detalis If true, prints detailed test information. Default is false.
     * @param seplen Separator length for output formatting. Default is 25.
     * @param white_space Amount of whitespace for output formatting. Default is 1.
     * @return true if the test passes, false otherwise.
     * @note Increments the function test index before running the test.
     * @exception noexcept This function does not throw exceptions.
     */
    template <typename T1, typename T2, typename T3>
    bool function(std::function<T1(T2, T3)> fx, T1 expected, T2 value1, T3 value2, bool detalis = false, int seplen = 25, int white_space = 1) noexcept
    {
        index.function++;
        return basic(fx(value1, value2), expected, detalis, seplen, white_space);
    }
    /**
     * @brief Resets the test count to its initial value.
     *
     * Sets the 'basic' member of the 'index' object to 1.
     * This function is constexpr and noexcept.
     */
    constexpr inline void reset_count() noexcept { index.basic = 1; }
    /**
     * @brief Resets the vector index counter to its initial value.
     *
     * This function sets the `index.vector` variable to 1, effectively resetting
     * any count or position tracking associated with vectors. It is marked as
     * `constexpr` and `noexcept`, ensuring compile-time evaluation and no exceptions.
     */
    constexpr inline void reset_vector_count() noexcept { index.vector = 1; }
    /**
     * @brief Resets the function count index to its initial value.
     *
     * This function sets the `function` member of the `index` object to 1.
     * It is marked as `constexpr` and `noexcept`, ensuring compile-time evaluation
     * and no exceptions thrown.
     */
    constexpr inline void reset_function_count() noexcept { index.function = 1; }
    /**
     * @brief Resets all internal counters to their initial state.
     *
     * This function calls reset_test_count(), reset_vector_count(), and reset_function_count()
     * to reset the respective counters. It is marked as constexpr and noexcept.
     */
    constexpr inline void reset_all_counts() noexcept
    {
        reset_count();
        reset_vector_count();
        reset_function_count();
    }
}
#endif // PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_LAB_TESTING_HPP