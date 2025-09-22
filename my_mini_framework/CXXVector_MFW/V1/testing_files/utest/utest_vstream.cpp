#include "CXXVector.hpp"
#include "CXXLite.hpp"
void utest_1()
{
    io::print_category("utest_1", 3, 60, '*');
    uvt::vstream<int> vs;
    test::basic<bool>(vs.empty(), true);
    vs << 24;
    vs << 99;
    test::basic<int>(vs[1], 99);
    test::basic<int>(vs[0], 24);
    test::basic<size_t>(vs.size(), 2);
}
void utest_2()
{
    io::print_category("utest_2", 3, 60, '*');
    uvt::vstream<char> vs({'a', 'b', 'c'});
    test::basic<size_t>(vs.size(), 3);
    test::basic<char>(vs[0], 'a');
    test::basic<char>(vs[1], 'b');
    test::basic<char>(vs[2], 'c');
    char ch;
    vs >> ch;
    test::basic<char>(ch, 'c');
    test::basic<size_t>(vs.size(), 2);
}
void utest_3()
{
    io::print_category("utest_3", 3, 60, '*');
    uvt::vstream<float> vs = {2.7, 3.14f, 1.414f};
    test::basic<size_t>(vs.size(), 3);
    test::basic<float>(vs[0], 2.7f);
    test::basic<float>(vs[1], 3.14f);
    test::basic<float>(vs[2], 1.414f);
    test::basic<bool>(vs.empty(), false);
    vs.clear();
    test::basic<bool>(vs.empty(), true);
}
void utest_4()
{
    io::print_category("utest_4", 3, 60, '*');
    uvt::vstream<std::string> vs;
    test::basic<bool>(vs.empty(), true);
    vs << "hello";
    vs << "world";
    test::basic<std::string>(vs[0], "hello");
    test::basic<std::string>(vs[1], "world");
    test::basic<size_t>(vs.size(), 2);
    std::string str;
    vs >> str;
    test::basic<std::string>(str, "world");
    test::basic<size_t>(vs.size(), 1);
}
void utest_5()
{
    io::print_category("utest_5", 3, 60, '*');
    std::vector<int> vec = {1, 2, 3, 4, 5};
    uvt::vstream<int> vs(vec);
    test::basic<size_t>(vs.size(), 5);
    test::basic<size_t>(vs.capacity(), vec.capacity());
    for (int i = 0; i < 5; i++)
        test::basic<int>(vs[i], i + 1);
}
int main()
{
    function::stream_t<void, true> s;
    s << utest_1;
    s << utest_2;
    s << utest_3;
    s << utest_4;
    s << utest_5;
    return 0;
}
