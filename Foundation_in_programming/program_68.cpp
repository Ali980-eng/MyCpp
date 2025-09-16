#include <iostream>
#include <chrono>
#include <thread>
int main()
{
    using namespace std::literals::chrono_literals;
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(1s);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> d_n = end - start;
    std::cout << d_n.count() << std::endl;
    return 0;
}