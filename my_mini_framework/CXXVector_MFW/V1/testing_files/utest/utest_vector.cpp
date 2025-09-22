#include "CXXVector.hpp"
#include "CXXLite.hpp"
void utest_1()
{
    io::print_category("unit test 1");
    uvt::vector<int> v1;
    test::basic<bool>(true, v1.empty());
}
void utest_2()
{
    io::print_category("unit test 2");
    uvt::vector<int> v2 = {10, 19, 18};
    test::basic<bool>(false, v2.is_fixed_size());
}
void utest_3()
{
    io::print_category("unit test 3");
    uvt::vector<int> v3 = {3, {10, 88, 99}};
    test::basic<size_t>(3, v3.size());
}
void utest_4()
{
    io::print_category("unit test 4");
    std::vector<char> stdv4 = {'c', 'l', 'i', 'e'};
    uvt::vector<char> v4(stdv4);
    test::vector<char>(stdv4, v4.get());
}
void utest_5()
{
    io::print_category("unit test 5");
    uvt::vector<char> v5(3);
    test::basic<bool>(true, v5.is_fixed_size());
    test::basic<size_t>(3, v5.size());
    v5.resize(5);
    test::basic<size_t>(5, v5.size());
}
void utest_6()
{
    io::print_category("unit test 6");
    uvt::vector<float> v6 = {0, 10, 39, 88};
    std::vector<float> stdv6 = {0, 10, 39, 88};
    test::basic<bool>(true, v6 == stdv6);
}
void utest_7()
{
    io::print_category("unit test 7");
    uvt::vector<double> v7 = {1.2, 2.8, 1.5, 2.5};
    test::basic<double>(9.5, v7.sum(1.5));
    test::basic<double>(1.5, v7.at(2));
}
void utest_8()
{
    io::print_category("unit test 8");
    uvt::vector<char> v8 = {'u', 't', 'e', 's', 't'};
    v8.clear();
    test::basic<bool>(true, v8.empty());
}
void utest_9()
{
    io::print_category("unit test 9");
    std::vector<int> stdv9 = {19, 88, 34};
    uvt::vector<int> v9 = {34, 88, 19};
    test::vector<int>(stdv9, v9.reverse());
}
void utest_10()
{
    io::print_category("unit test 10");
    uvt::vector<int> v10 = {10, 11, 5};
    test::basic<int>(550, v10.multiply());
}
void utest_11()
{
    io::print_category("unit test 11");
    uvt::vector<double> v11 = {1, 3, 5, 1};
    test::basic<double>(0.1, v11.divide());
}
void utest_12()
{
    io::print_category("unit test 12");
    uvt::vector<char> v12 = {'a', 's', 'i', 'l'};
    v12.push_front('o');
    test::basic<char>('o', v12[0]);
    v12.pop_back();
    test::basic<char>('i', v12.top_back());
}
bool fun1(int number)
{
    if (number > 10)
        return true;
    return false;
}
void utest_13()
{
    io::print_category("unit test 13");
    uvt::vector<int> v13 = {1, 8, 19, 3, 2};
    v13.push_front(fun1, 10);
    test::basic(10, v13[2]);
    test::basic(1, v13.top_front());
    test::basic(2, v13.top_back());
    v13.pop_front();
    test::basic(8, v13.top_front());
}
void utest_14()
{
    io::print_category("unit test 14");
    uvt::vector<char> v14 = {'u', 'i', 'e', 'o'};
    test::basic<bool>(false, v14.find('z'));
    test::basic<bool>(true, v14.find('i'));
}
bool even_num(int num)
{
    if (num % 2 == 0)
        return true;
    return false;
}
bool fun2(int num)
{
    if (num > 20)
        return true;
    return false;
}
void utest_15()
{
    io::print_category("unit test 15");
    uvt::vector<int> v15 = {15, 9, 7, 10, 11, 13};
    test::basic<bool>(true, v15.find(even_num));
    test::basic<bool>(false, v15.find(fun2));
}
bool fun3(char ch)
{
    if (ch == 'l')
        return true;
    return false;
}
void utest_16()
{
    io::print_category("unit test 16");
    uvt::vector<char> v16 = {'y', 'o', 'u', 'm', 'y', 'l', 'o', 'v', 'e'};
    test::basic<int>(5, v16.find_index('l'));
    test::basic<int>(5, v16.find_index(fun3));
}
bool fun4(char ch)
{
    if (ch == 'e')
        return true;
    return false;
}
void utest_17()
{
    io::print_category("unit test 17");
    uvt::vector<char> v17 = {'y', 'o', 'm', 'l', 'o', 'e'};
    v17.erase('m');
    test::basic<bool>(false, v17.find('m'));
    v17.erase_index(2);
    test::basic<bool>(false, v17.find('l'));
    v17.erase(fun4);
    test::basic<bool>(false, v17.find('e'));
}
void utest_18()
{
    io::print_category("unit test 18");
    uvt::vector<float> v18 = {0, 10, 39, 88};
    std::vector<float> stdv18 = {6, 16, 45, 94};
    v18 + 6;
    test::vector<float>(stdv18, v18.get());
}
void utest_19()
{
    io::print_category("unit test 19");
    uvt::vector<float> v19 = {0, 10, 39, 88};
    std::vector<float> stdv19 = {0, 1, 3.9, 8.8};
    v19 / 10;
    test::vector<float>(stdv19, v19.get());
}
void utest_20()
{
    io::print_category("unit test 20");
    uvt::vector<float> v20 = {0, 10, 39, 88};
    std::vector<float> stdv20 = {0, 100, 390, 880};
    v20 * 10;
    test::vector<float>(stdv20, v20.get());
}
void utest_21()
{
    io::print_category("unit test 21");
    uvt::vector<int> v21 = {10, 98, 38, 29};
    std::vector<int> stdv21 = {-10, 78, 18, 9};
    v21 - 20;
    test::vector<int>(stdv21, v21.get());
}
void utest_22()
{
    io::print_category("unit test 22");
    uvt::vector<int> v22 = {10, 98, 38, 29};
    const std::vector<int> stdv22 = {-10, 52, 21, 11};
    std::vector<int> real_value = {20, 46, 17, 18};
    v22 - stdv22;
    test::vector<int>(real_value, v22.get());
}
void utest_23()
{
    io::print_category("unit test 23");
    uvt::vector<int> v23 = {10, 98, 38, 29};
    v23.add_after(38, 99);
    test::basic<int>(99, v23[3]);
    test::basic<bool>(true, v23.find(99));
}
void utest_24()
{
    io::print_category("unit test 24");
    uvt::vector<std::string> v24 = {"ean", "eon", "enwm"};
    v24.add_before("eon", "iiii");
    test::basic("iiii", v24[1]);
    test::basic<bool>(true, v24.find("iiii"));
}
void utest_25()
{
    io::print_category("unit test 25");
    uvt::vector<int> v25 = {25, 28, 18, 29, 29, 8, 4, 3, 2, 5, 15, 16, 18, 19, 11};
    std::vector<int> stdv25 = {5, 2, 3, 4, 8};
    test::basic<int>(15, int(v25.average()));
    v25.pop_front();
    test::basic<bool>(false, v25.find(25));
    test::vector<int>(stdv25, v25.reverse(5, 9));
}
int main()
{
    io::NewLines(4);
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
