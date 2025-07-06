#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <numeric>
#include "InOut.hpp"
using namespace std;
/*
------------------------------------------------------------
  Weekly Function Implementation Series – Week 7
------------------------------------------------------------

  Author   : Ali Lafi
  Language : C++
  Duration : June 29, 2025 – July 6, 2025

  Topics Covered:
    - Basic Algorithms
    - For-Loops
    - String Manipulation
    - Recursion

  Description:
    This file contains a set of C++ function implementations related 
    to various programming exercises in algorithms, loops, strings, 
    and recursion.

    Each function includes Multiple-line comments that explain the 
    purpose of the function, the approach used, and any 
    relevant edge-case considerations.
*/
// Basic Algorithm
/*81. Check 10 in First or Last Element
Write a C++ program to check a given array of integers of length 1 or more and return true if 10 appears as either first or last element in the given array.
Sample Input:{{ 10, 20, 40, 50 }, { 5, 20, 40, 10 }, { 10, 20, 40, 10 }, { 12, 24, 35, 55 }}
Sample Output:[1, 1, 1, 0]*/
bool Check10FirLas(const vector<int> &numbers) {
    if(numbers[0]==10||numbers[numbers.size()-1]==10) return true;
    return false;
}
/*82. First and Last Elements Match Check
Write a C++ program to check a given array of integers of length 1 or more.
The program will return true if the first element and the last element are equal in the given array.
Sample Input:{{ 10, 20, 40, 50 }, { 10, 20, 40, 10 }, { 12, 24, 35, 55 }}
Sample Output:[0, 1, 0]*/
bool FirLasEleMatch(const vector<int> &numbers) {
    if(numbers[0] == numbers[numbers.size()-1]) return true;
    return false;
}
/*83. Same First or Last Element in Two Arrays
Write a C++ program to check two given arrays of integers of length 1 or more.
This will return true if they have the same first element or if they have the same last element.
Sample Input:
{{ 10, 20, 40, 50 }, { 10, 20, 40, 50 }, 
{ 10, 20, 40, 50 }, { 10, 20, 40, 5 }, 
{ 10, 20, 40, 50 }, { 1, 20, 40, 5 }}
Sample Output:[1, 1, 0]*/
template <class dynamic> class doubleVec {
    private:
    vector<dynamic> vec1;
    vector<dynamic> vec2;
    public:
    bool empty() {
        if(vec1.empty()&&vec2.empty()) {
            cout<<"The Two vector is empty"<<endl;
            return true;
        }
        return false;
    }
    bool empty1() {
        return vec1.empty();
    }
    bool empty2() {
        return vec2.empty();
    }
    doubleVec() {
        vec1 = {};
        vec2 = {};
    }
    doubleVec(const vector<dynamic>& v1, const vector<dynamic>& v2) {
        vec1 = v1;
        vec2 = v2;
    }
    void set_vec(const vector<dynamic>& v1, const vector<dynamic>& v2) {
        vec1 = v1;
        vec2 = v2;
    }
    vector<dynamic> get_vec1() const {
        return vec1;
    }
    vector<dynamic> get_vec2() const {
        return vec2;
    }
    dynamic sum_vec1() {
        dynamic sum = dynamic(); // Initialize properly
        for(const dynamic& ele : vec1) sum += ele;
        return sum;
    }  
    dynamic sum_vec2() {
        dynamic sum = dynamic(); // Initialize properly
        for(const dynamic& ele : vec2) sum += ele;
        return sum;
    }
    int size_vec1() {
        if(vec1.empty()) return 0;
        return vec1.size();
    }
    int size_vec2() {
        if(vec2.empty()) return 0;
        return vec2.size();
    }
    dynamic at_vec1(int index) {
        if(index < 0 || index >= vec1.size()) throw out_of_range("Index is out of range.");
        return vec1[index];
    }
    dynamic at_vec2(int index) {
        if(index < 0 || index >= vec2.size()) throw out_of_range("Index is out of range.");
        return vec2[index];
    }
    void clear_all() {
        vec1.clear();
        vec2.clear();
    }
    void clear_vec1() {
        vec1.clear();
    }
    void clear_vec2() {
        vec2.clear();
    }
    void print() {
        cout<<"vec1: ";
        PrintVec(vec1);
        cout<<"vec2:";
        PrintVec(vec2);
    }
};
template <class dynamic> bool SameFirstOrLast(const doubleVec<dynamic>& douvec) {
    vector<dynamic> v1 = douvec.get_vec1();
    vector<dynamic> v2 = douvec.get_vec2();
    // Check if vectors are empty
    if(v1.empty() || v2.empty()) return false;
    dynamic firele1 = v1[0];
    dynamic firele2 = v2[0];
    dynamic lasele1 = v1[v1.size() - 1];  // Fixed: use size() - 1
    dynamic lasele2 = v2[v2.size() - 1];  // Fixed: use size() - 1   
    return (firele1 == firele2 || lasele1 == lasele2);
}
/*84. Sum of Array Elements
Write a C++ program to compute the sum of the elements of an array of integers.
Sample Input:{{ 10, 20, 30, 40, 50 }, { 10, 20, -30, -40, 50 }}
Sample Output:{150, 10}*/
int sumVec(const vector<int> &vec) {
    if(vec.empty()) return -1;
    return accumulate(vec.begin(), vec.end(), 0);
}
/*85. Left Rotate Array (Length 4)
Write a C++ program to rotate the elements of a given array of integers (length 4 ) in the left direction and return the changed array.
Sample Input: { 10, 20, 30, 40 }
Sample Output:
Rotated array: 20 30 40 10*/
vector<int> rotateVec(const vector<int> &vec, short expected_len = 4) {
    // Handle empty vector case
    if (vec.empty()) {
        cerr << "Error: The vector is empty." << std::endl;
        return {};
    } // End of if block
    // Check if vector length is less than the expected length for rotation
    // If strict 'Length 4' is required, consider changing to 'vec.size() != expected_len'
    if (vec.size() < expected_len) return vec;
    vector<int> result; // Initialize vector to store rotated elements
    // Add elements from the second position to the end of the new vector
    for (size_t i = 1; i < vec.size(); i++) { // Use size_t for loop counter
        result.push_back(vec[i]);
    } // End of for loop
    // Add the first element of the original vector to the end of the new vector
    result.push_back(vec[0]);
    return result;
} // End of rotateVec
/*86. Reverse Array (Length 5)
Write a C++ program to reverse a given array of integers of length 5.
Sample Input:{ 0, 10, 20, 30, 40 }
Sample Output:
Reverse array: 40 30 20 10 0 */
vector<int> ReverseArr(const vector<int> &vec, short expected_len = 5) {
    vector<int> result;
    for(int i = vec.size()-1;i>=0;i--) result.push_back(vec[i]);
    return result;
}
/*87. Middle Elements from Two Arrays
Write a C++ program to create an array containing the middle elements from the two given arrays of integers, each of length 5.
Sample Input:{{0, 10, 20, 30, 40}, {0, -10, -20, -30, -40}}
Sample Output:
New array: 20 -20 */
vector<int> MiddEleTwo(const vector<int> &V1, const vector<int> &V2) {
    vector<int> result;
    if(V1.empty()) result.push_back(-1);
    else result.push_back(V1[ceil(V1.size()/2)]);
    if(V2.empty()) result.push_back(-1);
    else result.push_back(V2[ceil(V2.size()/2)]);
    return result;
}
/*88. First and Last Elements of Array
Write a C++ program to create an array taking the first and last elements of a given array of integers and length 1 or more.
Sample Input: { 10, 20, -30, -40, 30 }
Sample Output:
New array: 10 30*/
vector<int> FirAndLasEle(const vector<int> &numbers) {
    if(numbers.empty()) return {-1};
    if(numbers.size()<=2) return numbers;
    return {numbers[0], numbers[numbers.size()-1]};
}
/*89. Check 15 or 20 in Array (Length 2)
Write a C++ program to determine whether a given array of integers of length 2 contains 15 or 20.
Sample Input: {{ 12, 20 }, { 14, 15 }, { 11, 21 }}
Sample Output: [1, 1, 0]*/
bool CheckTwoNumArr(const vector<int> &numbers, int num1 = 15, int num2 = 20, short expected_len = 2) {
    if(numbers.empty()) return false;
    if(numbers.size()==1) {
        if(numbers[0] == num1||numbers[0] == num2) 
        return true;
    }
    for(int number : numbers) {
        if(number == num1||number == num2) 
        return true;
    }
    return false;
}
/*90. Check if 15 or 20 Not Present in Array (Length 2)
Write a C++ program to check if an array of integers with length 2 does not contain 15 or 20.
Sample Input:{{ 12, 20 },{ 14, 15 },{ 11, 21 }}
Sample Output:[0, 0, 1]*/
bool CheckTwoNotNum(const vector<int> &numbers) {
    return !CheckTwoNumArr(numbers);
}
/*91. Check Array for Two 10s or 20s
Write a C++ program to check a given array of integers and return true if the array contains 10 or 20 twice.
The length of the array will be 0, 1, or 2.
Sample Input:{{ 12, 20 }, { 20, 20 }, { 10, 10 }, { 10 }}
Sample Output:[0, 1, 1, 0]*/
bool CheckArrTwo(const vector<int> &numbers) {
    short count = 2;
    for(int number : numbers) {
        if(number == 10 || number == 20) count--;
        if(count == 0) return true;
    }
    return false;
}
/*92. Replace '7' with '1' if Preceded by '5'
Write a C++ program to check a given array of integers, length 3 and create an array.
If there is a 5 in the given array immediately followed by a 7 then set 7 to 1.
Sample Input: {{ 1, 5, 7 }, { 1, 5, 3, 7 }}
Sample Output:
New array: 1 5 1
New array: 1 5 3 7*/
vector<int> Replace7to1(const vector<int> &numbers) {
    bool sw_num5 = false;
    vector<int> result;
    for(int number : numbers) {
        if(number == 5) sw_num5 = true;
        else if(number == 7 && sw_num5) {
            result.push_back(1);
            sw_num5 = false;
            continue;
        }
        else sw_num5 = false;
        result.push_back(number);
    }
    return result;
}
/*93. Sum Two Arrays and Find Larger
Write a C++ program to compute the sum of the two given arrays of integers, length 3 and find the array that has the largest sum.
Sample Input:{{ 1, 5, 7 }, { 1, 5, 3 }}
Sample Output:
New array: 1 5 7*/
vector<int> SumTwoArrFindLar(doubleVec<int> &douvec) {
    int sum1 = douvec.sum_vec1(), sum2 = douvec.sum_vec2();
    if(sum1 > sum2) return douvec.get_vec1();
    if(sum2 > sum1) return douvec.get_vec2();
    return douvec.get_vec1(); // default to vec1 if equal
}
/*94. Create Array from Middle Elements of Even-Length Array
Write a C++ program to create an array taking two middle elements from a given array of integers of length even.
Sample Input: { 1, 5, 7, 9, 11, 13 }
Sample Output:
New array: 7 9*/
vector<int> CreateArr(const vector<int> &numbers) {
    if(numbers.empty()) {
        cerr<<"The array is empty."<<endl;
        return {};
    }
    if(numbers.size()%2 != 0) {
        cerr<<"The size of the array is not even."<<endl;
        return {};
    }
    bool middleEle = false;
    vector<int> result;
    for(int i = 1;i <= numbers.size();i++) {
        if(i == (numbers.size() / 2)) middleEle = true;
        if(middleEle) {
            for(int j = i - 1;j<i + 1;j++) result.push_back(numbers[j]);
            return result;
        }
    }
    return {};
}
/*95. Swap First and Last Elements of Array
Write a C++ program to create an array by swapping the first and last elements of a given array of integers with a length of at least 1.
Sample Input: { 1, 5, 7, 9, 11, 13 }
Sample Output:
New array (after swapping the first and last elements of the said array): 13 5 7 9 11 1 */
vector<int> SwapFirAndLas(const vector<int> &vec) {
    if(vec.empty()) {
        cerr<<"The vector is empty."<<endl;
        return {};
    }
    if(vec.size() == 1) return vec;
    if(vec.size() == 2) return {vec[1], vec[0]};
    vector<int> result;
    result.push_back(vec[vec.size()-1]);
    for(int i = 1;i<vec.size()-1;i++) result.push_back(vec[i]);
    result.push_back(vec[0]);
    return result;
}
/*96. Create Array of Middle 3 Elements (Length = 3)
Write a C++ program to create an array length 3 from a given array (length at least 3) using the elements from the middle of the array.
Sample Input: { 1, 5, 7, 9, 11, 13 }
Sample Output:
New array: 7 9 11*/
vector<int> CreateArr2(const vector<int> &numbers) {
    if(numbers.empty()) {
        cerr<<"The array is empty."<<endl;
        return {};
    }
    if(numbers.size()<=3) return numbers;
    bool middleEle = false;
    vector<int> result;
    for(int i = 1;i <= numbers.size();i++) {
        if(i == (numbers.size() / 2)) middleEle = true;
        if(middleEle) {
            for(int j = i - 1;j<i + 2;j++) result.push_back(numbers[j]);
            return result;
        }
    }
    return {};
}
/*97. Find Largest of First, Last, Middle Elements in Odd-Length Array
Write a C++ program to find the largest value from the first, last, and middle elements of a given array of integers of odd length (at least 1).
Sample Input:{{1}, {1, 2, 9}, {1, 2, 9, 3, 3}, {1, 2, 3, 4, 5, 6, 7}, {1, 2, 2, 3, 7, 8, 9, 10, 6, 5, 4}}
Sample Output:[1, 9, 9, 7, 8]*/
int LargestFirLasMidd(const vector<int> &arr) {
    if(arr.empty()) {
        cerr<<"The array is empty."<<endl;
        return -1;
    }
    if(arr.size() == 1) return arr[0];
    if(arr.size() == 2) {
        if(arr[0] > arr[1]) return arr[0];
        else return arr[1];
    }
    if(arr[0] > arr[arr.size()/2] && arr[0] > arr[arr.size()-1]) return arr[0];
    if(arr[arr.size()/2] > arr[0] && arr[arr.size()/2] > arr[arr.size()-1]) return arr[arr.size()/2];
    if(arr[arr.size()-1] > arr[0] && arr[arr.size()-1] > arr[arr.size()/2]) return arr[arr.size()-1];
    return -1;
}
/*98. Count Even Numbers in Array
Write a C++ program to count the even number of elements in a given array of integers.
Sample Input:{{ 1, 5, 7, 9, 10, 12 }, {0, 2, 4, 6, 8, 10}}
Sample Output:[2, 6]*/
short CountEvenNum(const vector<int> &numbers) {
    if(numbers.empty()) {
        cerr<<"The numbers array is empty"<<endl;
        return -1;
    }
    else if(numbers.size() == 1) {
        if(numbers[0] % 2 == 0) return 1;
        return 0;
    }
    short count = 0;
    for(int number : numbers) {
        if(number % 2 == 0) count++;
    }
    return count;
}
/*99. Difference Between Largest and Smallest Values in Array
Write a C++ program to compute the difference between the largest and smallest values in a given array of integers and length one or more.
Sample Input:{{ 1, 5, 7, 9, 10, 12}, {0, 2, 4, 6, 8, 10}}
Sample Output:[11, 10]*/
int DiffBetLarSmall(const vector<int> &numbers) {
    if(numbers.empty()) {
        cerr<<"The numbers array is empty"<<endl;
        return -1;
    }
    else if(numbers.size() == 1) return numbers[0];
    else if(numbers.size() == 2) {
        if(numbers[0] > numbers[1]) return numbers[0] - numbers[1];
        else return numbers[1] - numbers[0];
    }
    int largest = numbers[0], smallest = numbers[0];
    for(int number : numbers) {
        if(number > largest) largest = number;
        if(number < smallest) smallest = number;
    }
    return (largest - smallest);
}
/*100. Sum Array Elements Excluding 17
Write a C++ program to compute the sum of values in a given array of integers except the number 17.
Return 0 if the given array has no integers.
Sample Input: { 1, 5, 7, 9, 10, 17 }
Sample Output:
Sum of values in the array of integers except the number 17: 32 */
int SumEleExclud17(const vector<int> &numbers) {
    if(numbers.empty()) return 0;
    else if(numbers.size() == 1) {
        if(numbers[0] != 17) return numbers[0];
        return 0;
    }
    else if(numbers.size() == 2) {
        if(numbers[0] != 17 && numbers[1] != 17) return numbers[0] + numbers[1];
        if(numbers[0] != 17) return numbers[0];
        if(numbers[1] != 17) return numbers[1];
        return 0;
    }
    int sum = 0;
    for(int number : numbers) {
        if(number != 17) sum += number;
    }
    return sum;
}
// For-Loops
/*61. Print ASCII Characters with Their Values
Write a C++ program that prints all ASCII characters with their values.
Sample Output:
Input the starting value for ASCII characters: 65
Input the ending value for ASCII characters: 75
The ASCII characters:
65 --> A
66 --> B
67 --> C
68 --> D
69 --> E
70 --> F
71 --> G
72 --> H
73 --> I
74 --> J
75 --> K*/
void PrintASCII(short startNum = 32, short endNum = 126) {
    if(startNum<32||endNum>126) return;
    cout<<"The ASCII characters in the range["<<startNum<<", "<<endNum<<"]: "<<endl;
    for(short i = startNum;i<=endNum;i++) cout<<i<<" --> "<<char(i)<<endl;
}
/*62. Power Calculation Using a For Loop
Write a program in C++ to find the power of any number using a for loop.
Sample Output:
Input the base: 2
Input the exponent: 5
2 ^ 5 = 32*/
int power(int base, int exponent) {
    long int result = 1;
    for(int i = 1;i<=exponent;i++) result *= base;
    return result;
}
/*63. Print All Factors of a Number
Write a program in C++ to enter any number and print all factors of the number.
Sample Output:
Input a number: 63
The factors are: 1 3 7 9 21 63*/
vector<int> FactorsOfNum(int num) {
    vector<int> factors;
    for(int i = 1;i<=num;i++) {
        if(num%i == 0)
        factors.push_back(i);
    }
    return factors;
}
/*64. One's Complement of a Binary Number
Write a program in C++ to find the one's complement of a binary number.
Sample Output:
Input a 8 bit binary value: 10100101
The original binary = 10100101
After ones complement the number = 01011010*/
bool isbinary(const string& num) {
    if (num.empty()) {
        cerr << "The number is empty" << endl;
        return false;
    }
    for (char ch : num) {
        if (ch != '0' && ch != '1')
        return false;
    }
    return true;
}
string OnesCom(const string& binaryNum) {
    if (binaryNum.empty()) {
        cerr << "The number is empty" << endl;
        return "empty error";
    }
    if (!isbinary(binaryNum)) {
        cerr << "Not a binary number" << endl;
        return "invalid binary input";
    }
    string result;
    for (char bit : binaryNum) {
        if (bit == '0') result += '1';
        else result += '0';
    }
    return result;
}
/*65. Two's Complement of a Binary Number
Write a program in C++ to find the two's complement of a binary number.
Sample Output:
Input a 8 bit binary value: 01101110
The original binary = 01101110
After ones complement the value = 10010001
After twos complement the value = 10010010*/
string TwosCom(const string& binaryNum) {
    if (binaryNum.empty()) {
        cerr << "The number is empty" << endl;
        return "empty error";
    }
    if (!isbinary(binaryNum)) {
        cerr << "Not a binary number" << endl;
        return "invalid binary input";
    }
    string onecom = OnesCom(binaryNum);
    string result = onecom;
    bool carry = true;
    for (int i = onecom.length() - 1; i >= 0; --i) {
        if (carry) {
            if (onecom[i] == '0') {
                result[i] = '1';
                carry = false;
            }
            else {
                result[i] = '0';
                // keep carry = true
            }
        } 
        else result[i] = onecom[i];
    }
    return result;
}
/*66. Checkerboard Pattern with "black" and "white"
Write code to create a checkerboard pattern with the words "black" and "white".
Sample Output:
Input number of rows: 5
black-white-black-white-black
white-black-white-black-white
black-white-black-white-black
white-black-white-black-white
black-white-black-white-black*/
void PrintPattern(const string &str1, const string &str2, int rows, char separator = '-') {
    if(str1.empty()||str2.empty()) {
        cerr<<"one of the string input is empty"<<endl;
        return;
    }
    cout<<endl;
    for(int i = 0;i<rows;i++) {
        for(int j = 0;j<rows;j++) {
            if ((i + j) % 2 == 0) cout << str1;
            else cout << str2;
            if(j != rows-1) cout<<separator;
        }
        cout<<endl;
    }
}
/*67. Sum of Series 1.2 + 2.3 + 3.4 + ...
Write a program in C++ to calculate the sum of the series 1.2 + 2.3 + 3.4 + 4.5 + 5.6 + .......
Sample Output:
Input the last integer between 1 to 98 without fraction you want to add: 1.2 + 2.3 + 3.4 + 4.5 + 5.6 + 6.7 + 7.8 + 8.9 + 9.1 + 10.11 The sum of the series = 59.61 */
float SumOfSeries(int endser, int start = 1) {
    if (start <= 0 || endser <= 0) return -1;
    float sum = 0;
    for (int i = start; i <= endser; i++) sum += i + (i + 1) / 10.00f;
    return sum;
}
/*68. First N Numbers for a Specific Base
Write a program that will print the first N numbers for a specific base.
Sample Output:
Print the first N numbers for a specific base:
The number 11 in base 10 = 1*(10^1)+1*(10^0)=11
Similarly the number 11 in base 7 = 1*(7^1)+1*(7^0)=8
----------------------------------------------------------------
Input the number of term: 15
Input the base: 9
The numbers in base 9 are:
1 2 3 4 5 6 7 8 10 11 12 13 14 15 16*/
void printFirNNum(int base, int term) {
    if(base <= 1 || term <= 0) return;
    int count = 1;
    for(int i = 0;i<=ceil(term/base);i++) {
        for(int j = 1;j<base;j++) {
            cout<<count<<' ';
            if(count == term + (10 - base)) break;
            count++;
        }
        count++;
    }
    cout<<endl;
}
/*69. Square Matrix with Diagonal Zero and Incrementing Off-Diagonals
Write a program in C++ to produce a square matrix with 0's down the main diagonal, 1's in the entries just above and below the main diagonal, 2's above and below that, etc.
0 1 2 3 4
1 0 1 2 3
2 1 0 1 2
3 2 1 0 1
4 3 2 1 0
Sample Output:    
Input number or rows: 8                                                                                      
0  1  2  3  4  5  6  7                                                                                        
1  0  1  2  3  4  5  6                                                                                        
2  1  0  1  2  3  4  5                                                                                        
3  2  1  0  1  2  3  4                                                                                        
4  3  2  1  0  1  2  3                                                                                        
5  4  3  2  1  0  1  2                                                                                        
6  5  4  3  2  1  0  1                                                                                        
7  6  5  4  3  2  1  0 */
vector<vector<int>> SquMatZeroDigo(int rows) {
    int sNum = 0;
    vector<int> tempRow;
    vector<vector<int>> result;
    for(int j = 0;j<rows;j++) {
        for(int i = sNum;i < rows + sNum;i++) tempRow.push_back(abs(i));
        result.push_back(tempRow);
        tempRow.clear();
        sNum--;
    }
    return result;
}
void printSquZeroMat(int rows) {
    cout<<endl;
    vector<vector<int>> SquMat = SquMatZeroDigo(rows);
    for(vector<int> Row : SquMat) {
        for(int num : Row) cout<<num<<' ';
        cout<<endl;
    }
}
/*70. Decimal to Binary Conversion
Write a program in C++ to convert a decimal number to a binary number.
Sample Output:
Input a decimal number: 35
The binary number is: 100011*/
string DecToBin(int num) {
    string binary;
    vector<int> modtwo;
    while (num) {
        modtwo.push_back(num%2);
        num /= 2;
    }
    for(int i = modtwo.size()-1;i>=0;i--) binary += to_string(modtwo[i]);
    return binary;
}
// Strings
/*34. Remove a Specific Word from a String
Write a C++ program that removes a specific word from a given string.
Return the updated string.
Test Data:
("Exercises Practice Solution", "Solution") -> "Exercises Practice"
("Exercises Practice Solution", "Practice ") -> "Exercises Solution"
("Exercises Practice Solution", " Solution") -> " Practice Solution"*/
vector<string> separatorStr(const string &str) {
    if(str.empty()) {
        cerr<<"The input string is empty."<<endl;
        return {};
    }
    string temp;
    vector<string> result;
    for(int i = 0;i<str.length();i++) {
        if(str[i] == ' '||i == str.length()-1) {
            if(i==str.length()-1) temp += str[i];
            result.push_back(temp);
            temp.clear();
        }
        else temp += str[i];
    }
    return result;
}
bool equalStr(const string& str1, const string& str2) {
    if(str1.empty()||str2.empty()) {
        cerr<<"One of the inputs is empty."<<endl;
        return false;
    }
    if(str1.length() != str2.length()) return false;
    for(int i = 0;i<str1.length();i++) {
        if(str1[i]!=str2[i])
        return false;
    }
    return true;
}
string removeWord(const string& str, const string& word) {
    if(str.empty()||word.empty()) {
        cerr<<"One of the inputs is empty."<<endl;
        return "Empty Error";
    }
    if(str.length()<word.length()) {
        cerr<<"The word to remove is longer than the original string."<<endl;
        return "Length Error";
    }
    string NewWord, result;
    for(char ch : word) {
        if(ch == ' ') continue;
        else NewWord += ch;
    }
    vector<string> wordHolder = separatorStr(str);
    for(string loopword : wordHolder) {
        if(equalStr(loopword, NewWord)) continue;
        else {
            result += loopword;
            result += " ";
        }
    }
    return result;
}
/*35. Reverse Words with Odd Lengths in a String
Write a C++ program to reverse all words that have odd lengths in a string.
Test Data:
("Exercises Practice Solution" ) -> "sesicrexE Practice Solution"
("The quick brown fox jumps over the lazy dog") -> "ehT kciuq nworb xof spmuj over eht lazy dog."*/
string reverseOddLen(const string &str) {
    if (str.empty()) {
        cerr << "The input string is empty." << endl;
        return "Empty Error";
    }
    string result;
    vector<string> words = separatorStr(str);
    for (int i = 0; i < words.size(); ++i) {
        string word = words[i];
        if (word.length() % 2 != 0) reverse(word.begin(), word.end());
        result += word;
        if (i != words.size() - 1) result += " ";
    }
    return result;
}
/*36. Check for Two Consecutive Identical Letters
Write a C++ program to check whether there are two consecutive (following each other continuously), identical letters in a given string.
Test Data:
("Exercises") -> 0
("Yellow") -> 1*/
bool CheckTwoIdenLette(const string &str) {
    char las_ch = '\0';
    for(char ch : str) {
        if(ch == las_ch) return true;
        if(ch) las_ch = ch;
    }
    return false;
}
/*37. Count Occurrences of a Specific Character in a String
Write a C++ program that counts the number of instances of a certain character in a given string.
Test Data:
("Exercises", "e") -> 2
("Compilation Time", "i") -> 3*/
short CountOccuSpecCh(const string &str, const char ch) {
    short count = 0;
    for(int i = 0;i<str.length();i++) {
        if(str[i] == ch)
        count++;
    }
    return count;
}
/*38. Remove a Specific Character from a String
Write a C++ program that removes a specific character from a given string.
Return the updated string.
Test Data:
("Filename", "e") -> "Filnam"
("Compilation Time", "i") -> "Complaton Tme"*/
string removeChStr(const string &str, const char ch) {
    if(str.empty()) {
        cerr<<"The string is empty."<<endl;
        return "Empty Error";
    }
    if(str.length() == 1) return str;
    string result;
    for(int i = 0;i<str.length();i++) {
        if(str[i] != ch) result += str[i];
    }
    return result;
}
/*39. Check if a String Contains Only Unique Characters
Write a C++ program that checks whether a given string contains unique characters or not.
Return true if the string contains unique characters otherwise false.
Test Data:
("Filename") -> 0
("abc") -> 1*/
bool UniqChar(const string &str) {
    if(str.empty()) {
        cerr<<"The string is empty."<<endl;
        return false;
    }
    if(str.length() == 1) return true;
    for(int i = 0;i<str.length();i++) {
        for(int j = 0;j<str.length();j++) {
            if(str[i] == str[j] && j != i)
            return false;
        }
    }
    return true;
}
/*40. Select Lowercase Characters at the Same Position from Two Strings
For two given strings, str1 and str2, write a C++ program to select only the characters that are lowercase in the other string at the same position.
Return characters as a single string.
Test Data:
("Java", "jscript") -> "scr"
("jScript", "Java") -> "Jva"
("cpp", "c++") -> "c++"*/
string lowerCaseChar(const string &str1, const string &str2) {
    if(str1.empty()||str2.empty()) {
        cerr<<"empty string passed to the function"<<endl;
        return "Empty Error";
    }
    string result;
    for(int i = 0;i<str1.length();i++) {
        if(islower(str1[i])) result += str2[i];
    }
    return result;
}
/*41. Position of the Second Occurrence of a Substring
Write a C++ program that finds the position of the second occurrence of a string in another string.
If the substring does not appear at least twice return -1.
Test Data:
("the qu qu", "qu") -> 7
("theququ", "qu") -> 5
("thequ", "qu") -> -1*/
bool issubstr(const string &str, const string &sstr, short position) {
    for (int j = 0; j < sstr.length(); j++) {
        if (str[position + j] != sstr[j])
        return false;
    }
    return true;
}
short PosSecOcc(const string &str, const string &sstr) {
    if(str.empty()||sstr.empty()) {
        cerr<<"empty string passed to the function"<<endl;
        return -1;
    }
    short count = 2, Position = 0;
    for(int i = 0;i<str.length();i++) {
        if(i+sstr.length() <= str.length()) {
            if(issubstr(str, sstr, i)) count--;
        }
        if(count == 0) return i;
    }
    return -1;
}
/*42. Alternate the Case of Each Letter in a String
Write a C++ program that alternates the case of each letter in a given string of letters.
Pattern: First lowercase letter then uppercase letter and so on.
Test Data:
("JavaScript") -> "jAvAsCrIpT"
("Python") -> "pYtHoN"
("C++") -> "c++" */
string AlterTheCaseEachlette(const string &str) {
    if(str.empty()) {
        cerr<<"The string is empty."<<endl;
        return "Empty Error";
    }
    string result;
    for(char ch : str) {
        if(islower(ch)) result += toupper(ch);
        else if(isupper(ch)) result += tolower(ch);
        else result += ch;
    }
    return result;
}
// Recursion
/*6. Reverse a String Using Recursion
Write a C++ program to reverse a string using recursion*/
string recuReverseStr(const string &str, int index = -1, bool begin = true) {
    if(str.empty()) {
        cerr<<"The input string is empty."<<endl;
        return "Empty Error";
    }
    if (index == -1 && begin) index = str.length() - 1;
    if (index < 0 && !begin) return "";
    return str[index] + recuReverseStr(str, index - 1, false);
}
/*7. Power Calculation Using Recursion
Write a C++ program to implement a recursive function to calculate the power of a number.*/
double recuPower(double base, int pownum) {
    if(base == 0 && pownum == 0) {
        cerr << "Error: 0^0 is undefined." << endl;
        return -1;
    }
    else if(base == 0 && pownum < 0) {
        cerr << "Error: Division by zero (0 raised to negative power)." << endl;
        return -1;
    }
    else if(pownum == 0) return 1;
    else if(pownum < 0) return 1.0 / recuPower(base, -pownum);
    else return base * recuPower(base, pownum - 1);
    return 0;
}
/*8. Check if a String is a Palindrome Using Recursion
Write a C++ program to implement a recursive function to check if a given string is a palindrome.*/
bool isPalindromeRec(const string& str, int left = 0, int right = -1) {
    if (right == -1) right = str.length() - 1;
    if (left >= right) return true;
    if (str[left] != str[right]) return false;
    return isPalindromeRec(str, left + 1, right - 1);
}
int main() {
    NewLines(5);

    //////////////Basic Algorithm//////////////
    PrintCategory("Basic Algorithm");
    vector<vector<int>> testvec1 = {
        { 10, 20, 40, 50 },
        { 5, 20, 40, 10 },
        { 10, 20, 40, 10 },
        { 12, 24, 35, 55 }
    };
    for(int i = 0;i<testvec1.size();i++) Test(i+1, Check10FirLas(testvec1[i]));
    doubleVec<int> dvec1({ 10, 20, 40, 50 }, { 10, 20, 40, 50 });
    doubleVec<int> dvec2({ 10, 20, 40, 50 }, { 10, 20, 40, 5 });
    doubleVec<int> dvec3({ 10, 20, 40, 50 }, { 1, 20, 40, 5 });
    Test(5, SameFirstOrLast(dvec1));
    Test(6, SameFirstOrLast(dvec2));
    Test(7, SameFirstOrLast(dvec3));
    vector<vector<int>> testvec2 = {
        { 10, 20, 30, 40, 50 },
        { 10, 20, -30, -40, 50 }
    };
    for(int i = 0;i<testvec2.size();i++) Test(i+8, sumVec(testvec2[i]));
    VecTest(10, rotateVec({ 10, 20, 30, 40 }));
    VecTest(11, ReverseArr({ 0, 10, 20, 30, 40 }));
    VecTest(12, MiddEleTwo({0, 10, 20, 30, 40}, {0, -10, -20, -30, -40}));
    VecTest(13, FirAndLasEle({ 10, 20, -30, -40, 30 }));
    Test(14, CheckTwoNumArr({ 12, 20 }));
    Test(15, CheckTwoNumArr({ 14, 15 }));
    Test(16, CheckTwoNumArr({ 11, 21 }));
    Test(17, CheckTwoNotNum({ 12, 20 }));
    Test(18, CheckTwoNotNum({ 14, 15 }));
    Test(19, CheckTwoNotNum({ 11, 21 }));
    Test(20, CheckArrTwo({ 12, 20 }));
    Test(21, CheckArrTwo({ 20, 20 }));
    Test(22, CheckArrTwo({ 10, 10 }));
    Test(23, CheckArrTwo({ 10 }));
    VecTest(24, Replace7to1({ 1, 5, 7 }));
    VecTest(25, Replace7to1({ 1, 5, 3, 7 }));
    doubleVec<int> dvec4({ 1, 5, 7 }, { 1, 5, 3 });
    VecTest(26, SumTwoArrFindLar(dvec4));
    VecTest(27, CreateArr({ 1, 5, 7, 9, 11, 13 }));
    VecTest(28, CreateArr({ 1, 5, 7, 44, 9, 20, 11, 13 }));
    VecTest(29, SwapFirAndLas({ 1, 5, 7, 9, 11, 13 }));
    VecTest(30, CreateArr2({ 1, 5, 7, 9, 11, 13 }));
    vector<vector<int>> testvec3 = {
        {1},
        {1, 2, 9},
        {1, 2, 9, 3, 3}, 
        {1, 2, 3, 4, 5, 6, 7}, 
        {1, 2, 2, 3, 7, 8, 9, 10, 6, 5, 4}
    };
    for(int i = 0;i < testvec3.size();i++) Test(i + 31, LargestFirLasMidd(testvec3[i]));
    vector<vector<int>> testvec4 = {{ 1, 5, 7, 9, 10, 12 }, {0, 2, 4, 6, 8, 10}};
    for(int i = 0;i < testvec4.size();i++) Test(i + 36, CountEvenNum(testvec4[i]));
    vector<vector<int>> testvec5 = {{ 1, 5, 7, 9, 10, 12}, {0, 2, 4, 6, 8, 10}};
    for(int i = 0;i < testvec5.size();i++) Test(i + 38, DiffBetLarSmall(testvec5[i]));
    Test(40, SumEleExclud17({ 1, 5, 7, 9, 10, 17 }));

    ///////////////For-Loops///////////////
    PrintCategory("For-Loops");
    Test(1, 0, true);
    PrintASCII(65, 75);
    Test(2, power(2, 5));
    VecTest(3, FactorsOfNum(63));
    Test(4, OnesCom("10100101"));
    Test(5, TwosCom("01101110"));
    Test(6, 0, true);
    PrintPattern("black", "white", 5);
    Test(7, SumOfSeries(10));
    Test(8, 0, true);
    printFirNNum(9, 15);
    Test(9, 0, true);
    printSquZeroMat(8);
    Test(10, DecToBin(35));

    ////////////strings///////////////
    PrintCategory("strings");
    Test(1, removeWord("Exercises Practice Solution", "Solution"));
    Test(2, removeWord("Exercises Practice Solution", "Practice "));
    Test(3, removeWord("Exercises Practice Solution", " Solution"));
    Test(4, reverseOddLen("Exercises Practice Solution"));
    Test(5, reverseOddLen("The quick brown fox jumps over the lazy dog"));
    Test(6, CheckTwoIdenLette("Exercises"));
    Test(7, CheckTwoIdenLette("Yellow"));
    Test(8, CountOccuSpecCh("Exercises", 'e'));
    Test(9, CountOccuSpecCh("Compilation Time", 'i'));
    Test(10, removeChStr("Filename", 'e'));
    Test(11, removeChStr("Compilation Time", 'i'));
    Test(12, UniqChar("Filename"));
    Test(13, UniqChar("abc"));
    Test(14, lowerCaseChar("Java", "jscript"));
    Test(15, lowerCaseChar("jScript", "Java"));
    Test(16, lowerCaseChar("cpp", "c++"));
    Test(17, PosSecOcc("the qu qu", "qu"));
    Test(18, PosSecOcc("theququ", "qu"));
    Test(19, PosSecOcc("thequ", "qu"));
    Test(20, AlterTheCaseEachlette("JavaScript"));
    Test(21, AlterTheCaseEachlette("Python"));
    Test(22, AlterTheCaseEachlette("C++"));

    ///////////Recursion///////////
    PrintCategory("Recursion");
    Test(1, recuReverseStr("Compilation"));
    Test(2, recuReverseStr("Exercises"));
    Test(3, recuReverseStr("Yellow")); 
    Test(4, recuPower(2, 10));
    Test(5, recuPower(5, 3));
    Test(6, recuPower(7, 2));
    Test(7, recuPower(-2, 10));
    Test(8, recuPower(-5, -3));
    Test(9, recuPower(7, -2));
    Test(10, isPalindromeRec("kayak"));
    Test(11, isPalindromeRec("deified"));
    Test(12, isPalindromeRec("rotator"));
    Test(13, isPalindromeRec("repaper"));
    Test(14, isPalindromeRec("hello"));
    Test(15, isPalindromeRec("deed"));
    Test(16, isPalindromeRec("peep"));
    Test(17, isPalindromeRec("wow"));
    Test(18, isPalindromeRec("Yellow"));
    Test(19, isPalindromeRec("noon"));
    return 0;
}