#include "CXXVector.hpp"
#include "CXXLite.hpp"
void utest_1()
{
    io::print_category("unit test 1", 3, 60, '*');
    uvt::vector_3d<int> v1;
    test::basic<bool>(v1.empty(), true);
    v1 = {
        {{1, 2, 3},
         {4, 5, 6}},
        {{7, 8, 9},
         {10, 11, 12}}};
    test::basic<int>(v1.get(1, 0, 2), 9);
    test::basic<size_t>(v1.size(), 2);
    test::basic<size_t>(v1.size(0), 2);
    test::basic<size_t>(v1.size(1, 1), 3);
}
void utest_2()
{
    io::print_category("unit test 2", 3, 60, '*');
    uvt::vector_3d<char> v2 = {
        {{'c', 'i'},
         {'o', 'p'}},
        {{'p', 'y'},
         {'t', 'h'}},
        {{'o', 'n'},
         {'-', '-'}}};
    std::vector<std::vector<std::vector<char>>> stdv2 = {
        {{'c', 'i'},
         {'o', 'p'}},
        {{'p', 'y'},
         {'t', 'h'}},
        {{'o', 'n'},
         {'-', '-'}}};
    test::basic<bool>(v2 == stdv2, true);
    stdv2[1][1][1] = 'o';
    test::basic<bool>(v2 == stdv2, false);
    test::basic<char>(v2.at(2, 0, 1), 'n');
    test::vector<char>(v2.at(2, 1), stdv2[2][1]);
    test::vector_2d<char>(v2.at(0), stdv2[0]);
}
void utest_3()
{
    io::print_category("unit test 3", 3, 60, '*');
    uvt::vector_3d<double> v3 = {
        {{1.1, 2.2, 3.3},
         {4.4, 5.5, 6.6}},
        {{7.7, 8.8, 9.9},
         {10.1, 11.11, 12.12}}};
    std::vector<std::vector<std::vector<double>>> stdv3 = {
        {{1.1, 2.2, 3.3},
         {4.4, 5.5, 6.6}},
        {{7.7, 8.8, 9.9},
         {10.1, 11.11, 12.12}}};
    test::basic<bool>(v3 == stdv3, true);
    test::basic<double>(v3.at(0, 1, 2), 6.6);
    test::basic<size_t>(v3.size(1), 2);
    test::vector<double>(v3.at(1, 0), stdv3[1][0]);
    test::vector_2d<double>(v3.at(0), stdv3[0]);
}
void utest_4()
{
    io::print_category("unit test 4", 3, 60, '*');
    uvt::vector_3d<int> v4 = {
        {{1, 2, 3},
         {4, 5, 6}},
        {{7, 8, 9},
         {10, 11, 12}}};
    test::basic<size_t>(v4.size(1), 2);
    v4.pop(1);
    test::basic<size_t>(v4.size(1), 1);
    v4.push(1, {13, 18, 99});
    test::basic<size_t>(v4.size(1), 2);
    test::basic<int>(v4.at(1, 1, 2), 99);
    v4.clear();
    test::basic<bool>(v4.empty(), true);
}
void utest_5()
{
    io::print_category("unit test 5", 3, 60, '*');
    uvt::vector_3d<int> v5(3, 3, 3);
    v5 = {
        {{1, 2, 3},
         {4, 5, 6},
         {7, 8, 9}},
        {{10, 11, 12},
         {13, 14, 15},
         {16, 17, 18}},
        {{19, 20, 21},
         {22, 23, 24},
         {25, 26, 27}}};
    test::basic<bool>(v5.empty(), false);
    test::basic<size_t>(v5.size(), 3);
    test::basic<size_t>(v5.size(0), 3);
    test::basic<size_t>(v5.size(1, 1), 3);
    test::basic<bool>(v5.is_fixed_size(), true);
}
void utest_6()
{
    io::print_category("unit test 6", 3, 60, '*');
    uvt::vector_3d<int> v6 = {
        {{1, 2},
         {3, 4}},
        {{5, 6},
         {7, 8}},
        {{9, 10},
         {11, 12}}};
    std::vector<std::vector<std::vector<int>>> transposed = v6.get_transpose();
    std::vector<std::vector<std::vector<int>>> expected = {
        {{1, 2},
         {5, 6},
         {9, 10}},
        {{3, 4},
         {7, 8},
         {11, 12}}};
    test::basic<bool>(transposed == expected, true);
    std::vector<std::vector<int>> flattened;
    v6.get_flatten(flattened);
    std::vector<std::vector<int>> expected_flattened = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
        {9, 10},
        {11, 12}};
    test::basic<bool>(flattened == expected_flattened, true);
}
void utest_7()
{
    io::print_category("unit test 7", 3, 60, '*');
    uvt::vector_3d<int> v7 = {
        {{1, 2, 3},
         {4, 5, 6}},
        {{7, 8, 9},
         {10, 11, 12}}};
    test::basic<int>(v7.last_index(), 1);
    test::basic<int>(v7.last_index(0), 1);
    v7.pop(0);
    test::basic<int>(v7.last_index(0), 0);
    test::basic<int>(v7.last_index(0, 0), 2);
    v7.push(0, {16, 17, 18});
    test::basic<int>(v7.last_index(0), 1);
}
void utest_8()
{
    io::print_category("unit test 8", 3, 60, '*');
    uvt::vector_3d<double> v8 = {
        {{4.0, 3.0},
         {6.0, 3.0}},
        {{1.0, 2.0},
         {1.0, 4.0}}};
    test::basic<size_t>(v8.size(), 2);
    test::basic<size_t>(v8.size(0), 2);
    test::basic<size_t>(v8.size(1, 0), 2);
    v8.clear();
    test::basic<bool>(v8.empty(), true);
    v8 = {
        {{4.0, 3.0},
         {6.0, 3.0}},
        {{1.0, 2.0},
         {1.0, 4.0}}};
    v8.clear(1);
    test::basic<bool>(v8.empty(1), true);
    test::basic<bool>(v8.empty(), false);
}
void utest_9()
{
    io::print_category("unit test 9", 3, 60, '*');
    uvt::vector_3d<int> v9 = {
        {{1, 2, 3},
         {4, 5, 6}},
        {{7, 8, 9},
         {10, 11, 12}}};
    v9 += 9;
    std::vector<std::vector<std::vector<int>>> expected = {
        {{10, 11, 12},
         {13, 14, 15}},
        {{16, 17, 18},
         {19, 20, 21}}};
    std::vector<std::vector<int>> v1 = expected[0];
    test::vector_3d<int>(v9.get(), expected);
    test::vector_2d<int>(v9[0], v1);
}
void utest_10()
{
    io::print_category("unit test 10", 3, 60, '*');
    uvt::vector_3d<double> v10 = {
        {{4.0, 3.0},
         {6.0, 3.0}},
        {{1.0, 2.0},
         {1.0, 4.0}}};
    v10 *= 2.0;
    std::vector<std::vector<std::vector<double>>> expected = {
        {{8.0, 6.0},
         {12.0, 6.0}},
        {{2.0, 4.0},
         {2.0, 8.0}}};
    test::vector_3d<double>(v10.get(), expected);
    test::vector_2d<double>(v10[1], expected[1]);
}
void utest_11()
{
    io::print_category("unit test 11", 3, 60, '*');
    uvt::vector_3d<int> v11 = {
        {{1, 2, 3},
         {4, 5, 6}},
        {{7, 8, 9},
         {10, 11, 12}}};
    v11 -= 1;
    std::vector<std::vector<std::vector<int>>> expected = {
        {{0, 1, 2},
         {3, 4, 5}},
        {{6, 7, 8},
         {9, 10, 11}}};
    test::vector_3d<int>(v11.get(), expected);
    test::vector_2d<int>(v11[1], expected[1]);
}
void utest_12()
{
    io::print_category("unit test 12", 3, 60, '*');
    uvt::vector_3d<double> v12 = {
        {{4.0, 3.0},
         {6.0, 3.0}},
        {{1.0, 2.0},
         {1.0, 4.0}}};
    v12 /= 2.0;
    std::vector<std::vector<std::vector<double>>> expected = {
        {{2.0, 1.5},
         {3.0, 1.5}},
        {{0.5, 1.0},
         {0.5, 2.0}}};
    test::vector_3d<double>(v12.get(), expected);
    test::vector_2d<double>(v12[1], expected[1]);
}
void utest_13()
{
    io::print_category("unit test 13", 3, 60, '*');
    uvt::vector_3d<int> v13 = {
        {{1, 2, 3},
         {4, 5, 6}},
        {{7, 8, 9},
         {10, 11, 12}}};
    v13 ^= 2;
    std::vector<std::vector<std::vector<int>>> expected = {
        {{1, 4, 9},
         {16, 25, 36}},
        {{49, 64, 81},
         {100, 121, 144}}};
    test::vector_3d<int>(v13.get(), expected);
}
void utest_14()
{
    io::print_category("unit test 14", 3, 60, '*');
    uvt::vector_3d<double> v14 = {
        {{4.0, 3.0},
         {6.0, 3.0}},
        {{1.0, 2.0},
         {1.0, 4.0}}};
    std::vector<std::vector<std::vector<double>>> sumvec = {
        {{1.0, 1.0},
         {1.0, 1.0}},
        {{1.0, 1.0},
         {1.0, 1.0}}};
    v14 += sumvec;
    std::vector<std::vector<std::vector<double>>> expected = {
        {{5.0, 4.0},
         {7.0, 4.0}},
        {{2.0, 3.0},
         {2.0, 5.0}}};
    test::vector_3d<double>(v14.get(), expected);
}
void utest_15()
{
    io::print_category("unit test 15", 3, 60, '*');
    uvt::vector_3d<int> v15 = {
        {{1, 2, 3},
         {4, 5, 6}},
        {{7, 8, 9},
         {10, 11, 12}}};
    std::vector<std::vector<std::vector<int>>> mulvec = {
        {{1, 0, 1},
         {0, 1, 0}},
        {{1, 1, 1},
         {0, 0, 0}}};
    v15 *= mulvec;
    std::vector<std::vector<std::vector<int>>> expected = {
        {{1, 0, 3},
         {0, 5, 0}},
        {{7, 8, 9},
         {0, 0, 0}}};
    test::vector_3d<int>(v15.get(), expected);
}
void utest_16()
{
    io::print_category("unit test 16", 3, 60, '*');
    uvt::vector_3d<double> v16 = {
        {{4.0, 3.0},
         {6.0, 3.0}},
        {{1.0, 2.0},
         {1.0, 4.0}}};
    std::vector<std::vector<std::vector<double>>> divvec = {
        {{2.0, 1.0},
         {3.0, 1.0}},
        {{1.0, 2.0},
         {1.0, 2.0}}};
    v16 /= divvec;
    std::vector<std::vector<std::vector<double>>> expected = {
        {{2.0, 3.0},
         {2.0, 3.0}},
        {{1.0, 1.0},
         {1.0, 2.0}}};
    test::vector_3d<double>(v16.get(), expected);
}
void utest_17()
{
    io::print_category("unit test 17", 3, 60, '*');
    uvt::vector_3d<int> v17 = {
        {{1, 2, 3},
         {4, 5, 6}},
        {{7, 8, 9},
         {10, 11, 12}}};
    std::vector<std::vector<std::vector<int>>> expvec = {
        {{1, 4, 9},
         {16, 25, 36}},
        {{49, 64, 81},
         {100, 121, 144}}};
    v17 ^= 2;
    test::vector_3d<int>(v17.get(), expvec);
}
void utest_18()
{
    io::print_category("unit test 18", 3, 60, '*');
    uvt::vector_3d<double> v18 = {
        {{4.0, 3.0},
         {6.0, 3.0}},
        {{1.0, 2.0},
         {1.0, 4.0}}};
    std::vector<std::vector<std::vector<double>>> matrices = {
        {{4.0, 3.0},
         {6.0, 3.0}},
        {{1.0, 2.0},
         {1.0, 4.0}}};
    v18 -= matrices;
    std::vector<std::vector<std::vector<double>>> expected = {
        {{0.0, 0.0},
         {0.0, 0.0}},
        {{0.0, 0.0},
         {0.0, 0.0}}};
    test::vector_3d<double>(v18.get(), expected);
}
void utest_19()
{
    io::print_category("unit test 19", 3, 60, '*');
    uvt::vector_3d<double> v19 = {
        {{4.0, 3.0},
         {6.0, 3.0}},
        {{1.0, 2.0},
         {1.0, 4.0}}};
    test::basic<bool>(v19.is_cude2X2X2(), true);
    std::vector<std::vector<double>> push_vector2d = {{1.0, 2.0}, {3.0, 4.0}};
    v19.push(push_vector2d);
    test::basic<bool>(v19.is_cude2X2X2(), false);
    v19 = {
        {{1.0, 2.0, 3.0},
         {4.0, 5.0, 6.0},
         {7.0, 8.0, 9.0}},
        {{10.0, 11.0, 12.0},
         {13.0, 14.0, 15.0},
         {16.0, 17.0, 18.0}},
        {{19.0, 20.0, 21.0},
         {22.0, 23.0, 24.0},
         {25.0, 26.0, 27.0}}};
    std::vector<long double> dets = v19.get_determinant_vec();
    std::vector<long double> expected_dets = {0.0, 0.0, 0.0};
    test::vector<long double>(dets, expected_dets);
    test::basic<bool>(v19.is_cude3X3X3(), true);
    test::basic<double>(v19.get_determinant(0), 0.0);
}
void utest_20()
{
    io::print_category("unit test 20", 3, 60, '*');
    uvt::vector_3d<int> v20 = {
        {{1, 2, 3},
         {4, 5, 6}},
        {{7, 8, 9},
         {10, 11, 12}}};
    test::basic<bool>(v20.is_sizeNXMXW(2, 2, 3), true);
    test::basic<bool>(v20.is_sizeNXMXW(2, 3, 3), false);
    std::vector<std::vector<std::vector<int>>> checkvec = {
        {{1, 2, 3},
         {4, 5, 6}},
        {{7, 8, 9},
         {10, 11, 12}}};
    test::basic<bool>(v20.is_sizeNXMXW(2, 2, 3, checkvec), true);
    test::basic<bool>(v20.is_sizeNXMXW(2, 3, 3, checkvec), false);
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
    return 0;
}
