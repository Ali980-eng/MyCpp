#include "CXXVector.hpp"
#include "CXXLite.hpp"
void utest_1()
{
    io::print_category("unit test 1", 3, 60, '*');
    std::vector<int> v1 = {10, 9, 39, 23};
    std::vector<int> v2 = {23, 39, 9, 10};
    test::vector<int>(uvt::reverse_v<int>(v1), v2);
    test::basic<bool>(uvt::same_v(uvt::reverse_v<int>(v1), v2), true);
    v1.pop_back();
    test::basic<size_t>(uvt::v_end(v1), 2);
    test::basic<size_t>(uvt::v_end(v2), 3);
    test::basic<bool>(uvt::same_v(v1, v2), false);
    v2.push_back(100);
    v2.push_back(88);
    v2.push_back(66);
    std::vector<int> v3 = {9, 10, 100};
    test::vector<int>(uvt::sub_v(v2, 2, 4), v3);
}
void utest_2()
{
    io::print_category("unit test 2", 3, 60, '*');
    std::vector<std::vector<int>> v1 = {
        {10, 29, 38},
        {29, 38},
        {2, 39, 39},
        {1}};
    std::vector<std::vector<int>> v2 = {
        {1},
        {39, 39, 2},
        {38, 29},
        {38, 29, 10}};
    test::vector_2d<int>(uvt::reverse_v(v1), v2);
}
void utest_3()
{
    io::print_category("unit test 3", 3, 60, '*');
    std::vector<std::vector<int>> v1 = {
        {77, 29, 39, 38, 29},
        {55, 32, 19, 20, 22},
        {33, 44, 90, 92, 35},
        {12, 11, 39, 38, 29}};
    std::vector<std::vector<int>> v2 = {
        {77, 29, 39, 38, 29},
        {55, 32, 19, 20, 22},
        {12, 11, 39, 38, 29}};
    test::vector_2d<int>(uvt::erase_row<int>(v1, 2), v2);
}
void utest_4()
{
    io::print_category("unit test 4", 3, 60, '*');
    std::vector<std::vector<int>> v1 = {
        {77, 29, 39, 38, 29},
        {55, 32, 19, 20, 22},
        {33, 44, 90, 92, 35},
        {12, 11, 39, 38, 29}};
    std::vector<std::vector<int>> v2 = {
        {77, 29, 38, 29},
        {55, 32, 20, 22},
        {33, 44, 92, 35},
        {12, 11, 38, 29}};
    test::vector_2d<int>(uvt::erase_column<int>(v1, 2), v2);
}
void utest_5()
{
    io::print_category("unit test 5", 3, 60, '*');
    std::vector<std::vector<int>> v1 = {
        {77, 29, 39, 38, 29},
        {55, 32, 19, 20, 22},
        {33, 44, 90, 92, 35},
        {12, 11, 39, 38, 29}};
    std::vector<std::vector<int>> v2 = {
        {77, 29, 38, 29},
        {55, 32, 20, 22},
        {12, 11, 38, 29}};
    test::vector_2d<int>(uvt::erase_row_column<int>(v1, 2, 2), v2);
}
int main()
{
    io::NewLines(5);
    function::stream_t<void, true> s;
    s << utest_1;
    s << utest_2;
    s << utest_3;
    s << utest_4;
    s << utest_5;
    io::println("execution time for unit test 1: " + std::to_string(benchmark::execution_time<void>(utest_1)));
    io::println("execution time for unit test 2: " + std::to_string(benchmark::execution_time<void>(utest_2)));
    io::println("execution time for unit test 3: " + std::to_string(benchmark::execution_time<void>(utest_3)));
    io::println("execution time for unit test 4: " + std::to_string(benchmark::execution_time<void>(utest_4)));
    io::println("execution time for unit test 5: " + std::to_string(benchmark::execution_time<void>(utest_5)));
    return 0;
}
