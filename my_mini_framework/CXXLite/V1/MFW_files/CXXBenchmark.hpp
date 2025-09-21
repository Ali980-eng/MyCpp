#pragma once
#ifndef PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_LAB_CXXBENCHMARK_HPP
#define PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_LAB_CXXBENCHMARK_HPP
#include <chrono>
#include <thread>
#include <windows.h>
#include <psapi.h>
#include <memory>
namespace benchmark
{
    /**
     * @brief A lightweight code execution timer utility.
     *
     * The `code_timer` class can be used to measure execution time in two modes:
     *
     * 1. **RAII mode (`in_structure = true`)**:
     *    - Starts timing automatically upon construction.
     *    - Stops timing and prints duration (in milliseconds) automatically
     *      upon destruction.
     *    - No need to call `start_time()` or `stop_time()`.
     *
     * 2. **Manual mode (`in_structure = false`)**:
     *    - Requires explicit calls to `start_time()` and `stop_time()`.
     *    - `get_duration()` can be used after `stop_time()` to retrieve the result.
     *
     * @tparam in_structure A compile-time boolean flag:
     *         - `true`: RAII automatic mode.
     *         - `false`: manual start/stop mode.
     *
     * Example usage:
     * @code
     * {
     *     // RAII mode: automatically times this scope
     *     code_timer<true> t;
     *     // some heavy code...
     * }
     * // Prints: time code duration: X ms
     *
     * {
     *     // Manual mode
     *     code_timer<false> t;
     *     t.start_time();
     *     // some heavy code...
     *     t.stop_time();
     *     std::cout << "manual duration: " << t.get_duration() * 1000.0f << " ms\n";
     * }
     * @endcode
     */
    template <bool in_structure>
    class code_timer
    {
    private:
        bool started = false;
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
        std::chrono::duration<float> mycodetime;

