#pragma once
#ifndef PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_LAB_TEST_STREAM_HPP
#define PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_LAB_TEST_STREAM_HPP
#include <functional>
#include <type_traits>
namespace function
{
    /**
     * @brief A template class that wraps a function object and provides
     *        safe execution with built-in error handling.
     *
     * The stream_t class acts as a minimal stream-like container for
     * function objects (std::function<T()>). It allows storing a function,
     * retrieving it, and executing it with exception handling.
     *
     * @tparam T The return type of the function object.
     */
    template <typename T, bool immediate_run>
    class stream_t
    {
    private:
        /**
         * @brief Internal function storage.
         *
         * This holds the function object that will be executed when
         * handler() or run_test() is called.
         */
        std::function<T()> f;

    protected:
        /**
         * @brief Executes the stored function with exception handling.
         *
         * This function runs the stored function object `f()` and
         * catches common exceptions:
         * - std::invalid_argument
         * - std::length_error
         * - std::exception
         * - const char* (C-style error messages)
         *
         * All errors are reported to std::cerr.
         *
         * @note This method is intended for internal use and is
         *       exposed through run_test().
         */
        void handler() const noexcept
        {
            try
            {
                f();
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << "invalid argument: " << e.what() << std::endl;
            }
            catch (const std::length_error &e)
            {
                std::cerr << "length error: " << e.what() << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << "Exception: " << e.what() << "\n";
            }
            catch (const char *msg)
            {
                std::cerr << "Error: " << msg << "\n";
            }
        }

    public:
        stream_t() = default;
        /**
         * @brief Assigns a new function to the stream.
         *
         * Example usage:
         * @code
         * stream_t<int> s;
         * s << []() -> int { return 42; };
         * @endcode
         *
         * @param fx The function object to be stored.
         */
        void operator<<(std::function<T()> fx) noexcept
        {
            f = fx;
            if (immediate_run)
                handler();
        }
        /**
         * @brief Extracts the stored function into another std::function.
         *
         * Example usage:
         * @code
         * std::function<int()> func;
         * s >> func; // func now holds the stored function
         * @endcode
         *
         * @param fx Reference to a function object where the stored function will be copied.
         */
        void operator>>(std::function<T()> &fx) noexcept { fx = f; }
        /**
         * @brief Executes the stored function safely.
         *
         * This method runs the stored function using handler(),
         * which ensures that common exceptions are caught and
         * reported instead of propagating.
         *
         * Example usage:
         * @code
         * s.run_test();
         * @endcode
         */
        void run_test() const noexcept { handler(); }
    };
    /**
     * @brief A template class that wraps a unary function (T -> T)
     *        and provides safe execution with built-in error handling.
     *
     * The stream_tp class stores a function of type std::function<T(T)>,
     * allowing input transformation and safe execution with exception handling.
     *
     * @tparam T The input and output type of the function object.
     */
    template <typename T>
    class stream_tp
    {
    private:
        /**
         * @brief Internal function storage.
         *
         * This holds the unary function (T -> T) that will be executed
         * when handler() or run_test() is called.
         */
        std::function<T(T)> f;

    protected:
        /**
         * @brief Executes the stored function with the given input and
         *        provides exception handling.
         *
         * This function runs the stored function `f(input)` and catches:
         * - std::invalid_argument
         * - std::length_error
         * - std::exception
         * - const char* (C-style error messages)
         *
         * All errors are reported to std::cerr.
         *
         * @param input The input value passed to the stored function.
         */
        void handler(const T &input) const noexcept
        {
            try
            {
                f(input);
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << "invalid argument: " << e.what() << std::endl;
            }
            catch (const std::length_error &e)
            {
                std::cerr << "length error: " << e.what() << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << "Exception: " << e.what() << "\n";
            }
            catch (const char *msg)
            {
                std::cerr << "Error: " << msg << "\n";
            }
        }

    public:
        stream_tp() = default;
        /**
         * @brief Assigns a new unary function to the stream.
         *
         * Example usage:
         * @code
         * stream_tp<int> s;
         * s << [](int x) { return x * x; }; // stores a square function
         * @endcode
         *
         * @param fx The function object to be stored.
         */
        void operator<<(std::function<T(T)> fx) noexcept { f = fx; }
        /**
         * @brief Extracts the stored function into another std::function.
         *
         * Example usage:
         * @code
         * std::function<int(int)> func;
         * s >> func; // func now holds the stored function
         * @endcode
         *
         * @param fx Reference to a function object where the stored function will be copied.
         */
        void operator>>(std::function<T(T)> &fx) noexcept { fx = f; }
        /**
         * @brief Executes the stored function with an lvalue reference input.
         *
         * Example usage:
         * @code
         * int value = 5;
         * s.run_test(value); // safely runs f(value)
         * @endcode
         *
         * @param value Reference to the input value.
         */
        void run_test(T &value) const noexcept { handler(value); }
        /**
         * @brief Executes the stored function with an rvalue input.
         *
         * Example usage:
         * @code
         * s.run_test(10); // safely runs f(10)
         * @endcode
         *
         * @param value Rvalue reference to the input value.
         */
        void run_test(T &&value) const noexcept { handler(value); }
    };
    /**
     * @brief A template class that wraps a unary transformation function (T2 -> T1)
     *        and provides safe execution with built-in error handling.
     *
     * The stream__tp class stores a function of type std::function<T1(T2)>,
     * allowing input of type T2 to be transformed into output of type T1.
     * It also provides exception handling for common errors.
     *
     * @tparam T1 The return type of the stored function.
     * @tparam T2 The input type of the stored function.
     */
    template <typename T1, typename T2>
    class stream__tp
    {
    private:
        /**
         * @brief Internal function storage.
         *
         * Holds the unary function (T2 -> T1) that will be executed
         * when handler() or run_test() is called.
         */
        std::function<T1(T2)> f;

