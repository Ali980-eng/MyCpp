#include "E:\Myfiles\programing\c++\ProgrammingLibrarys\MyLibrarys\VT_Librarys\CXXVector.hpp"
#include "E:\Myfiles\programing\c++\ProgrammingLibrarys\MyLibrarys\lab\BOFramework\CXXLite.hpp"
void utest_1()
{
    io::print_category("unit test 1", 3, 60, '*');
    uvt::vector_2d<int> v1;
    test::basic<bool>(v1.empty(), true);
    test::basic(v1.general_matrix_type(), "Empty Matrix");
}
void utest_2()
{
    io::print_category("unit test 2", 3, 60, '*');
    uvt::vector_2d<int> v2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};
    test::basic(v2.general_matrix_type(), "Identity Matrix");
    test::basic<int>(v2.determinant(), 1);
    test::vector<int>(v2[1], {0, 1, 0});
}
void utest_3()
{
    io::print_category("unit test 3", 3, 60, '*');
    uvt::vector_2d<char> v3 = {2, 2, {{'c', 'i'}, {'o', 'p'}}};
    test::basic(v3.general_matrix_type(), "Square Matrix");
    test::basic<bool>(v3.is_fixed_size(), true);
    test::basic<char>(v3.get(1, 1), 'p');
}
void utest_4()
{
    io::print_category("unit test 4", 5, 60, '*');
    uvt::vector_2d<float> v4 = {
        {2, 0, 0},
        {0, 6, 0},
        {0, 0, 1}};
    test::basic(v4.general_matrix_type(), "Diagonal Matrix");
    test::basic<float>(v4.determinant(), 12);
}
void utest_5()
{
    io::print_category("unit test 5", 3, 60, '*');
    uvt::vector_2d<int> v5 = {
        {1, 2, 8},
        {0, 8, 9},
        {0, 0, 5}};
    test::basic(v5.general_matrix_type(), "Upper Triangular Matrix");
    test::basic<int>(v5.determinant(), 40);
}
void utest_6()
{
    io::print_category("unit test 6", 3, 60, '*');
    uvt::vector_2d<double> v6 = {
        {1.7, 0, 0},
        {2.8, 1.3, 0},
        {5.9, 4.6, 6.6},
    };
    test::basic(v6.general_matrix_type(), "Lower Triangular Matrix");
    test::basic<int>(v6.determinant(), 14.586);
}
void utest_7()
{
    io::print_category("unit test 7", 3, 60, '*');
    uvt::vector_2d<int> v7 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 2, 9}};
    test::basic(v7.general_matrix_type(), "Square Matrix");
    test::basic<int>(v7.determinant(), -36);
}
void utest_8()
{
    io::print_category("unit test 8", 3, 60, '*');
    uvt::vector_2d<int> v8 = {
        {12, 32, 23, 11},
        {55, 25, 62, 19},
        {34, 44, 88, 77},
        {65, 12, 14, 75}};
    test::basic(v8.general_matrix_type(), "Square Matrix");
    test::basic<int>(v8.determinant(), -7770447);
}
void utest_9()
{
    io::print_category("unit test 9", 3, 60, '*');
    uvt::vector_2d<char> v9 = {
        {'c', ',', 'o'},
        {'u', 'o', 'w'},
        {'q', 'g', 'n'}};
    const std::vector<char> stdv9 = {'c', ',', 'o', 'u', 'o', 'w', 'q', 'g', 'n'};
    test::vector<char>(v9.get_flatten(), stdv9);
    test::basic<char>(v9.get_flatten(2), v9.get(0, 2));
    test::vector<char>(v9.get(1), {'u', 'o', 'w'});
}
void utest_10()
{
    io::print_category("unit test 10", 3, 60, '*');
    uvt::vector_2d<int> v10 = {
        {10, 18, 12},
        {11, 97, 92}};
    std::vector<std::vector<int>> stdv10 = {
        {10, 11},
        {18, 97},
        {12, 92}};
    test::vector_2d<int>(stdv10, v10.get_transpose());
    v10.clear(1);
    test::basic<bool>(v10.empty(1), true);
    test::basic<bool>(v10.empty(0), false);
    v10.clear();
    test::basic<bool>(v10.empty(), true);
}
void utest_11()
{
    io::print_category("unit test 11", 3, 60, '*');
    uvt::vector_2d<char> v11 = {
        {'c', 'p', 'p'},
        {'g', '+', '+'},
        {'2', 'h', 'o'}};
    size_t before_size = v11.size(2);
    v11.pop(2);
    test::basic<size_t>(v11.size(2), before_size - 1);
    before_size = v11.size();
    v11.pop();
    test::basic<size_t>(v11.size(), before_size - 1);
    std::vector<char> stdv11 = {'o', '-', '-'};
    v11.push(stdv11);
    test::vector<char>(v11.get(2), stdv11);
    v11.push(1, 'i');
    test::basic<size_t>(v11.last_index(1), 3);
    test::basic<size_t>(v11.last_index(), 2);
}
void utest_12()
{
    io::print_category("unit test 12", 3, 60, '*');
    uvt::vector_2d<int> v12 = {
        {1, 8, 9},
        {2, 9}};
    std::vector<std::vector<int>> stdv12 = {
        {1, 8, 9},
        {2, 9}};
    test::basic<bool>(v12 == stdv12, true);
    stdv12[1].push_back(11);
    test::basic<bool>(v12 == stdv12, false);
}
void utest_13()
{
    io::print_category("unit test 13", 3, 60, '*');
    uvt::vector_2d<short> v13 = {
        {8, 9, 12},
        {10, 2, 3},
        {9, 11, 3}};
    std::vector<std::vector<short>> stdv13 = {
        {16, 17, 20},
        {18, 10, 11},
        {17, 19, 11}};
    v13 += 8;
    test::vector_2d<short>(v13.get(), stdv13);
}
void utest_14()
{
    io::print_category("unit test 14", 3, 60, '*');
    uvt::vector_2d<short> v14 = {
        {8, 9, 12},
        {10, 2, 3},
        {9, 11, 3}};
    std::vector<std::vector<short>> stdv14 = {
        {6, 7, 10},
        {8, 0, 1},
        {7, 9, 1}};
    v14 -= 2;
    test::vector_2d<short>(v14.get(), stdv14);
}
void utest_15()
{
    io::print_category("unit test 15", 3, 60, '*');
    uvt::vector_2d<short> v15 = {
        {8, 9, 12},
        {10, 2, 3},
        {9, 11, 3}};
    std::vector<std::vector<short>> stdv15 = {
        {80, 90, 120},
        {100, 20, 30},
        {90, 110, 30}};
    v15 *= 10;
    test::vector_2d<short>(v15.get(), stdv15);
}
void utest_16()
{
    io::print_category("unit test 16", 3, 60, '*');
    uvt::vector_2d<float> v16 = {
        {8, 9, 12},
        {10, 2, 3},
        {9, 11, 3}};
    std::vector<std::vector<float>> stdv16 = {
        {4, 4.5, 6},
        {5, 1, 1.5},
        {4.5, 5.5, 1.5}};
    v16 /= 2;
    test::vector_2d<float>(v16.get(), stdv16);
}
void utest_17()
{
    io::print_category("unit test 17", 3, 60, '*');
    uvt::vector_2d<char> v17 = {
        {'c', 'i'},
        {'o', ','}};
    std::vector<char> stdv17 = {'c', 'i'};
    test::vector<char>(v17[0], stdv17);
}
void utest_18()
{
    io::print_category("unit test 18", 3, 60, '*');
    uvt::vector_2d<char> v18 = {
        {'c', 'i'},
        {'o', ','}};
    int d = v18.determinant();
    test::basic<int>(d, -7299);
}
void utest_19()
{
    io::print_category("unit test 19", 3, 60, '*');
    uvt::vector_2d<short> v19 = {
        {8, 9, 12},
        {10, 2, 3},
        {9, 11, 3}};
    std::vector<std::vector<short>> stdv19 = {
        {6, 7, 10},
        {8, 0, 1},
        {7, 9, 1}};
    std::vector<std::vector<short>> stdv19_1 = {
        {14, 16, 22},
        {18, 2, 4},
        {16, 20, 4}};
    v19 += stdv19;
    test::vector_2d<short>(v19.get(), stdv19_1);
}
void utest_20()
{
    io::print_category("unit test 20", 3, 60, '*');
    uvt::vector_2d<short> v20 = {
        {8, 9, 12},
        {10, 2, 3},
        {9, 11, 3}};
    std::vector<std::vector<short>> stdv20 = {
        {6, 7, 3},
        {7, 3, 1},
        {7, 9, 1}};
    std::vector<std::vector<short>> stdv20_1 = {
        {2, 2, 9},
        {3, -1, 2},
        {2, 2, 2}};
    v20 -= stdv20;
    test::vector_2d<short>(v20.get(), stdv20_1);
}
void utest_21()
{
    io::print_category("unit test 21", 3, 60, '*');
    uvt::vector_2d<short> v21 = {
        {18, 88, 12},
        {10, 28},
        {19},
        {29, 33, 55, 32}};
    test::basic(v21.general_matrix_type(), "Invalid Matrix");
    v21.push(0, 98);
    v21.push(1, 78);
    v21.push(1, 62);
    v21.push(2, 12);
    v21.push(2, 36);
    v21.push(2, 51);
    test::basic(v21.general_matrix_type(), "Square Matrix");
    test::basic<long double>(v21.determinant(), -5396064);
}
void utest_22()
{
    io::print_category("unit test 22", 3, 60, '*');
    uvt::vector_2d<short> v22 = {
        {8, 8, 2, 9},
        {0, 2, 8, 6},
        {9, 1, 6, 5},
        {9, 3, 5, 2}};
    std::vector<std::vector<short>> stdv22 = {
        {64, 64, 4, 81},
        {0, 4, 64, 36},
        {81, 1, 36, 25},
        {81, 9, 25, 4}};
    v22 ^= 2;
    test::vector_2d<short>(v22.get(), stdv22);
}
void utest_23()
{
    io::print_category("unit test 23", 3, 60, '*');
    uvt::vector_2d<short> v23 = {
        {8, 8, 2, 9},
        {0, 2, 8, 6},
        {9, 1, 6, 5},
        {9, 3, 5, 2}};
    std::vector<std::vector<short>> stdv23_1 = {
        {1, 1, 2, 2},
        {8, 3, 2, 3},
        {1, 4, 4, 3},
        {3, 6, 5, 9}};
    v23 ^= stdv23_1;
    std::vector<std::vector<short>> stdv23_2 = {
        {8, 8, 4, 81},
        {0, 8, 64, 216},
        {9, 1, 1296, 125},
        {729, 729, 3125, 512}};
    test::vector_2d<short>(v23.get(), stdv23_2);
}
void utest_24()
{
    io::print_category("unit test 24", 3, 60, '*');
    uvt::vector_2d<int> v24 = {
        {8, 8, 2, 9},
        {0, 2, 8, 6},
        {9, 1, 6, 5},
        {9, 3, 5, 2}};
    uvt::vector_2d<int> v24_1 = {
        {1, 1, 2, 2},
        {8, 3, 2, 3},
        {1, 4, 4, 3},
        {3, 6, 5, 9}};
    v24 ^= v24_1;
    std::vector<std::vector<int>> v24_2 = {
        {8, 8, 4, 81},
        {0, 8, 64, 216},
        {9, 1, 1296, 125},
        {729, 729, 3125, 512}};
    test::vector_2d<int>(v24.get(), v24_2);
}
void utest_25()
{

    io::print_category("unit test 25", 3, 60, '*');
    uvt::vector_2d<int> v25 = {
        {8, 9, 12},
        {10, 2, 3},
        {9, 11, 3}};
    uvt::vector_2d<int> v25_1 = {
        {6, 7, 3},
        {7, 3, 1},
        {7, 9, 1}};
    std::vector<std::vector<int>> v25_2 = {
        {2, 2, 9},
        {3, -1, 2},
        {2, 2, 2}};
    v25 -= v25_1;
    test::vector_2d<int>(v25.get(), v25_2);
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
}