    public:
        /// @brief Constructor. Starts timing if RAII mode is enabled.
        code_timer()
        {
            if (in_structure)
                start = std::chrono::high_resolution_clock::now();
        }
        /// @brief Returns the last measured duration in seconds.
        float get_duration() const { return mycodetime.count(); }
        /// @brief Start timing (only valid in manual mode).
        void start_time()
        {
            if (in_structure)
                throw std::logic_error("RAII mode: timer is running by default");
            start = std::chrono::high_resolution_clock::now();
            started = true;
        }
        /// @brief Stop timing (only valid in manual mode).
        void stop_time()
        {
            if (in_structure)
                throw std::logic_error("RAII mode: timer is running by default");
            if (!started)
                throw std::logic_error("Timer is not running");
            end = std::chrono::high_resolution_clock::now();
            mycodetime = end - start;
            started = false;
        }
        /// @brief Destructor. In RAII mode, prints the measured duration.
        ~code_timer()
        {
            if (in_structure)
            {
                end = std::chrono::high_resolution_clock::now();
                mycodetime = end - start;
                float ms = mycodetime.count();
            }
        }
    };
    /**
     * @brief Measure the execution time of a parameterless function.
     *
     * This function takes a callable object (e.g., lambda, functor, function pointer)
     * with no parameters, executes it once, and measures the duration of its execution
     * using @ref code_timer in manual mode.
     *
     * @tparam T Return type of the function.
     * @param func A std::function<T()> representing the callable to measure.
     * @return Execution time in seconds as a floating-point value.
     *
     * @note The measured duration is in seconds. Multiply by 1000.0f if milliseconds
     *       are desired.
     *
     * Example usage:
     * @code
     * auto duration = execution_time<void>([]() {
     *     heavy_computation();
     * });
     * std::cout << "Duration: " << duration * 1000.0f << " ms\n";
     * @endcode
     */
    template <typename T>
    float execution_time(std::function<T()> func)
    {
        code_timer<false> timer;
        timer.start_time();
        func();
        timer.stop_time();
        return timer.get_duration();
    }
    /**
     * @brief Measure the execution time of a single-argument function.
     *
     * This overload takes a callable object that accepts a single argument,
     * executes it once with the provided value, and measures the duration
     * of its execution using @ref code_timer in manual mode.
     *
     * @tparam T The type of both the argument and return value of the function.
     * @param func A std::function<T(T)> representing the callable to measure.
     * @param arg The argument to pass to the function.
     * @return Execution time in seconds as a floating-point value.
     *
     * @note The measured duration is in seconds. Multiply by 1000.0f if milliseconds
     *       are desired.
     *
     * Example usage:
     * @code
     * auto duration = execution_time<int>([](int x) {
     *     return fibonacci(x);
     * }, 30);
     *
     * std::cout << "Duration: " << duration * 1000.0f << " ms\n";
     * @endcode
     */
    template <typename T>
    float execution_time(std::function<T(T)> func, T arg)
    {
        code_timer<false> timer;
        timer.start_time();
        func(arg);
        timer.stop_time();
        return timer.get_duration();
    }
    /**
     * @brief Measure the execution time of a function taking two arguments of the same type.
     *
     * Executes the provided callable with two arguments of type @p T2 and
     * measures its execution duration using @ref code_timer in manual mode.
     *
     * @tparam T1 Return type of the function.
     * @tparam T2 Argument type of the function (both arguments are the same type).
     * @param func A std::function<T1(T2, T2)> representing the callable to measure.
     * @param arg1 First argument to pass to the function.
     * @param arg2 Second argument to pass to the function.
     * @return Execution time in seconds as a floating-point value.
     *
     * @example
     * @code
     * auto duration = execution_time<int, int>([](int a, int b) {
     *     return a + b;
     * }, 10, 20);
     *
     * std::cout << "Duration: " << duration * 1000.0f << " ms\n";
     * @endcode
     */
    template <typename T1, typename T2>
    float execution_time(std::function<T1(T2, T2)> func, T2 arg1, T2 arg2)
    {
        code_timer<false> timer;
        timer.start_time();
        func(arg1, arg2);
        timer.stop_time();
        return timer.get_duration();
    }
    /**
     * @brief Measure the execution time of a single-argument function.
     *
     * Executes the provided callable with one argument of type @p T2 and
     * measures its execution duration using @ref code_timer in manual mode.
     *
     * @tparam T1 Return type of the function.
     * @tparam T2 Argument type of the function.
     * @param func A std::function<T1(T2)> representing the callable to measure.
     * @param arg Argument to pass to the function.
     * @return Execution time in seconds as a floating-point value.
     *
     * @example
     * @code
     * auto duration = execution__time<int, int>([](int x) {
     *     return x * x;
     * }, 42);
     *
     * std::cout << "Duration: " << duration * 1000.0f << " ms\n";
     * @endcode
     */
    template <typename T1, typename T2>
    float execution__time(std::function<T1(T2)> func, T2 arg)
    {
        code_timer<false> timer;
        timer.start_time();
        func(arg);
        timer.stop_time();
        return timer.get_duration();
    }
    /**
     * @brief Measure the execution time of a two-argument function with different types.
     *
     * Executes the provided callable with arguments of types @p T2 and @p T3,
     * and measures its execution duration using @ref code_timer in manual mode.
     *
     * @tparam T1 Return type of the function.
     * @tparam T2 Type of the first argument.
     * @tparam T3 Type of the second argument.
     * @param func A std::function<T1(T2, T3)> representing the callable to measure.
     * @param arg1 First argument to pass to the function.
     * @param arg2 Second argument to pass to the function.
     * @return Execution time in seconds as a floating-point value.
     *
     * @example
     * @code
     * auto duration = execution__time<std::string, int, double>(
     *     [](int a, double b) {
     *         return std::to_string(a + static_cast<int>(b));
     *     },
     *     5, 3.7
     * );
     *
     * std::cout << "Duration: " << duration * 1000.0f << " ms\n";
     * @endcode
     */
    template <typename T1, typename T2, typename T3>
    float execution__time(std::function<T1(T2, T3)> func, T2 arg1, T3 arg2)
    {
        code_timer<false> timer;
        timer.start_time();
        func(arg1, arg2);
        timer.stop_time();
        return timer.get_duration();
    }
    /**
     * @brief A collection of simple functions to simulate various time complexities.
     *
     * These functions are used internally to compare execution durations and
     * determine the likely time complexity of an algorithm.
     */
    /** Constant time complexity O(1). */
    void big_O1() noexcept { return; }
    /** Logarithmic time complexity O(log n).
     *  Repeatedly divides num by n until zero. */
    void logn(int num, int n) noexcept
    {
        while (num > 0)
            num /= n;
    }
    /** Linear time complexity O(n).
     *  Iterates num times in a single loop. */
    void big_On(int num) noexcept
    {
        for (int i = 0; i < num; i++)
            ;
    }
    /** Linearithmic time complexity O(n log n).
     *  Outer loop runs n times, inner loop is logarithmic. */
    void logn_n(int num, int n) noexcept
    {
        for (int i = 0; i < num; i++)
        {
            int temp = num;
            while (temp > 0)
                temp /= n;
        }
    }
    /** Quadratic time complexity O(n^2). */
    void big_On2(int num) noexcept
    {
        for (int i = 0; i < num; i++)
            for (int j = 0; j < num; j++)
                ;
    }
    /** Cubic time complexity O(n^3). */
    void big_On3(int num) noexcept
    {
        for (int i = 0; i < num; i++)
            for (int j = 0; j < num; j++)
                for (int k = 0; k < num; k++)
                    ;
    }
    /**
     * @brief Estimate the time complexity of an algorithm based on measured execution time.
     *
     * This function compares the provided execution time against predefined
     * time benchmarks for standard complexities: O(1), O(log n), O(n), O(n log n),
     * O(n^2), O(n^3), and higher exponential or factorial complexities.
     *
     * @param time Measured execution time in seconds.
     * @param num Input size used in the benchmark functions.
     * @param logbase Base for logarithmic calculations (default: 10).
     * @return A string representing the estimated time complexity.
     *
     * @example
     * @code
     * float t = 0.0023f;  // measured execution time
     * int n = 1000;       // input size
     * std::string complexity = execution_type(t, n);
     * std::cout << "Estimated complexity: " << complexity << "\n";
     * @endcode
     */
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
    /**
     * @brief Returns the size of an object in bytes.
     *
     * This function calculates the compile-time size of any object
     * using sizeof.
     *
     * @tparam T Type of the object.
     * @param object Reference to the object.
     * @return Size of the object in bytes.
     *
     * @note This only accounts for the object's immediate size in memory,
     *       not dynamically allocated data (heap).
     */
    template <typename T>
    constexpr size_t mata_data(T &object) noexcept
    {
        return sizeof(object);
    }
    /**
     * @brief Returns the heap memory used by a vector.
     *
     * Calculates the memory allocated on the heap for a std::vector
     * based on its capacity and element size.
     *
     * @tparam T Type of elements in the vector.
     * @param v Reference to the vector.
     * @return Heap memory in bytes.
     */
    template <typename T>
    constexpr size_t heap_data(const std::vector<T> &v)
    {
        return sizeof(T) * v.capacity();
    }
    /**
     * @brief Returns the heap memory used by a std::string.
     *
     * Calculates the memory allocated on the heap based on the string's capacity.
     *
     * @param s Reference to the string.
     * @return Heap memory in bytes.
     */
    size_t heap_data(const std::string &s)
    {
        return sizeof(char) * s.capacity();
    }
    /**
     * @brief Measures additional memory usage caused by executing a parameterless function.
     *
     * The function checks the process's working set before and after execution
     * and returns the difference in memory usage.
     *
     * @tparam T Return type of the function.
     * @param f Function to execute.
     * @return Additional memory used in bytes (0 if no increase).
     */
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
    /**
     * @brief Measures additional memory usage caused by executing a single-argument function.
     *
     * The function checks the process's working set before and after execution
     * and returns the difference in memory usage.
     *
     * @tparam T Return type and argument type of the function.
     * @param f Function to execute.
     * @param input Argument to pass to the function.
     * @return Additional memory used in bytes (0 if no increase).
     */
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
    /**
     * @brief Measures additional memory usage caused by executing a single-argument function.
     *
     * Overload with template parameters T1 and T2.
     *
     * @tparam T1 Return type of the function.
     * @tparam T2 Argument type of the function.
     * @param f Function to execute.
     * @param input Argument to pass to the function.
     * @return Additional memory used in bytes (0 if no increase).
     */
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
     * @brief Measures additional memory usage caused by executing a two-argument function.
     *
     * The function checks the process's working set before and after execution
     * and returns the difference in memory usage.
     *
     * @tparam T1 Return type of the function.
     * @tparam T2 Type of the first argument.
     * @tparam T3 Type of the second argument.
     * @param f Function to execute.
     * @param input1 First argument to pass to the function.
     * @param input2 Second argument to pass to the function.
     * @return Additional memory used in bytes (0 if no increase).
     */
    template <typename T1, typename T2, typename T3>
    size_t function__data(std::function<T1(T2, T3)> f, T2 input1, T3 input2)
    {
        PROCESS_MEMORY_COUNTERS info1, info2;
        GetProcessMemoryInfo(GetCurrentProcess(), &info1, sizeof(info1));
        f(input1, input2);
        GetProcessMemoryInfo(GetCurrentProcess(), &info2, sizeof(info2));
        if (info2.WorkingSetSize > info1.WorkingSetSize)
            return info2.WorkingSetSize - info1.WorkingSetSize;
        else
            return 0;
    }
};
#endif // PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_LAB_CXXBENCHMARK_HPP