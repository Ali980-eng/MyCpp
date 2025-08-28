#include <cassert>
#include "E:\Myfiles\programing\c++\ProgrammingLibrarys\MyLibrarys\lab\Dynamic.hpp"
#include "E:\Myfiles\programing\c++\ProgrammingLibrarys\MyLibrarys\lab\test_tools.hpp"
using namespace std;
void test_1(int expected)
{
    udt::dynamic dd1(expected);
    test<int>(dd1.get_int(), expected);
}
void test_2(int expected)
{
    udt::dynamic dd2 = expected;
    test<int>(dd2.get_int(), expected);
}
void test_3(int num1, int num2)
{
    udt::dynamic dd3 = num1;
    dd3 *= num2;
    int expected = (num1 * num2);
    test<int>(dd3.get_int(), expected);
}
void test_4(int num1, int num2)
{
    udt::dynamic dd4 = num1;
    dd4 += num2;
    int expected = (num1 + num2);
    test<int>(dd4.get_int(), expected);
}
void test_5(int num1, int num2)
{
    udt::dynamic dd5 = num1;
    dd5 ^= num2;
    int expected = pow(num1, num2);
    test<int>(dd5.get_int(), expected);
}
void test_6(int num1, int num2)
{
    udt::dynamic dd6 = num1;
    dd6 /= num2;
    int expected = (num1 / num2);
    test<int>(dd6.get_int(), expected);
}
void test_7(float fnum)
{
    udt::dynamic dd7 = fnum;
    test<float>(dd7.get_float(), fnum);
}
void test_8(float fnum1, float fnum2)
{
    udt::dynamic dd8 = fnum1;
    dd8 += fnum2;
    float expected = (fnum1 + fnum2);
    test<float>(dd8.get_float(), expected);
}
void test_9(float fnum1, float fnum2)
{
    udt::dynamic dd9 = fnum1;
    dd9 *= fnum2;
    float expected = (fnum1 * fnum2);
    test<float>(dd9.get_float(), expected);
}
void test_10(float fnum1, float fnum2)
{
    udt::dynamic dd10 = fnum1;
    dd10 /= fnum2;
    float expected = (fnum1 / fnum2);
    test<float>(dd10.get_float(), expected);
}
void test_11(float fnum1, float fnum2)
{
    udt::dynamic dd11 = fnum1;
    dd11 ^= fnum2;
    float expected = pow(fnum1, fnum2);
    test<float>(dd11.get_float(), expected);
}
void test_11_20(int num, float fnum, double dnum, char c)
{
    udt::dynamic dd11_20;
    dd11_20.complex();
    dd11_20 = num;
    dd11_20 = fnum;
    dd11_20 = dnum;
    dd11_20 = c;
    test<bool>(dd11_20.is_complex(), true);
    test<string>(dd11_20.get_name(), "complex");
    test<int>(dd11_20.get_int(), num);
    test<float>(dd11_20.get_float(), fnum);
    test<double>(dd11_20.get_double(), dnum);
    test<char>(dd11_20.get_char(), c);
    dd11_20.clear_char();
    test<bool>(dd11_20.is_pure_numeric(), true);
    dd11_20.uncomplex(false);
    dd11_20 %= 5;
    test<int>(dd11_20.get_int(), num % 5);
    dd11_20.clear_all();
    test<bool>(dd11_20.is_empty(), true);
    dd11_20 = dnum;
    dd11_20 ^= 3.0;
    test<double>(dd11_20.get_double(), pow(dnum, 3));
}
void test_21(int num, char c, float fnum, double dnum, bool b)
{
    vector<udt::dynamic> dd21 = {num, c, fnum, dnum, b};
    bool trueval = (num == dd21[0].get_int()) && (c == dd21[1].get_char()) && (fnum == dd21[2].get_float()) && (dnum == dd21[3].get_double()) && (b == dd21[4].get_bool());
    test<bool>(trueval, true);
}
void test_22(bool val1, bool val2)
{
    udt::dynamic dd22 = val1;
    test<bool>(dd22.get_bool(), val2);
}
int main()
{
    io::NewLines(4);
    test_1(10);
    test_2(5);
    test_3(10, 5);
    test_4(10, 5);
    test_5(5, 2);
    test_6(10, 2);
    test_7(7.79);
    test_8(6.67, 3.32);
    test_9(0.5, 5.5);
    test_10(2.5, 0.5);
    test_11_20(12, 1.8, 0.5, 'a');
    test_21(10, 'A', 9.74, 29.7, false);
    test_22(false, false);
    return 0;
}