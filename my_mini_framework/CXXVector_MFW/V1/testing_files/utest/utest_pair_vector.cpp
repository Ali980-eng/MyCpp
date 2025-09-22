#include "CXXLite.hpp"
#include "CXXVector.hpp"
void utest_1()
{
    io::print_category("unit test 1", 3, 60, '*');
    std::vector<int> v1 = {10, 28, 22, 12};
    std::vector<int> v2 = {88, 98, 89, 29};
    uvt::pair_v<int> pv1(v1, v2);
    test::basic<bool>(pv1.empty(), false);
    test::basic<bool>(pv1.empty_v1(), false);
    test::basic<bool>(pv1.empty_v2(), false);
    test::basic<int>(pv1.at_v1(1), 28);
    test::basic<int>(pv1.at_v2(2), 89);
    test::vector<int>(pv1.get_vec1(), v1);
    test::vector<int>(pv1.get_vec2(), v2);
}
void utest_2()
{
    io::print_category("unit test 2", 3, 60, '*');
    std::vector<int> v1 = {4, 6};
    std::vector<int> v2 = {7, 3, 8, 2};
    uvt::pair_v<int> pv2(v1, v2);
    test::basic<int>(pv2.Divi_v1(std::pow(10, 3)), 41);
    test::basic<int>(pv2.Divi_v2(std::pow(10, 6)), 2976);
    test::basic<long double>(pv2.Mult_v1(), 24);
    test::basic<long double>(pv2.Mult_v2(), 336);
    test::basic<long double>(pv2.sum_v1(), 10);
    test::basic<long double>(pv2.sum_v2(), 20);
    test::basic<long double>(pv2.average_v1(), 5);
    test::basic<long double>(pv2.average_v2(), 5);
    test::basic<size_t>(pv2.size_v1(), 2);
    test::basic<size_t>(pv2.size_v2(), 4);
    pv2.clear_v1();
    test::basic<bool>(pv2.empty_v1(), true);
    test::basic<bool>(pv2.empty_v2(), false);
}
void utest_3()
{
    io::print_category("unit test 3", 3, 60, '*');
    std::vector<short> v1 = {95, 98};
    std::vector<short> v2 = {10, 12};
    uvt::pair_v<short> pv3(v1, v2);
    pv3.clear_v2();
    test::basic<bool>(pv3.empty_v2(), true);
    test::basic<bool>(pv3.empty_v1(), false);
    test::basic<bool>(pv3.empty(), false);
    pv3.clear_v1();
    test::basic<bool>(pv3.empty(), true);
}
void utest_4()
{
    io::print_category("unit test 4", 3, 60, '*');
    std::vector<char> v1 = {'l', 'i'};
    std::vector<char> v2 = {'v', 'o'};
    uvt::pair_v<char> pv4(v1, v2);
    pv4.swap_vecs();
    test::vector<char>(pv4.get_vec1(), v2);
    test::vector<char>(pv4.get_vec2(), v1);
    pv4.clear_all();
    test::basic<char>(pv4.empty(), true);
}
void utest_5()
{
    io::print_category("unit test 5", 3, 60, '*');
    uvt::pair_v<float> pv5 = {1.8, 1.9, 2.8, 3.9};
    test::basic<bool>(pv5.empty_v1(), false);
    test::basic<bool>(pv5.empty_v2(), true);
    pv5 = {1.2, 8.9, 3.8, 2.0};
    test::basic<bool>(pv5.empty(), false);
    test::basic<int>(pv5.sum_v1(), 10.4);
    test::basic<int>(pv5.sum_v2(), 15.9);
    test::basic<int>(pv5.Mult_v1(), 37.3464);
    test::basic<int>(pv5.Mult_v2(), 81.168);
    test::basic<int>(pv5.average_v1(), 2.6);
    test::basic<int>(pv5.average_v2(), 3.975);
}
void utest_6()
{
    io::print_category("unit test 6", 3, 60, '*');
    uvt::vector_2d<char> v = {
        {'o', 'i'},
        {'u', 'w', 'q'}};
    uvt::pair_v<char> pv6 = {'o', 'i'};
    pv6 = {'u', 'w', 'q'};
    test::basic<bool>(pv6 == v.get(0), true);
    pv6 + 3;
    v += 3;
    test::vector<char>(pv6.get_vec1(), v.get(0));
    test::vector<char>(pv6.get_vec2(), v.get(1));
}
void utest_7()
{
    io::print_category("unit test 7", 3, 60, '*');
    std::vector<std::vector<int>> vs = {
        {2, 17, 2, 17},
        {3, 17, 7, 18}};
    uvt::pair_v<int> pv7;
    pv7 = {1, 9, 0, 8};
    pv7 = {2, 9, 5, 9};
    std::vector<int> v = {1, 8, 2, 9};
    pv7 + v;
    test::vector<int>(pv7.get_vec1(), vs[0]);
    test::vector<int>(pv7.get_vec2(), vs[1]);
}
void utest_8()
{
    io::print_category("unit test 8", 3, 60, '*');
    std::vector<std::vector<short>> v = {
        {8, 29, 19, 23},
        {2, 88, 21, 0}};
    uvt::pair_v<short> pv8;
    pv8 = {18, 39, 29, 33};
    pv8 = {12, 98, 31, 10};
    pv8 - 10;
    test::vector<short>(pv8.get_vec1(), v[0]);
    test::vector<short>(pv8.get_vec2(), v[1]);
}
void utest_9()
{
    io::print_category("unit test 9", 3, 60, '*');
    std::vector<std::vector<int>> vs = {
        {0, 1, -2, -1},
        {1, 1, 3, 0}};
    uvt::pair_v<int> pv9;
    pv9 = {1, 9, 0, 8};
    pv9 = {2, 9, 5, 9};
    std::vector<int> v = {1, 8, 2, 9};
    pv9 - v;
    test::vector<int>(pv9.get_vec1(), vs[0]);
    test::vector<int>(pv9.get_vec2(), vs[1]);
}
void utest_10()
{
    io::print_category("unit test 10", 3, 60, '*');
    std::vector<std::vector<int>> vs = {
        {5, 45, 0, 40},
        {10, 45, 25, 45}};
    uvt::pair_v<int> pv10;
    pv10 = {1, 9, 0, 8};
    pv10 = {2, 9, 5, 9};
    pv10 * 5;
    test::vector<int>(pv10.get_vec1(), vs[0]);
    test::vector<int>(pv10.get_vec2(), vs[1]);
}
void utest_11()
{
    io::print_category("unit test 11", 3, 60, '*');
    std::vector<std::vector<int>> vs = {
        {2, 5, 0, 4},
        {1, 6, 12, 3}};
    uvt::pair_v<int> pv11;
    pv11 = {4, 10, 0, 8};
    pv11 = {2, 12, 24, 6};
    pv11 / 2;
    test::vector<int>(pv11.get_vec1(), vs[0]);
    test::vector<int>(pv11.get_vec2(), vs[1]);
}
void utest_12()
{
    io::print_category("unit test 12", 3, 60, '*');
    uvt::pair_v<int> pv12 = {{12, 98, 23}, {78, 88, 32, 29}};
    test::basic<size_t>(pv12.size_v1(), 3);
    test::basic<size_t>(pv12.size_v2(), 4);
    pv12.set_v1({98, 28, 38});
    test::basic<int>(pv12.at_v1(0), 98);
    test::basic<int>(pv12.at_v2(1), 88);
}
void utest_13()
{
    io::print_category("unit test 13", 3, 60, '*');
    uvt::pair__v<int, char> pv13 = {{18, 29, 39}, {'w', 'o', 'i', 'l'}};
    test::basic<int>(pv13.at_v1(1), 29);
    test::basic<char>(pv13.at_v2(2), 'i');
    test::basic<size_t>(pv13.size_v1(), 3);
    test::basic<size_t>(pv13.size_v2(), 4);
}
void utest_14()
{
    io::print_category("unit test 14", 3, 60, '*');
    uvt::pair__v<short, float> pv14 = {{19, 99, 38}, {1.7, 2.3, 8.9}};
    test::basic<int>(pv14.sum_v1(), 156);
    test::basic<int>(pv14.sum_v2(), 12.9);
    test::basic<int>(pv14.Mult_v1(), 71478);
    test::basic<int>(pv14.Mult_v2(std::pow(10, 3)), 34798);
    test::basic<int>(pv14.Divi_v1(std::pow(10, 8)), 1399);
    test::basic<int>(pv14.Divi_v2(std::pow(10, 3)), 28.73);
}
void utest_15()
{
    io::print_category("unit test 15", 3, 60, '*');
    uvt::pair__v<int, char> pv15;
    pv15 = {{19, 28, 39}, {'o', '2', 'o'}};
    test::basic<bool>(pv15.empty(), false);
    pv15.clear_v1();
    test::basic<bool>(pv15.empty_v1(), true);
    test::basic<bool>(pv15.empty_v2(), false);
    pv15.clear_v2();
    test::basic<bool>(pv15.empty_v2(), true);
    test::basic<bool>(pv15.empty(), true);
}
void utest_16()
{
    io::print_category("unit test 16", 3, 60, '*');
    std::vector<int> v1 = {10, 29, 39};
    std::vector<char> v2 = {'o', 'z', 'w'};
    int sum = 0;
    for (char c : v2)
        sum += int(c);
    uvt::pair__v<int, char> pv16;
    test::basic<bool>(pv16.empty(), true);
    pv16.set_v1(v1);
    test::basic<bool>(pv16.empty_v1(), false);
    test::basic<bool>(pv16.empty_v2(), true);
    pv16.set_v2(v2);
    test::basic<bool>(pv16.empty_v2(), false);
    test::basic<bool>(pv16.empty(), false);
    test::basic<int>(pv16.sum_v1(), 78);
    test::basic<int>(pv16.sum_v2(), sum);
    pv16.clear_all();
    test::basic<bool>(pv16.empty(), true);
}
void utest_17()
{
    io::print_category("unit test 17", 3, 60, '*');
    uvt::pair__v<float, int> pv17 = {{19.8, 12.9, 11.7}, {99, 29, 29, 20}};
    test::basic<size_t>(pv17.size_v1(), 3);
    test::basic<size_t>(pv17.size_v2(), 4);
    test::basic<int>(static_cast<int>(pv17.average_v1()), 14);
    test::basic<int>(static_cast<int>(pv17.average_v2()), 44);
}
void utest_18()
{
    io::print_category("unit test 18", 3, 60, '*');
    std::vector<int> v1 = {89, 99, 102, 129};
    std::vector<char> v2 = {'o', 'a', 'z', 'p', 'c'};
    uvt::pair__v<int, char> pv18(v1, v2);
    test::vector<int>(pv18.get_vec1(), v1);
    test::vector<char>(pv18.get_vec2(), v2);
}
void utest_19()
{
    io::print_category("unit test 19", 3, 60, '*');
    std::vector<int> v1 = {111, 97, 122, 112, 99};
    std::vector<char> v2 = {'Y', 'c', 'f', '~'};
    uvt::pair__v<int, char> pv18 = {{89, 99, 102, 126}, {{'o', 'a', 'z', 'p', 'c'}}};
    pv18.swap_vecs();
    test::vector<int>(pv18.get_vec1(), v1);
    test::vector<char>(pv18.get_vec2(), v2);
}
void utest_20()
{
    io::print_category("unit test 20", 3, 60, '*');
    uvt::pair__v<double, int> pv20 = {{2.8, 3.8, 8.9, 0.9}, {9, 12, 29, 38, 20}};
    int num = 3;
    double dnum = 1.8;
    pv20 + num;
    pv20 + dnum;
    std::vector<double> v1 = {3.8, 4.8, 10.7, 2.7};
    std::vector<int> v2 = {12, 15, 32, 41, 23};
    test::vector<double>(pv20.get_vec1(), v1);
    test::vector<int>(pv20.get_vec2(), v2);
}
void utest_21()
{
    io::print_category("unit test 21", 3, 60, '*');
    uvt::pair__v<short, int> pv21 = {{3, 9, 8, 3, 2}, {90, 39, 28, 39, 29, 29}};
    short num1 = 3;
    int num2 = 9;
    pv21 *num1;
    pv21 *num2;
    std::vector<short> v1 = {9, 27, 24, 9, 6};
    std::vector<int> v2 = {810, 351, 252, 351, 261, 261};
    test::vector<short>(pv21.get_vec1(), v1);
    test::vector<int>(pv21.get_vec2(), v2);
}
void utest_22()
{
    io::print_category("unit test 22", 3, 60, '*');
    uvt::pair__v<char, short> pv22 = {{'z', 'x', 'u'}, {88, 98, 29, 33}};
    pv22 - '0';
    pv22 - short(88);
    std::vector<char> v1 = {'J', 'H', 'E'};
    std::vector<short> v2 = {0, 10, -59, -55};
    test::vector<char>(pv22.get_vec1(), v1);
    test::vector<short>(pv22.get_vec2(), v2);
}
void utest_23()
{
    io::print_category("unit test 23", 3, 60, '*');
    uvt::pair__v<int, char> pv23 = {{88, 29, 38, 39}, {'~', '|', 'x'}};
    pv23 / int(4);
    pv23 / char(2);
    std::vector<int> v1 = {22, 7, 9, 9};
    std::vector<char> v2 = {'?', '>', '<'};
    test::vector<int>(pv23.get_vec1(), v1);
    test::vector<char>(pv23.get_vec2(), v2);
}
void utest_24()
{
    io::print_category("unit test 24", 3, 60, '*');
    uvt::pair__v<int, char> pv24 = {{9, 27, 24, 9, 6}, {'~', '|', 'x'}};
    std::vector<int> v1 = {3, 9, 2, 9, 3};
    std::vector<char> v2 = {'!', '*', '0'};
    pv24 - v1;
    pv24 - v2;
    std::vector<int> v3 = {6, 18, 22, 0, 2};
    std::vector<char> v4 = {']', 'R', 'H'};
    test::vector<int>(pv24.get_vec1(), v3);
    test::vector<char>(pv24.get_vec2(), v4);
}
void utest_25()
{
    io::print_category("unit test 25", 3, 60, '*');
    uvt::pair__v<int, double> pv25;
    pv25 = {{29, 38, 39, 23}, {2.9, 3.3, 2.3}};
    std::vector<int> v1 = {1, 2, 1, 7};
    std::vector<double> v2 = {1.1, 1.7, 0.7};
    pv25 + v1;
    pv25 + v2;
    std::vector<int> v3 = {30, 40, 40, 30};
    std::vector<double> v4 = {4, 5, 3};
    test::vector<int>(pv25.get_vec1(), v3);
    test::vector<double>(pv25.get_vec2(), v4);
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
    s << utest_6;
    s << utest_7;
    s << utest_8;
    s << utest_9;
    s << utest_10;
    s << utest_11;
    s << utest_12;
    s << utest_13;
    s << utest_14;
    s << utest_15;
    s << utest_16;
    s << utest_17;
    s << utest_18;
    s << utest_19;
    s << utest_20;
    s << utest_21;
    s << utest_22;
    s << utest_23;
    s << utest_24;
    s << utest_25;
    io::println("execution time for unit test 1: " + std::to_string(benchmark::execution_time<void>(utest_1)));
    io::println("execution time for unit test 2: " + std::to_string(benchmark::execution_time<void>(utest_2)));
    io::println("execution time for unit test 3: " + std::to_string(benchmark::execution_time<void>(utest_3)));
    io::println("execution time for unit test 4: " + std::to_string(benchmark::execution_time<void>(utest_4)));
    io::println("execution time for unit test 5: " + std::to_string(benchmark::execution_time<void>(utest_5)));
    io::println("execution time for unit test 6: " + std::to_string(benchmark::execution_time<void>(utest_6)));
    io::println("execution time for unit test 7: " + std::to_string(benchmark::execution_time<void>(utest_7)));
    io::println("execution time for unit test 8: " + std::to_string(benchmark::execution_time<void>(utest_8)));
    io::println("execution time for unit test 9: " + std::to_string(benchmark::execution_time<void>(utest_9)));
    io::println("execution time for unit test 10: " + std::to_string(benchmark::execution_time<void>(utest_10)));
    io::println("execution time for unit test 11: " + std::to_string(benchmark::execution_time<void>(utest_11)));
    io::println("execution time for unit test 12: " + std::to_string(benchmark::execution_time<void>(utest_12)));
    io::println("execution time for unit test 13: " + std::to_string(benchmark::execution_time<void>(utest_13)));
    io::println("execution time for unit test 14: " + std::to_string(benchmark::execution_time<void>(utest_14)));
    io::println("execution time for unit test 15: " + std::to_string(benchmark::execution_time<void>(utest_15)));
    io::println("execution time for unit test 16: " + std::to_string(benchmark::execution_time<void>(utest_16)));
    io::println("execution time for unit test 17: " + std::to_string(benchmark::execution_time<void>(utest_17)));
    io::println("execution time for unit test 18: " + std::to_string(benchmark::execution_time<void>(utest_18)));
    io::println("execution time for unit test 19: " + std::to_string(benchmark::execution_time<void>(utest_19)));
    io::println("execution time for unit test 20: " + std::to_string(benchmark::execution_time<void>(utest_20)));
    io::println("execution time for unit test 21: " + std::to_string(benchmark::execution_time<void>(utest_21)));
    io::println("execution time for unit test 22: " + std::to_string(benchmark::execution_time<void>(utest_22)));
    io::println("execution time for unit test 23: " + std::to_string(benchmark::execution_time<void>(utest_23)));
    io::println("execution time for unit test 24: " + std::to_string(benchmark::execution_time<void>(utest_24)));
    io::println("execution time for unit test 25: " + std::to_string(benchmark::execution_time<void>(utest_25)));
    return 0;
}
