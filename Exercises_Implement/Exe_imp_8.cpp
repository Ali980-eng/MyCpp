#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include "testing.hpp"
// 2025/08/21 - 2025/08/14
// Basic Algorithm
/*101. Sum Array Excluding Numbers Starting with '5' and Followed by '6'
Write a C++ program to compute the sum of the numbers in a given array except the ones starting with 5 followed by at least one 6.
Return 0 if the given array has no integers.
Sample Input: {{ 1, 5, 9, 10, 17 }, { 1, 5, 6, 9, 10, 17 }}
Sample Output:
Sum of the numbers of the said array except those numbers starting with 5 followed by at least one 6: 42
Sum of the numbers of the said array except those numbers starting with 5 followed by at least one 6: 37 */
int SumArr_5_6(const std::vector<int> &numbers) noexcept
{
    if (numbers.empty())
        return 0;
    if (numbers.size() == 1)
        return numbers[0];
    if (numbers.size() == 2)
        return numbers[0] == 5 && numbers[1] == 6 ? 0 : numbers[0] + numbers[1];
    int sum = 0;
    for (int i = 1; i < numbers.size(); i++)
    {
        if (numbers[i - 1] == 5 && numbers[i] == 6)
            continue;
        sum += numbers[i - 1];
    }
    return sum + numbers[numbers.size() - 1];
}
/*102. Check for Adjacent '5's in Array
Write a C++ program to check if a given array of integers contains 5 next to a 5 somewhere.
Sample Input:
{ 1, 5, 6, 9, 10, 17 }
{ 1, 5, 5, 9, 10, 17 }
{ 1, 5, 5, 9, 10, 17, 5, 5 }
Sample Output: [0, 1, 1]*/
bool Check_5_5(const std::vector<int> &numbers) noexcept
{
    if (numbers.empty() || numbers.size() == 1)
        return false;
    if (numbers.size() == 2)
        return numbers[0] == 5 && numbers[0] == numbers[1];
    for (int i = 1; i < numbers.size(); i++)
    {
        if (numbers[i - 1] == 5 && numbers[i] == 5)
            return true;
    }
    return false;
}
/*103. Check if Array Contains Both '5' and '7'
Write a C++ program to check whether a given array of integers contains 5's and 7's.
Sample Input:
{ 1, 5, 6, 9, 10, 17 }
{ 1, 4, 7, 9, 10, 17 }
{ 1, 1, 2, 9, 10, 17}
Sample Output: [1, 1, 0]*/
bool Check_5_7(const std::vector<int> &numbers) noexcept
{
    if (numbers.empty())
        return false;
    if (numbers.size() == 1)
        return numbers[0] == 5 || numbers[0] == 7;
    for (int number : numbers)
    {
        if (number == 5 || number == 7)
            return true;
    }
    return false;
}
/*104. Check if Sum of All '5's Equals 15
Write a C++ program that checks if the sum of all 5' in the array is exactly 15.
Sample Input:
{ 1, 5, 6, 9, 10, 17 }
{ 1, 5, 5, 5, 10, 17 }
{ 1, 1, 5, 5, 5, 5}
Sample Output: [0, 1, 0]*/
bool CheckAll_5_equal_15(const std::vector<int> &numbers) noexcept
{
    if (numbers.empty() || numbers.size() == 1 || numbers.size() == 2)
        return false;
    int sum = 0;
    for (int number : numbers)
    {
        if (number == 5)
            sum += number;
    }
    return sum == 15;
}
/*105. Compare Count of '3's and '5's in Array
Write a C++ program to check if the number of 3's is greater than the number of 5's.
Sample Input:
{ 1, 5, 6, 9, 3, 3 }
{ 1, 5, 5, 5, 10, 17 }
{ 1, 3, 3, 5, 5, 5}
Sample Output:[1, 0, 0]*/
bool compare_count_3and5(const std::vector<int> &numbers) noexcept
{
    if (numbers.empty())
        return false;
    if (numbers.size() == 1)
        return numbers[0] == 3;
    if (numbers.size() == 2)
        return numbers[0] == 3 && numbers[1] == 3;
    int count = 0;
    for (int number : numbers)
    {
        if (number == 3)
            count++;
        if (number == 5)
            count--;
    }
    return count > 0;
}
/*106. Check for Presence of '3' or '5' in Array
Write a C++ program to check if a given array of integers contains a 3 or a 5.
Sample Input:
{ 5, 5, 5, 5, 5 }
{ 3, 3, 3, 3 }
{ 3, 3, 3, 5, 5, 5}
{ 1, 6, 8, 10}
Sample Output:[1, 1, 1, 0]*/
bool Check_presence_3or5(const std::vector<int> &numbers) noexcept
{
    if (numbers.empty())
        return false;
    if (numbers.size() == 1)
        return numbers[0] == 5 || numbers[0] == 3;
    for (int number : numbers)
        if (number == 5 || number == 3)
            return true;
    return false;
}
/*107. Check if Array Contains No '3' or '5'
Write a C++ program to check if a given array of integers contains no 3 or 5.
Sample Input:
{ 5, 5, 5, 5, 5 }
{ 3, 3, 3, 3 }
{ 3, 3, 3, 5, 5, 5}
{ 1, 6, 8, 10}
Sample Output: [1, 1, 0, 1]*/
bool Check_no_3or5(const std::vector<int> &numbers) noexcept
{
    if (numbers.empty() || numbers.size() == 1)
        return true;
    int holdnum = 0;
    for (int number : numbers)
    {
        if (holdnum == 3 && number == 5)
            return false;
        if (number == 3)
            holdnum = number;
    }
    return true;
}
/*108. Check for Adjacent '3's or '5's in Array
Write a C++ program to check if an array of integers contains a 3 next to a 3 or a 5 next to a 5 or both.
Sample Input:
{ 5, 5, 5, 5, 5 }
{ 1, 2, 3, 4 }
{ 3, 3, 5, 5, 5, 5}
{ 1, 5, 5, 7, 8, 10}
Sample Output: [1, 0, 1, 1]*/
bool Check_Adjacent_3or5(const std::vector<int> &numbers) noexcept
{
    if (numbers.empty() || numbers.size() == 1)
        return false;
    if (numbers.size() == 2)
        return (numbers[0] == 3 && numbers[1] == 3) || (numbers[0] == 5 && numbers[1] == 5);
    for (int i = 0; i < numbers.size(); i++)
    {
        if ((numbers[i - 1] == 3 && numbers[i] == 3) || (numbers[i - 1] == 5 && numbers[i] == 5))
            return true;
    }
    return false;
}
/*109. Check if Array Contains Two '5's Next or Separated by One Element
Write a C++ program to check a given array of integers.
Then, return true if the given array contains two 5's next to each other, or two 5's separated by one element.
Sample Input:
{ 5, 5, 1, 5, 5 }
{ 1, 2, 3, 4 }
{ 3, 3, 5, 5, 5, 5}
{ 1, 5, 5, 7, 8, 10}
Sample Output:[1, 0, 1, 1]*/
bool Check_Contains_Two5(const std::vector<int> &numbers) noexcept
{
    if (numbers.empty() || numbers.size() == 1)
        return false;
    if (numbers.size() == 2)
        return numbers[0] == 5 && numbers[1] == 5;
    if (numbers.size() == 3)
        return (numbers[0] == 5 && numbers[2] == 5) || (numbers[0] == 5 && numbers[1] == 5);
    for (int i = 2; i < numbers.size(); i++)
    {
        if ((numbers[i - 2] == 5 && numbers[i] == 5) || (numbers[i - 2] == 5 && numbers[i - 1] == 5))
            return true;
    }
    return false;
}
/*110. Check if '3' is Followed by '5' in Array
Write a C++ program to check a given array of integers and return true if there is a 3 with a 5 somewhere later in the given array.
Sample Input:
{ 3, 5, 1, 3, 7 }
{ 1, 2, 3, 4 }
{ 3, 3, 5, 5, 5, 5}
{ 2, 5, 5, 7, 8, 10}
Sample Output:[1, 0, 1, 0]*/
bool Check_3followed5(const std::vector<int> &numbers) noexcept
{
    if (numbers.empty() || numbers.size() == 1)
        return false;
    if (numbers.size() == 2)
        return numbers[0] == 3 && numbers[1] == 5;
    for (int i = 1; i < numbers.size(); i++)
    {
        if (numbers[i - 1] == 3 && numbers[i] == 5)
            return true;
    }
    return false;
}
/*111. Check for Two Adjacent Even or Odd Numbers in Array
Write a C++ program to check a given array of integers.
The program will return true if the given array contains either 2 even or 2 odd values all next to each other.
Sample Input:
{ 3, 5, 1, 3, 7 }
{ 1, 2, 3, 4 }
{ 3, 3, 5, 5, 5, 5}
{ 2, 4, 5, 6}
Sample Output: [1, 0, 1, 1]*/
constexpr bool is_even(int num) noexcept
{
    return num % 2 == 0;
}
constexpr bool is_odd(int num) noexcept
{
    return !is_even(num);
}
bool Check_Adjacent_evenodd(const std::vector<int> &numbers) noexcept
{
    if (numbers.empty() || numbers.size() == 1)
        return false;
    if (numbers.size() == 2)
        return (is_even(numbers[0]) && is_even(numbers[1])) || (is_odd(numbers[0]) && is_odd(numbers[1]));
    unsigned int even_count = 0, odd_count = 0;
    for (int number : numbers)
    {
        if (is_even(number))
            even_count++;
        else
            odd_count++;
    }
    if (odd_count < 2 && even_count < 2)
        return false;
    return odd_count != even_count;
}
/*112. Check if Five '5's Exist Without Adjacent Ones
Write a C++ program to check a given array of integers.
The program will return true if the value 5 appears 5 times and there are no 5 next to each other.
Sample Input:
{ 3, 5, 1, 5, 3, 5, 7, 5, 1, 5 }
{ 3, 5, 5, 5, 5, 5, 5}
{ 3, 5, 2, 5, 4, 5, 7, 5, 8, 5}
{ 2, 4, 5, 5, 5, 5}
Sample Output:[1, 0, 1, 0]*/
bool Check_5_Without_1(const std::vector<int> &numbers) noexcept
{
    if (numbers.empty() || 9 > numbers.size() >= 1)
        return false;
    bool firestfive = false;
    unsigned int count = 5;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] != 5 && firestfive)
        {
            firestfive = false;
            count = 5;
        }
        else if (numbers[i] == 5 && firestfive)
        {
            count--;
            i++;
        }
        else if (numbers[i] == 5)
        {
            firestfive = true;
            count--;
            i++;
        }
    }
    return count == 0;
}
/*113. Check if All '5's Are Next to Each Other
Write a C++ program to check a given array of integers and return true if every 5 that appears in the given array is next to another 5.
Sample Input:
{ 3, 5, 5, 3, 7 }
{ 3, 5, 5, 4, 1, 5, 7}
{ 3, 5, 5, 5, 5, 5}
{ 2, 4, 5, 5, 6, 7, 5}
Sample Output:[1, 0, 1, 0]*/
std::vector<int> extract_chain(const std::vector<int> &vec, int &begin, int element) noexcept
{
    if (vec.empty())
        return vec;
    if (vec.size() == 1 && element == vec[0])
        return vec;
    std::vector<int> result;
    for (; begin < vec.size(); begin++)
    {
        if (vec[begin] == element)
            result.push_back(element);
        else
            return result;
    }
    return result;
}
bool Check_All_5_Next(const std::vector<int> &numbers) noexcept
{
    if (numbers.empty() || numbers.size() == 1)
        return false;
    if (numbers.size() == 2)
        return numbers[0] == 5 && numbers[1] == 5;
    int chain_num = 0;
    bool firest_five = false;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 5)
        {
            chain_num += static_cast<int>(!extract_chain(numbers, i, 5).empty());
        }
    }
    return chain_num == 1;
}
/*114. Check if Specified Elements Appear at Both Start and End of Array
Write a C++ program to check a given array of integers.
The program will return true if the specified number of the same elements appears at the start and end of the given array.
Sample Input:
{ 3, 7, 5, 5, 3, 7 }, 2
{ 3, 7, 5, 5, 3, 7 }, 3
{ 3, 7, 5, 5, 3, 7, 5 }, 3
Sample Output: [1, 0, 1]*/
template <typename T>
std::vector<T> sub_vec(const std::vector<T> &vec, int begin, int end)
{
    if (vec.empty())
        return std::vector<T>(vec.begin() + begin, vec.begin() + end);
    if (begin > end || begin < 0 || end < 0 || end > vec.size())
        throw std::invalid_argument("Indexing Error");
    std::vector<T> result;
    for (int i = begin; i < end; i++)
    {
        result.push_back(vec[i]);
    }
    return result;
}
bool Check_subarr_apper(const std::vector<int> &vec, int len)
{
    if (len > vec.size())
        std::invalid_argument("Indexing Error");
    return sub_vec<int>(vec, 0, len) == sub_vec<int>(vec, vec.size() - len, vec.size());
}
/*115. Check for Three Increasing Adjacent Numbers in Array
Write a C++ program to check a given array of integers and return true if the array contains three increasing adjacent numbers.
Sample Input:
{ 1, 2, 3, 5, 3, 7 }
{ 3, 7, 5, 5, 3, 7 }
{ 3, 7, 5, 5, 6, 7, 5 }
Sample Output:[1, 0, 1]*/
bool Three_increasing_numbers(const std::vector<int> &numbers) noexcept
{
    if (numbers.empty() || numbers.size() == 1 || numbers.size() == 2)
        return false;
    if (numbers.size() == 3)
        return numbers[0] < numbers[1] && numbers[1] < numbers[2];
    for (int i = 2; i < numbers.size(); i++)
    {
        if (numbers[i - 2] < numbers[i - 1] && numbers[i - 1] < numbers[i])
            return true;
    }
    return false;
}
/*116. Check if Array is Non-Decreasing
Write a C++ program to check if the value of each element is equal or greater than the value of the previous element of a given array of integers.
Sample Input:
{ 5, 5, 1, 5, 5 }
{ 1, 2, 3, 4 }
{ 3, 3, 5, 5, 5, 5}
{ 1, 5, 5, 7, 8, 10}
Sample Output: [0, 1, 1, 1]*/
bool non_decreasing_array(const std::vector<int> &numbers) noexcept
{
    if (numbers.empty() || numbers.size() == 1)
        return false;
    if (numbers.size() == 2)
        return numbers[0] < numbers[1];
    for (int i = 1; i < numbers.size(); i++)
    {
        if (numbers[i - 1] > numbers[i])
            return false;
    }
    return true;
}
/*117. Check if Two Adjacent '15's Exist in Array
Write a C++ program to check if there are two values 15, 15 adjacent to each other in a given array (length should be at least 2) of integers.
Return true otherwise false.
Test Data:
({ 5, 5, 1, 15, 15 }) -> 1
({ 15, 2, 3, 4, 15 }) -> 0
({ 3, 3, 15, 15, 5, 5}) -> 1
({ 1, 5, 15, 7, 8, 15})-> 0 */
bool Adjacent_Two_15_Arr(const std::vector<int> &numbers) noexcept
{
    if (numbers.empty() || numbers.size() < 2)
        return false;
    for (int i = 1; i < numbers.size(); i++)
    {
        if (numbers[i - 1] == 15 && numbers[i] == 15)
            return true;
    }
    return false;
}
/*118. Find Larger Average Between First and Second Halves of Array.
Write a C++ program to find the largest average value between the first and second halves of a given array of integers.
Ensure that the minimum length is at least 2.
Assume that the second half begins at index (array length)/2.
Test Data:
({ 1, 2, 3, 4, 6, 8 }) -> 6
({ 15, 2, 3, 4, 15, 11 }) -> 10*/
template <typename T>
double average_vec(const std::vector<T> &numbers) noexcept
{
    if (numbers.empty())
        return 0.0;
    if (numbers.size() == 1)
        return numbers[0];
    if (numbers.size() == 2)
        return numbers[0] + numbers[1] / 2;
    T sum = 0.0;
    for (int number : numbers)
        sum += number;
    return sum / numbers.size();
}
int larger_average_half(const std::vector<int> &numbers) noexcept
{
    if (numbers.empty() || numbers.size() == 1)
        return 0;
    if (numbers.size() == 2)
        return numbers[0] > numbers[1] ? numbers[0] : numbers[1];
    int average_half1 = static_cast<int>(average_vec(sub_vec(numbers, 0, numbers.size() / 2)));
    int average_half2 = static_cast<int>(average_vec(sub_vec(numbers, numbers.size() / 2, numbers.size())));
    return average_half1 > average_half2 ? average_half1 : average_half2;
}
/*119. Count Strings of Given Length in String Array
Write a C++ program to count the number of strings with a given length in a given array of strings.
Test Data:
({"a", "b", "bb", "c", "ccc" }, 1) ->3
({"a", "b", "bb", "c", "ccc" }, 2) ->1
({"a", "b", "bb", "c", "ccc" }, 3) ->1*/
int count_string_length(const std::vector<std::string> &vs, int numlength) noexcept
{
    if (vs.empty())
        return 0;
    int count = 0;
    for (std::string s : vs)
    {
        if (s.length() == numlength)
            count++;
    }
    return count;
}
/*120. Create Array of First n Strings from Array
Write a C++ program to create an array using the first n strings from a given array of strings.
(n>=1 and <=length of the array).
Test Data:
({"a", "b", "bb", "c", "ccc" }, 2) -> {"a", "b"}
({"a", "b", "bb", "c", "ccc" }, 3) -> {"a", "b", "bb"}*/
std::vector<std::string> nStringsArray(const std::vector<std::string> &vs, int len)
{
    if (len > vs.size())
        throw std::invalid_argument("indexing error");
    return std::vector<std::string>(vs.begin(), vs.begin() + len);
}
/*121. Create Array with Strings of Given Length from String Array
Write a C++ program to create an array from a given array of strings using all the strings whose lengths are matched with the given string length.
Test Data:
({"a", "aaa", "b", "bb", "bbb", "c", "cc", "ccc"}, 1) -> {"a", "b", "c"}
({"a", "aaa", "b", "bb", "bbb", "c", "cc", "ccc"}, 2) -> {"bb", "cc"}
({"a", "aaa", "b", "bb", "bbb", "c", "cc", "ccc"}, 3) -> {"aaa", "bbb", "ccc"} */
std::vector<std::string> create_array_length(const std::vector<std::string> &vs, int len)
{
    if (vs.empty())
        return vs;
    std::vector<std::string> result;
    for (std::string s : vs)
    {
        if (s.length() == len)
            result.push_back(s);
    }
    return result;
}
/*122. Check if Number Contains Digit '3'
Write a C++ program to check a positive integer and return true if it contains the number 3.
Otherwise return false.
Test Data:
(143) -> 1
(678) -> 0
(963) -> 1*/
bool check_number_3(int num) noexcept
{
    num = std::abs(num);
    std::string snum = std::to_string(num);
    for (char cdigit : snum)
    {
        if (cdigit == '3')
            return true;
    }
    return false;
}
/*123. Create Array of Odd Numbers with Specific Length
Write a C++ program that creates a new array of odd numbers with specific lengths from a given array of positive integers.
Test Data:
({1,2,3,5,7,9,10},3) -> {1,3,5}*/
std::vector<int> array_of_odd(const std::vector<int> &numbers, int valde)
{
    if (numbers.empty())
        throw std::invalid_argument("Empty Error");
    std::vector<int> result;
    for (int number : numbers)
    {
        if (is_odd(number) && valde)
        {
            result.push_back(number);
            valde--;
        }
    }
    return result;
}
/*124. Multiply Each Integer in Array by 5
Write a C++ program to create a list from a given list of integers where each element is multiplied by 5.
Test Data:
({ 1, 2, 3}) -> {5, 10, 15}
({2, 4, 7, 8}) -> {10, 20, 35, 40}*/
std::vector<int> multiply_each_5(const std::vector<int> &numbers) noexcept
{
    if (numbers.empty())
        return numbers;
    std::vector<int> result;
    for (int number : numbers)
    {
        result.push_back(5 * number);
    }
    return result;
}
/*125. Multiply Each Integer in Array Three Times
Write a C++ program that multiplies each integer three times to create a list from a given list of integers.
Test Data:
({1, 2, 3, 4})-> {1 8 27 64}*/
template <typename T>
std::vector<T> multiply_each_3(const std::vector<T> &numbers) noexcept
{
    if (numbers.empty())
        return numbers;
    std::vector<T> result;
    for (const T &number : numbers)
        result.push_back(number * number * number);
    return result;
}
/*126. Add "$" at Start and End of Each String in Array
Write a C++ program to create a list from a given list of strings where each element has "$" added at the beginning and end position.
Test Data:
Sample Input:
{ "1", "2", "3" , "4" }
Expected Output:
$1$ $2$ $3$ $4$*/
std::vector<std::string> add_dollar_sign(const std::vector<std::string> &vs) noexcept
{
    if (vs.empty())
        return vs;
    std::vector<std::string> result;
    for (const std::string &s : vs)
        result.push_back("$" + s + "$");
    return result;
}
/*127. Create List of Strings Each Repeated 3 Times
Write a C++ program to create a list from a given list of strings where each element is replaced by 3 copies of the string concatenated together.
Test Data:
Sample Input:
{ "1", "2", "3" , "4" }
Expected Output :
111 222 333 444*/
std::vector<std::string> repeat_string_3(const std::vector<std::string> &vs) noexcept
{
    if (vs.empty())
        return vs;
    std::vector<std::string> result;
    for (const std::string &s : vs)
        result.push_back(s + s + s);
    return result;
}
/*128. Add 3 and Multiply by 4 for Each Integer in Array
Write a C++ program to create a list from a given list of integers.
In this program, each integer value is added to 3 and the result value is multiplied by 4.
Test Data:
({ 1, 2, 3 , 4 }) -> {16 20 24 28}*/
std::vector<int> Multiply_by_4(const std::vector<int> &numbers) noexcept
{
    if (numbers.empty())
        return numbers;
    std::vector<int> result;
    for (const int &number : numbers)
        result.push_back((number + 3) * 4);
    return result;
}
/*129. Create List of Rightmost Digits of Numbers in Array
Write a C++ program to create a list of the rightmost digits from a given list of positive integers.
Test Data:
({ 12, 20, 351, 4449}) -> {2, 0, 1, 9}*/
std::vector<int> rightmost_digits(const std::vector<int> &numbers) noexcept
{
    if (numbers.empty())
        return numbers;
    std::vector<int> result;
    for (const int &number : numbers)
        result.push_back(number % 10);
    return result;
}
/*71. Decimal to Hexadecimal Conversion
Write a program in C++ to convert a decimal number to a hexadecimal number.
Sample Output:
Input a decimal number: 43
The hexadecimal number is : 2B*/
std::string decimal_to_hexadecimal(int decimal) noexcept
{
    std::string hex = "";
    while (decimal > 0)
    {
        int remainder = decimal % 16;
        if (remainder < 10)
            hex = char(remainder + '0') + hex;
        else
            hex = char(remainder - 10 + 'A') + hex;
        decimal /= 16;
    }
    return hex;
}
/*73. Binary to Decimal Conversion
Write a C++ program to convert a binary number to a decimal number.
Sample Output:
Input a binary number: 1011
The decimal number: 11*/
int binary_to_decimal(const std::string &binary)
{
    if (binary.empty())
        throw std::invalid_argument("Invalid binary string");
    int decimal = 0;
    for (char digit : binary)
    {
        if (digit != '0' && digit != '1')
            throw std::invalid_argument("Invalid binary string");
        decimal = decimal * 2 + (digit - '0');
    }
    return decimal;
}
/*74. Binary to Hexadecimal Conversion
Write a C++ program to convert a binary number to a hexadecimal number.
Sample Output:
Input a binary number: 1011
The hexadecimal value: B*/
std::string binary_to_hexadecimal(const std::string &binary)
{
    if (binary.empty())
        throw std::invalid_argument("Invalid binary string");
    int decimal = binary_to_decimal(binary);
    return decimal_to_hexadecimal(decimal);
}
/*75. Binary to Octal Conversion
Write a C++ program to convert a binary number to an octal number.
Sample Output:
Input a binary number: 1011
The equivalent octal value of 1011 is : 13*/
std::string binary_to_octal(const std::string &binary)
{
    if (binary.empty())
        throw std::invalid_argument("Invalid binary string");
    int decimal = binary_to_decimal(binary);
    std::string octal = "";
    while (decimal > 0)
    {
        octal = char((decimal % 8) + '0') + octal;
        decimal /= 8;
    }
    return octal;
}
/*76. Octal to Decimal Conversion
Write a C++ program to convert an octal number to a decimal number.
Sample Output:
Input any octal number: 17
The equivalent decimal number: 15*/
int octal_to_decimal(const std::string &octal)
{
    if (octal.empty())
        throw std::invalid_argument("Invalid octal string");
    int decimal = 0;
    for (char digit : octal)
    {
        if (digit < '0' || digit > '7')
            throw std::invalid_argument("Invalid octal string");
        decimal = decimal * 8 + (digit - '0');
    }
    return decimal;
}
/*77. Octal to Binary Conversion
Write a C++ program to convert an octal number to a binary number.
Sample Output:
Input any octal number: 17
The equivalent binary number: 1111*/
std::string decimal_to_binary(int decimal) noexcept
{
    if (decimal == 0)
        return "0";
    std::string binary = "";
    while (decimal > 0)
    {
        binary = char((decimal % 2) + '0') + binary;
        decimal /= 2;
    }
    return binary;
}
std::string octal_to_binary(const std::string &octal)
{
    if (octal.empty())
        throw std::invalid_argument("Invalid octal string");
    int decimal = octal_to_decimal(octal);
    return decimal_to_binary(decimal);
}
/*78. Octal to Hexadecimal Conversion
Write a C++ program to convert an octal number to a hexadecimal number.
Sample Output:
Input any octal number: 77
The hexadecimal value of 77 is: 3F*/
std::string octal_to_hexadecimal(const std::string &octal)
{
    if (octal.empty())
        throw std::invalid_argument("Invalid octal string");
    int decimal = octal_to_decimal(octal);
    return decimal_to_hexadecimal(decimal);
}
/*79. Hexadecimal to Decimal Conversion
Write a C++ program to convert a hexadecimal number to a decimal number.
Sample Output:
Input any 32-bit Hexadecimal Number: 25
The value in decimal number is: 37*/
int hexadecimal_to_decimal(const std::string &hex)
{
    if (hex.empty())
        throw std::invalid_argument("Invalid hexadecimal string");
    int decimal = 0;
    for (char digit : hex)
    {
        if ((digit < '0' || digit > '9') && (digit < 'A' || digit > 'F'))
            throw std::invalid_argument("Invalid hexadecimal string");
        decimal = decimal * 16 + (isdigit(digit) ? digit - '0' : toupper(digit) - 'A' + 10);
    }
    return decimal;
}
/*80. Hexadecimal to Binary Conversion
Write a C++ program to convert a hexadecimal number to a binary number.
Sample Output:
Input any 32-bit Hexadecimal Number: 5f
The equivalant binary number is: 1011111 */
std::string hexadecimal_to_binary(const std::string &hex)
{
    if (hex.empty())
        throw std::invalid_argument("Invalid hexadecimal string");
    int decimal = hexadecimal_to_decimal(hex);
    return decimal_to_binary(decimal);
}
/*81. Hexadecimal to Octal Conversion
Write a C++ program to convert a hexadecimal number to an octal number.
Sample Output:
Input any 32-bit Hexadecimal Number: 5f The equivalant octal number is: 137 */
std::string hexadecimal_to_octal(const std::string &hex)
{
    if (hex.empty())
        throw std::invalid_argument("Invalid hexadecimal string");
    std::string binary = hexadecimal_to_binary(hex);
    std::string octal = binary_to_octal(binary);
    return octal;
}
/*82. Compare Two Numbers
Write a program in C++ to compare two numbers.
Sample Output:
Input the first integer: 25
Input the second integer: 15
25 != 15
25 > 15
25 >= 15*/
void compare_two_numbers(int a, int b) noexcept
{
    if (a == b)
        std::cout << a << " == " << b << std::endl;
    if (a != b)
        std::cout << a << " != " << b << std::endl;
    if (a > b)
        std::cout << a << " > " << b << std::endl;
    if (a < b)
        std::cout << a << " < " << b << std::endl;
}
/*83. Sum of the Digits of an Integer
Write a C++ program to compute the sum of the digits of an integer.
Sample Output:
Input any number: 25
The sum of the digits of the number 25 is: 7
----------------------------------------------------
84. Sum of the Digits of an Integer Using a Function
Write a C++ program to compute the sum of the digits of an integer using a function.
Sample Output:
Input any number: 255 The sum of the digits of the number 255 is: 12*/
int sum_of_digits(int n) noexcept
{
    int sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
/*85. Reverse a String
Write a program in C++ to reverse a string.
Sample Output:
Enter a string: w3resource The string in reverse are: ecruoser3w*/
std::string reverse_string(const std::string &str) noexcept
{
    if (str.empty())
        return str;
    std::string reversed_str = str;
    for (size_t i = 0; i < str.length() / 2; i++)
        std::swap(reversed_str[i], reversed_str[str.length() - i - 1]);
    return reversed_str;
}
/*86. Count Letters, Spaces, Numbers, and Others in a String
Write a C++ program to count the letters, spaces, numbers and other characters in an input string.
Sample Output:
Enter a string: This is w3resource.com
The number of characters in the string is: 22
The number of alphabets are: 18
The number of digits are: 1
The number of spaces are: 2
The number of other characters are: 1 */
int Count_word(std::string str, int &letters, int &spaces, int &numbers, int &others) noexcept
{
    letters = spaces = numbers = others = 0;
    for (char c : str)
    {
        if (std::isalpha(c))
            letters++;
        else if (std::isspace(c))
            spaces++;
        else if (std::isdigit(c))
            numbers++;
        else
            others++;
    }
    return letters + spaces + numbers + others;
}
/*87. Generate Three-Digit Numbers from {1,2,3,4} and Count Them
Write a C++ program to create and display an original three-digit numbers using 1, 2, 3, 4.
Also count how many three-digit numbers are there.
Sample Output:
The three-digit numbers are:
123 124 132 134 142 143 213 214 231 234 241 243 312 314 321 324 341 342 412 413 421 423 431 432
Total number of the three-digit-number is: 24*/
int generate_number(const std::vector<int> &numbers) noexcept
{
    if (numbers.empty())
        return 0;
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed for random number generation
    int result = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        int index = rand() % numbers.size();
        result = result * 10 + numbers[index];
    }
    return result;
}
// Numbers
/*1. Ugly Number Check
Write a program in C++ to check whether a given number is an ugly number or not.
Sample output:
Input an integer number: 25
It is an ugly number.*/
bool ugly_number(int num) noexcept
{
    if (num <= 0)
        return false;
    while (num % 2 == 0)
        num /= 2;
    while (num % 3 == 0)
        num /= 3;
    while (num % 5 == 0)
        num /= 5;
    return num == 1;
}
/*2. Abundant Number Check
Write a program in C++ to check whether a given number is Abundant or not.
Sample Output:
Input an integer number: 35
The number is not Abundant.*/
bool abundant_number(int num) noexcept
{
    if (num <= 0)
        return false;
    int sum = 0;
    for (int i = 1; i <= num / 2; i++)
    {
        if (num % i == 0)
            sum += i;
    }
    return sum > num;
}
/*3. Find Abundant Numbers Between 1 and 1000
Write a program in C++ to find the Abundant numbers (integers) between 1 and 1000.
Sample Output:
The Abundant number between 1 to 1000 are:
-----------------------------------------------
{
    {12, 18, 20, 24, 30, 36, 40, 42, 48, 54},
    {56, 60, 66, 70, 72, 78, 80, 84, 88, 90},
    {96, 100, 102, 104, 108, 112, 114, 120},
    {126, 132, 138, 140, 144, 150, 156, 160, 162, 168},
    {174, 176, 180, 186, 192, 196, 198, 200, 204, 208},
    {210, 216, 220, 222, 224, 228, 234, 240, 246},
    {252, 258, 260, 264, 270, 272, 276, 280, 282, 288},
    {294, 300, 304, 306, 308, 312, 318, 320, 324, 330, 336},
    {340, 342, 348, 350, 352, 354, 360, 364, 366, 368, 372, 378},
    {380, 384, 390, 392, 396, 400, 402, 408, 414, 416, 420, 426},
    {432, 438, 440, 444, 448, 450, 456, 460, 462, 464, 468, 474, 476},
    {480, 486, 490, 492, 498, 500, 504, 510, 516, 520, 522, 528, 532},
    {534, 540, 544, 546, 550, 552, 558, 560, 564, 570, 572, 576, 580},
    {582, 588, 594, 600, 606, 608, 612, 616, 618, 620, 624, 630, 636},
    {640, 642, 644, 648, 650, 654, 660, 666, 672, 678, 680, 684, 690, 696, 700, 702},
    {704, 708, 714, 720, 726, 728, 732, 736, 738, 740, 744, 748},
    {750, 756, 760, 762, 768, 770, 774, 780, 784, 786, 792, 798},
    {800, 804, 810, 812, 816, 820, 822, 828, 832, 834, 836, 840},
    {846, 852, 858, 860, 864, 868, 870, 876, 880, 882, 888, 894},
    {896, 900, 906, 910, 912, 918, 920, 924, 928, 930, 936, 940},
    {942, 945, 948, 952, 954, 960, 966, 968, 972, 978, 980, 984, 990, 992, 996, 1000}
};*/
std::vector<std::vector<int>> abundant_numbers(int start, int end) noexcept
{
    std::vector<std::vector<int>> result;
    for (int i = start; i <= end; i++)
    {
        if (abundant_number(i))
            result.push_back({i});
    }
    return result;
}
int main()
{
    io::NewLines();
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    test::basic(42, SumArr_5_6({1, 5, 9, 10, 17}));
    test::basic<bool>(false, Check_5_5({1, 5, 6, 9, 10, 17}));
    test::basic<bool>(true, Check_5_5({1, 5, 5, 9, 10, 17}));
    test::basic<bool>(true, Check_5_5({1, 5, 5, 9, 10, 17, 5, 5}));
    test::basic<bool>(true, Check_5_7({1, 5, 6, 9, 10, 17}));
    test::basic<bool>(true, Check_5_7({1, 4, 7, 9, 10, 17}));
    test::basic<bool>(false, Check_5_7({1, 1, 2, 9, 10, 17}));
    test::basic<bool>(false, CheckAll_5_equal_15({1, 5, 6, 9, 10, 17}));
    test::basic<bool>(true, CheckAll_5_equal_15({1, 5, 5, 5, 10, 17}));
    test::basic<bool>(false, CheckAll_5_equal_15({1, 1, 5, 5, 5, 5}));
    test::basic<bool>(true, compare_count_3and5({1, 5, 6, 9, 3, 3}));
    test::basic<bool>(false, compare_count_3and5({1, 5, 5, 5, 10, 17}));
    test::basic<bool>(false, compare_count_3and5({1, 3, 3, 5, 5, 5}));
    test::basic<bool>(true, Check_presence_3or5({5, 5, 5, 5, 5}));
    test::basic<bool>(true, Check_presence_3or5({3, 3, 3, 3}));
    test::basic<bool>(true, Check_presence_3or5({3, 3, 3, 5, 5, 5}));
    test::basic<bool>(false, Check_presence_3or5({1, 6, 8, 10}));
    test::basic<bool>(true, Check_no_3or5({5, 5, 5, 5, 5}));
    test::basic<bool>(true, Check_no_3or5({3, 3, 3, 3}));
    test::basic<bool>(false, Check_no_3or5({3, 3, 3, 5, 5, 5}));
    test::basic<bool>(true, Check_no_3or5({1, 6, 8, 10}));
    test::basic<bool>(true, Check_Adjacent_3or5({5, 5, 5, 5, 5}));
    test::basic<bool>(false, Check_Adjacent_3or5({1, 2, 3, 4}));
    test::basic<bool>(true, Check_Adjacent_3or5({3, 3, 5, 5, 5, 5}));
    test::basic<bool>(true, Check_Adjacent_3or5({1, 5, 5, 7, 8, 10}));
    test::basic<bool>(true, Check_Contains_Two5({5, 5, 1, 5, 5}));
    test::basic<bool>(false, Check_Contains_Two5({1, 2, 3, 4}));
    test::basic<bool>(true, Check_Contains_Two5({3, 3, 5, 5, 5, 5}));
    test::basic<bool>(true, Check_Contains_Two5({1, 5, 5, 7, 8, 10}));
    test::basic<bool>(true, Check_3followed5({3, 5, 1, 3, 7}));
    test::basic<bool>(false, Check_3followed5({1, 2, 3, 4}));
    test::basic<bool>(true, Check_3followed5({3, 3, 5, 5, 5, 5}));
    test::basic<bool>(false, Check_3followed5({2, 5, 5, 7, 8, 10}));
    test::basic<bool>(true, Check_Adjacent_evenodd({3, 5, 1, 3, 7}));
    test::basic<bool>(false, Check_Adjacent_evenodd({1, 2, 3, 4}));
    test::basic<bool>(true, Check_Adjacent_evenodd({3, 3, 5, 5, 5, 5}));
    test::basic<bool>(true, Check_Adjacent_evenodd({2, 4, 5, 6}));
    test::basic<bool>(true, Check_5_Without_1({3, 5, 1, 5, 3, 5, 7, 5, 1, 5}));
    test::basic<bool>(false, Check_5_Without_1({3, 5, 5, 5, 5, 5, 5}));
    test::basic<bool>(true, Check_5_Without_1({3, 5, 2, 5, 4, 5, 7, 5, 8, 5}));
    test::basic<bool>(false, Check_5_Without_1({2, 4, 5, 5, 5, 5}));
    test::basic<bool>(true, Check_All_5_Next({3, 5, 5, 3, 7}));
    test::basic<bool>(false, Check_All_5_Next({3, 5, 5, 4, 1, 5, 7}));
    test::basic<bool>(true, Check_All_5_Next({3, 5, 5, 5, 5, 5}));
    test::basic<bool>(false, Check_All_5_Next({2, 4, 5, 5, 6, 7, 5}));
    test::basic<bool>(true, Check_subarr_apper({3, 7, 5, 5, 3, 7}, 2));
    test::basic<bool>(false, Check_subarr_apper({3, 7, 5, 5, 3, 7}, 3));
    test::basic<bool>(true, Check_subarr_apper({3, 7, 5, 5, 3, 7, 5}, 3));
    test::basic<bool>(true, Three_increasing_numbers({1, 2, 3, 5, 3, 7}));
    test::basic<bool>(false, Three_increasing_numbers({3, 7, 5, 5, 3, 7}));
    test::basic<bool>(true, Three_increasing_numbers({3, 7, 5, 5, 6, 7, 5}));
    test::basic<bool>(false, non_decreasing_array({5, 5, 1, 5, 5}));
    test::basic<bool>(true, non_decreasing_array({1, 2, 3, 4}));
    test::basic<bool>(true, non_decreasing_array({3, 3, 5, 5, 5, 5}));
    test::basic<bool>(true, non_decreasing_array({1, 5, 5, 7, 8, 10}));
    test::basic<bool>(true, Adjacent_Two_15_Arr({5, 5, 1, 15, 15}));
    test::basic<bool>(false, Adjacent_Two_15_Arr({15, 2, 3, 4, 15}));
    test::basic<bool>(true, Adjacent_Two_15_Arr({3, 3, 15, 15, 5, 5}));
    test::basic<bool>(false, Adjacent_Two_15_Arr({1, 5, 15, 7, 8, 15}));
    test::basic<int>(6, larger_average_half({1, 2, 3, 4, 6, 8}));
    test::basic<int>(10, larger_average_half({15, 2, 3, 4, 15, 11}));
    test::basic<int>(3, count_string_length({"a", "b", "bb", "c", "ccc"}, 1));
    test::basic<int>(1, count_string_length({"a", "b", "bb", "c", "ccc"}, 2));
    test::basic<int>(1, count_string_length({"a", "b", "bb", "c", "ccc"}, 3));
    test::basic<bool>(true, check_number_3(143));
    test::basic<bool>(false, check_number_3(678));
    test::basic<bool>(true, check_number_3(963));
    test::basic<int>(11, binary_to_decimal("1011"));
    test::basic<std::string>("2B", decimal_to_hexadecimal(43));
    test::basic<std::string>("B", binary_to_hexadecimal("1011"));
    test::basic<std::string>("13", binary_to_octal("1011"));
    test::basic<int>(15, octal_to_decimal("17"));
    test::basic<std::string>("1111", octal_to_binary("17"));
    test::basic<std::string>("3F", octal_to_hexadecimal("77"));
    test::basic<int>(37, hexadecimal_to_decimal("25"));
    test::basic<std::string>("1011111", hexadecimal_to_binary("5F"));
    test::basic<std::string>("137", hexadecimal_to_octal("5F"));
    test::basic<bool>(true, ugly_number(25));
    test::basic<bool>(false, abundant_number(35));
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    test::vector<std::string>({"a", "b"}, nStringsArray({"a", "b", "bb", "c", "ccc"}, 2));
    test::vector<std::string>({"a", "b", "bb"}, nStringsArray({"a", "b", "bb", "c", "ccc"}, 3));
    test::vector<std::string>({"a", "b", "c"}, create_array_length({"a", "aaa", "b", "bb", "bbb", "c", "cc", "ccc"}, 1));
    test::vector<std::string>({"bb", "cc"}, create_array_length({"a", "aaa", "b", "bb", "bbb", "c", "cc", "ccc"}, 2));
    test::vector<std::string>({"aaa", "bbb", "ccc"}, create_array_length({"a", "aaa", "b", "bb", "bbb", "c", "cc", "ccc"}, 3));
    test::vector<int>({1, 3, 5}, array_of_odd({1, 2, 3, 5, 7, 9, 10}, 3));
    test::vector<int>({5, 10, 15}, multiply_each_5({1, 2, 3}));
    test::vector<int>({10, 20, 35, 40}, multiply_each_5({2, 4, 7, 8}));
    test::vector<int>({1, 8, 27, 64}, multiply_each_3<int>({1, 2, 3, 4}));
    test::vector<std::string>({"$1$", "$2$", "$3$", "$4$"}, add_dollar_sign({"1", "2", "3", "4"}));
    test::vector<std::string>({"111", "222", "333", "444"}, repeat_string_3({"1", "2", "3", "4"}));
    test::vector<int>({16, 20, 24, 28}, Multiply_by_4({1, 2, 3, 4}));
    test::vector<int>({2, 0, 1, 9}, rightmost_digits({12, 20, 351, 4449}));
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    io::NewLines();
    return 0;
}