    protected:
        /**
         * @brief Executes the stored function with the given input and
         *        provides exception handling.
         *
         * This function runs the stored function `f(input2)` and catches:
         * - std::invalid_argument
         * - std::length_error
         * - std::exception
         * - const char* (C-style error messages)
         *
         * All errors are reported to std::cerr.
         *
         * @param input2 The input value passed to the stored function.
         *
         * @note The return value of the function is currently ignored.
         *       Use run_test() or modify handler() to return the result if needed.
         */
        void handler(const T2 &input2)
        {
            try
            {
                f(input2);
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << "invalid argument: " << e.what() << std::endl;
            }
            catch (const std::length_error &e)
            {
                std::cerr << "length error: " << e.what() << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << "Exception: " << e.what() << "\n";
            }
            catch (const char *msg)
            {
                std::cerr << "Error: " << msg << "\n";
            }
        }

    public:
        stream__tp() = default;
        /**
         * @brief Assigns a new unary transformation function to the stream.
         *
         * Example usage:
         * @code
         * stream__tp<int, double> s;
         * s << [](double x) { return static_cast<int>(x * 2); };
         * @endcode
         *
         * @param fx The function object to be stored.
         */
        void operator<<(std::function<T1(T2)> fx) noexcept { f = fx; }
        /**
         * @brief Extracts the stored function into another std::function.
         *
         * Example usage:
         * @code
         * std::function<int(double)> func;
         * s >> func; // func now holds the stored function
         * @endcode
         *
         * @param fx Reference to a function object where the stored function will be copied.
         */
        void operator>>(std::function<T1(T2)> &fx) noexcept { fx = f; }
        /**
         * @brief Executes the stored function safely with a given input.
         *
         * Example usage:
         * @code
         * double d = 3.14;
         * s.run_test(d); // safely runs f(d)
         * @endcode
         *
         * @param value2 Input value of type T2 passed to the stored function.
         *
         * @note The return value of the stored function is ignored.
         */
        void run_test(const T2 &value2) { handler(value2); }
    };
    /**
     * @brief A template class that wraps a binary function (T2, T3 -> T1)
     *        and provides safe execution with built-in error handling.
     *
     * The stream__t_p class stores a function of type std::function<T1(T2, T3)>,
     * allowing transformation of two inputs (T2 and T3) into one output (T1).
     * It also provides exception handling for common errors.
     *
     * @tparam T1 The return type of the stored function.
     * @tparam T2 The first input type of the stored function.
     * @tparam T3 The second input type of the stored function.
     */
    template <typename T1, typename T2, typename T3>
    class stream__t_p
    {
    private:
        /**
         * @brief Internal function storage.
         *
         * Holds the binary function (T2, T3 -> T1) that will be executed
         * when handler() or run_test() is called.
         */
        std::function<T1(T2, T3)> f;

    protected:
        /**
         * @brief Executes the stored function with the given inputs and
         *        provides exception handling.
         *
         * This function runs the stored function `f(input2, input3)` and catches:
         * - std::invalid_argument
         * - std::length_error
         * - std::exception
         * - const char* (C-style error messages)
         *
         * All errors are reported to std::cerr.
         *
         * @param input2 The first input value.
         * @param input3 The second input value.
         *
         * @note The return value of the function is currently ignored.
         *       Use run_test() or modify handler() to return the result if needed.
         */
        void handler(const T2 &input2, const T3 &input3)
        {
            try
            {
                f(input2, input3);
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << "invalid argument: " << e.what() << std::endl;
            }
            catch (const std::length_error &e)
            {
                std::cerr << "length error: " << e.what() << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << "Exception: " << e.what() << "\n";
            }
            catch (const char *msg)
            {
                std::cerr << "Error: " << msg << "\n";
            }
        }

    public:
        stream__t_p() = default;
        /**
         * @brief Assigns a new binary function to the stream.
         *
         * Example usage:
         * @code
         * stream__t_p<int, int, int> s;
         * s << [](int a, int b) { return a + b; }; // stores addition function
         * @endcode
         *
         * @param fx The function object to be stored.
         */
        void operator<<(std::function<T1(T2, T3)> fx) noexcept { f = fx; }
        /**
         * @brief Extracts the stored function into another std::function.
         *
         * Example usage:
         * @code
         * std::function<int(int,int)> func;
         * s >> func; // func now holds the stored function
         * @endcode
         *
         * @param fx Reference to a function object where the stored function will be copied.
         */
        void operator>>(std::function<T1(T2, T3)> &fx) noexcept { fx = f; }
        /**
         * @brief Executes the stored function safely with two inputs.
         *
         * Example usage:
         * @code
         * s.run_test(3, 4); // safely runs f(3, 4)
         * @endcode
         *
         * @param value2 First input argument.
         * @param value3 Second input argument.
         *
         * @note The return value of the stored function is ignored.
         */
        void run_test(const T2 &value2, const T3 &value3) { handler(value2, value3); }
    };
}
#endif // PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_LAB_TEST_STREAM_HPP