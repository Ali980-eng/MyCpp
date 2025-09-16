#include <iostream>
void nl(int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << std::endl;
    }
}
int main()
{
    nl(5);
    return 0;
}