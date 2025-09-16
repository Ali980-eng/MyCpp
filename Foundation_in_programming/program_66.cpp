#include <iostream>
#define print(output) (std::cout << output)
#define println(output) (std::cout << output << std::endl)
#define print_error(output) (std::cerr << output)
#define println_error(output) (std::cerr << output << std::endl)
#define print_test(tnum, output) (std::cout << "Test(" << tnum << "): " << output << std::endl)
int main()
{
    for (int i = 0; i < 4; ++i)
        std::cout << std::endl;
    print("hello world");
    return 0;
}