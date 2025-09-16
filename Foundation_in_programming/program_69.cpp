#include <iostream>
#include <chrono>
#include <thread>
#include "E:\Myfiles\programing\c++\ProgrammingLibrarys\MyLibrarys\lab\InOut.hpp"
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
float execution_time(std::function<T1(T2)> func, T2 arg)
{
    code_timer<false> timer;
    timer.start_time();
    func(arg);
    timer.stop_time();
    return timer.get_duration();
}
void bigOn_function(int num)
{
    code_timer<true> timer;
    for (int i = 0; i < num; i++)
        ;
}
void bigOn2_function(int num)
{
    code_timer<true> timer;
    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++)
            ;
}
void bigOn3_function(int num)
{
    code_timer<true> timer;
    for (int i = 0; i < num; ++i)
        for (int j = 0; j < num; ++j)
            for (int k = 0; k < num; ++k)
                ;
}
int main()
{
    io::NewLines(5);
    bigOn_function(100);
    bigOn2_function(100);
    bigOn3_function(100);
    return 0;
}