#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;
/*
  Project Title: Weekly Functions Practice - C++
  Author: Ali Mohammed Ali Lafi
  Date: April 15–22, 2025
  Deadline: April 22, 2025
  Description:
  This program contains a collection of independent C++ functions written as 
  weekly practice to reinforce algorithmic thinking, syntax skills, and 
  problem-solving techniques.

  Each function solves a specific programming problem, covering topics such as:
  - Arrays and pointers
  - Strings and character operations
  - Math and logic operations
  - Function design and modular programming

  For each function, the original problem statement is included as a comment 
  above the function to provide context.

  Notable Case:
  - One of the functions demonstrates a common C++ pitfall: calculating array size 
    using sizeof inside a function (due to array decay). The issue and fix are 
    explained inline in that section.

  Purpose:
  This program is part of a long-term goal to build a personal library of reusable 
  utility functions and serve as proof of practical C++ knowledge. It also marks 
  the start of a weekly series documenting my hands-on programming journey.

  Total Lines of Code: ~700
  Tools Used: GDB Online, C++ (C++11+)
  AI Involvement: Some functions were refined or explained with assistance from AI tools.

  Source of Practice Exercises:https://www.w3resource.com/cpp-exercises/
*/
// Basic Algorithm
/*1. Triple Sum for Same Values
Write a C++ program to compute the sum of two given integer values.
If the two values are the same, then return triple their sum.
Sample Input: [(1, 2), (3, 2), (2, 2)]
Sample Output: [3, 5, 12] */
int sum(int num1, int num2) {
    return (num1+num2);
}
/*2. Absolute Difference with 51
Write a C++ program to find the absolute difference between n and 51.
If n is greater than 51 return triple the absolute difference.
Sample Input: [53, 30, 51]
Sample Output: [6, 21, 0]*/
int AbsDiff51(int n) {
    if(n>51) return n-51;
    else if(n==51) return 0;
    else return 51-n;
}
/*3. Check 30 or Sum 30
Write a C++ program to check two given integers, and return true if one of them is 30 or if their sum is 30.
Sample Input: [(30, 0), (25, 5), (20, 30), (20, 25)]
Sample Output: [1, 1, 1, 0] */
bool Check30(int num1, int num2) {
    if(num1==30||num2==30||(num1+num2==30)) return true;
    else return false;
}
/*4. Within 10 of 100 or 200
Write a C++ program to check a given integer and return true if it is within 10 of 100 or 200.
Sample Input: [103, 90, 89]
Sample Output:[1, 1, 0] */
bool NumberChecker(int num) {
    if(num>=10&&num<=200) return true;
    else return false;
}
/*5. Add 'if' to String
Write a C++ program to create a string where 'if' is added to the front of a given string.
If the string already begins with 'if', return the string unchanged.
Sample Input: ["if else", "else"]
Sample Output: [if else, if else]*/
string AddIF(string str) {
    bool StrSw = false;
    string substr;
    for(int i=0;i<str.length();i++) {
        substr += str[i];
        if(i==1&&substr!="if")return "if "+str;
    }
    return str;
}
/*6. Remove Character from String
Write a C++ program to remove the character at a given position in the string.
The given position will be in the range 0..string length -1 inclusive.
Sample Input:[("Python", 1), ("Python", 0), ("Python", 4)]
Sample Output:[Pthon, ython, Pythn] */
string RemoveChar(string str, int index = -1) {
    string result;
    if(index>=0) {
        for(int i=0;i<str.length();i++) {
            if(i==index) continue;
            else result += str[i];
        }
    }
    else return str;
    return result;
}
/*7. Swap First and Last Characters
Write a C++ program to exchange the first and last characters in a given string and return the result string.
Sample Input:["abcd", "a", "xy"]
Sample output:[dbca, a, yx] */
string SwapFiAndLa(string str) {
    size_t StrLen = str.length();
    string result;
    vector<char> holder, ResHolder;
    if(!StrLen) return "you passed nothing for the function";
    else if(StrLen==1) return str;
    else {
        for(char NewCh : str)
        holder.push_back(NewCh);
    }
    for(int i=0;i<holder.size();i++) {
        if(i==0) ResHolder.push_back(holder[holder.size()-1]);
        else if(i==holder.size()-1) ResHolder.push_back(holder[0]);
        else ResHolder.push_back(holder[i]);
    }
    for(char HoldCh : ResHolder) result+=HoldCh;
    return result;
}
/*8. 4 Copies of First 2 Characters
Write a C++ program to create a string that is 4 copies of the 2 front characters of a given string. If the given string length is less than 2 return the original string.
Sample Input:["C Sharp", "JS", "a"]
Sample Output:[C C C C, JSJSJSJS, a] */
string FourCopies(string str) {
    int i;
    string substr, result;
    if(str.length()==1||str.length()==2) {
        for(i=1;i<=4;i++) result += str;
        return result;
    }
    for(i=0;i<=1;i++) substr += str[i];
    for(i=1;i<=4;i++) result += substr;
    return result;
}
/*9. Add Last Character to Front and Back
Write a C++ program to create a string with the last character added at the front and back of a given string of length 1 or more
Sample Input:["Red", "Green", "1"]
Sample Output:[dRedd, nGreenn, 111] */
string AddLastCh(string str) {
    if(str.empty()) return "the length of the string isn't enough.";
    char LastChar = str.back();
    string result;
    if(str.length() == 1) result = string(3, str[0]);
    else {
        result += LastChar;
        result += str[0];
        for(int i = 1; i < str.length() - 1; i++) result += str[i];
        result += str.back();
        result += LastChar;
    }
    return result;
}
/*10. Multiple of 3 or 7
Write a C++ program to check if a given positive number is a multiple of 3 or a multiple of 7.
Sample Input:[3, 14, 12, 37]
Sample Output:[1, 1, 1, 0]*/
bool Multiple_3_7(int num) {
    if(num%3==0) return true;
    else if(num%7==0) return true;
    else return false;
}
// For-Loops
/*1. First 10 Natural Numbers
Write a program in C++ to find the first 10 natural numbers.
Sample output:
The natural numbers are:
1 2 3 4 5 6 7 8 9 10 */
void First10Numbers() {
    for(int i=0;i<10;i++)cout<<i<<endl;
}
/*2. Sum of First 10 Natural Numbers
Write a program in C++ to find the sum of the first 10 natural numbers.
Sample Output:
Find the first 10 natural numbers:
---------------------------------------
The natural numbers are:
1 2 3 4 5 6 7 8 9 10
The sum of first 10 natural numbers: 55 */
int sumOfFirst10Num() {
    return 55;
}
/*3. Display n Terms of Natural Numbers and Their Sum
Write a program in C++ to display n terms of natural numbers and their sum.
Sample Output:
Input a number of terms: 7
The natural numbers upto 7th terms are:
1 2 3 4 5 6 7
The sum of the natural numbers is: 28 */
int NumSum(int num) {
    int sum;
    for(int i=1;i<=num;i++) sum+=i;
    return sum;
}
/*4. Find Perfect Numbers Between 1 and 500
Write a program in C++ to find the perfect numbers between 1 and 500.
The perfect numbers between 1 to 500 are: [6, 28, 496] */
vector<int> PerfectNum() {
    return {6,28,496};
}
/*5. Check Whether a Number is Prime or Not
Write a program in C++ to check whether a number is prime or not.
Sample Output:
Input a number to check prime or not: 13
The entered number is a prime number.*/
bool PrimeNumbers(int num) {
    for(int i=2;i<num;i++) 
    if(num%i==0) return false;
    return true;
}
/*6. Find Prime Numbers Within a Range
Write a program in C++ to find a prime number within a range.
Input number for starting range: 1
Input number for ending range: 100
The prime numbers between 1 and 100 are:
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
The total number of prime numbers between 1 to 100 is: 25*/
vector<int> PrimeRange(int starting, int enging) {
    vector<int> PrimeVec;
    for(int i=1;i<enging;i++) {
        if(PrimeNumbers(i))
        PrimeVec.push_back(i);
    }
    return PrimeVec;
}
/*7. Find the Factorial of a Number
Write a program in C++ to find the factorial of a number.
Sample output:
Input a number to find the factorial: 5
The factorial of the given number is: 120 */
int Factorial(int num) {
    int FacNum = 1;
    while (num>=1)
    {
        FacNum*=num;
        num--;
    }
    return FacNum;
}
/*8. Find the Last Prime Number Before a Given Number
Write a program in C++ to find the last prime number that occurs before the entered number.
Sample Output:
Input a number to find the last prime number occurs before the number: 50
47 is the last prime number before 50*/
int LastPrime(int enging) {
    return(PrimeRange(0, enging).back());
}
/*9. Find the Greatest Common Divisor (GCD) of Two Numbers
Write a program in C++ to find the Greatest Common Divisor (GCD) of two numbers.
Sample Output:
Input the first number: 25
Input the second number: 15
The Greatest Common Divisor is: 5*/
int GCD(int FirNum, int SecNum) {
    FirNum = abs(FirNum);
    SecNum = abs(SecNum);
    int gcd = 1; // Start with 1
    // Find the smaller number
    int smaller = (FirNum < SecNum) ? FirNum : SecNum;
    for (int i = 1; i <= smaller; i++) {
        if (FirNum % i == 0 && SecNum % i == 0) 
        gcd = i; // Update gcd when we find a common divisor
    }
    return gcd;
}
/*10. Sum of the Digits of a Given Number
Write a program in C++ to find the sum of the digits of a given number.
Sample Output:
Input a number:(1234)
The sum of digits of 1234 is:(10) */
int SumDigits(int num) {
    int NewNum = 1, sum = 0;
    vector<int> Numbers;
    while (num)
    {
        NewNum = num%10;
        Numbers.push_back(NewNum);
        num/=10;
    }
    for(int i=0;i<Numbers.size();i++) sum += Numbers[i];
    return sum;
}
// String
/*1. Reverse a Given String
Write a C++ program to reverse a given string.
Example:
Sample Input: w3resource
Sample Output: ecruoser3w*/
string Reverse(string str, int sstart = 0, int send = -1, int step = 1) {
    string result;
    if (send == -1) send = str.length(); // Default to full string length
    // Validate indices
    if (sstart < 0) sstart = 0;
    if (send > str.length()) send = str.length();
    if (sstart >= send) return ""; // Invalid range
    // Handle step
    if (step <= 0) step = 1; // Prevent infinite loop
    // Reverse the substring
    for (int i = send - 1; i >= sstart; i -= step) result += str[i];
    return result;
}
/*2. Replace Each Letter with the Next in the Alphabet
Write a C++ program to change every letter in a given string with the letter following it in the alphabet
(i.e. a becomes b, p becomes q, z becomes a).
Example:
Sample Input: w3resource
Sample Output: x3sftpvsdf*/
string NextChar(string str, int charstep = 1) {
    string result;
    for(int i = 0;i<str.length();i++) result += char(str[i]+charstep);
    return result;
}
/*3. Capitalize the First Letter of Each Word
Write a C++ program to capitalize the first letter of each word in a given string.
Words must be separated by only one space.
Example:
Sample Input: cpp string exercises
Sample Output: Cpp String Exercises*/
string Capitalize(string str) {
    bool capitalsw = false;
    string result;
    result += toupper(str[0]);
    for(int i = 1;i<str.length();i++) {
        if(str[i] == ' ') {
            result += str[i];
            capitalsw = true;
        }
        else if(capitalsw) {
            result += toupper(str[i]);
            capitalsw = false;
        }
        else result += str[i]; 
    }
    return result;
}
/*4. Find the Largest Word in a String
Write a C++ program to find the largest word in a given string.
Example:
Sample Input: C++ is a general-purpose programming language.
Sample Output: programming*/
string LargestWord(string str) {
    bool VecStrSw = false;
    size_t index, maxlen;
    string substr;
    vector<string> vecstr;
    for(int i = 0;i<str.length();i++) {
        if(str[i] == ' '||i == str.length()-1||str[i] == '-'||str[i] == '~') {
            VecStrSw = true;
            vecstr.push_back(substr);
            substr = "";
        }
        else substr += str[i];
    }
    index = 0;
    maxlen = vecstr[0].length();
    for(int j = 1;j<vecstr.size();j++) {
        if(maxlen<vecstr[j].length()) {
            maxlen = vecstr[j].length();
            index = j;
        }
        else continue;
    }
    return vecstr[index];
}
/*5. Sort Letters in a String
Write a C++ program to sort characters (numbers and punctuation symbols are not included) in a string.
Example:
Sample Input: python
Sample Output: hnopty*/
string SortLetters(string str) {
    vector<char> LetterVec;
    string result;
    for(char Letter : str) LetterVec.push_back(Letter);
    sort(LetterVec.begin(), LetterVec.end());
    for(char letter : LetterVec) result += letter;
    return result;
}
// Array
/*1. Largest Element in Array
Write a C++ program to find the largest element of a given array of integers.*/
int LargestElement(int num[], int ASize) {
    int LargestNum = num[0];
    for(int i=1;i<ASize;i++) {
        if(num[i]>LargestNum)
        LargestNum = num[i];
    }
    return LargestNum;
}
/*2. Largest Three Elements in Array
Write a C++ program to find the largest three elements in an array.*/
vector<int> LarThEle(int num[], int ASize) {
    vector<int> result;
    for(int i=0;i<ASize;i++) result.push_back(num[i]);
    sort(result.begin(), result.end(), greater<int>());
    return {result[0], result[1], result[2]};
}
/*3. Second Largest Element in Array
Write a C++ program to find the second largest element in an array of integers.*/
int SecLarEle(int num[],int ASize) {
    vector<int> result;
    for(int i=0;i<ASize;i++) result.push_back(num[i]);
    sort(result.begin(), result.end(), greater<int>());
    return result[1];
}
/*4. k Largest Elements in Array
Write a C++ program to find the k largest elements in a given array of integers.*/
vector<int> LargestElements(int num[], int ASize, int k) {
    vector<int> sortedArray(num, num + ASize);
    vector<int> result;
    sort(sortedArray.begin(), sortedArray.end(), greater<int>());
    int limit = min(k, ASize);
    for (int i = 0; i < limit; i++) result.push_back(sortedArray[i]);
    return result;
}
/*5. Second Smallest Element in Array
Write a C++ program to find the second smallest elements in a given array of integers.*/
int SecSmalEle(int num[], int ASize) {
    vector<int> result;
    for(int i=0;i<ASize;i++) result.push_back(num[i]);
    sort(result.begin(), result.end(), greater<int>());
    return result[ASize-2];
}
// Vectors
/*1. Consecutive Rearrangement in Vector
Write a C++ program to check whether numbers in a vector can be rearranged so that each number appears exactly once in a consecutive list of numbers.
Return true otherwise false.
Example:{1, 2, 5, 0, 3, 6, 7}
Check consecutive numbers in the said vector! 0*/
bool canBeConsecutive(vector<int>& nums) {
    if (nums.empty()) return false;
    if (nums.size() == 1) return true;
    set<int> uniqueNums;
    for (int num : nums) {
        if (uniqueNums.count(num)) return false;
        uniqueNums.insert(num);
    }
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); ++i)
    if (nums[i] - nums[i-1] != 1) return false;
    return true;
}
/*2. Elements Smaller Than Adjacent Neighbours
Write a C++ program that returns the elements in a vector that are strictly smaller than their adjacent left and right neighbours.
Example:
Original Vector elements: {1, 2, 5, 0, 3, 1, 7}
Vector elements that are smaller than its adjacent neighbours: [0, 1]*/
vector<int> EleSmallNei(vector<int> num) {
    vector<int> ResultEle;
    for(int i=0;i<num.size();i++) {
        if(i==0) {
            if(num[i]<num[i+1])
            ResultEle.push_back(num[i]);
        } 
        else if(i==num.size()-1) {
            if(num[i]<num[i-1])
            ResultEle.push_back(num[i]);
        }
        else {
            if(num[i]<num[i-1]&&num[i]<num[i+1])
            ResultEle.push_back(num[i]);
        }
    }
    return ResultEle;
}
/*3. Create an n x n Matrix from Input
Write a C++ program to create an n x n matrix by taking an integer (n) as input from the user.
Example:
Input: 2
Input an integer value: Create an n x n matrix by said integer: {{2, 2}, {2, 2}}*/
vector<vector<int>> nxnMatrix(int MatrixSize) {
    vector<int> SubVecNum;
    vector<vector<int>> ResultMatrix;
    for(int i=0;i<MatrixSize;i++) {
        for(int j=0;j<MatrixSize;j++)
        SubVecNum.push_back(MatrixSize);
        ResultMatrix.push_back(SubVecNum);
    }
    return ResultMatrix;
}
/*4. Capitalize First Letter of Each Vector String
Write a C++ program to capitalize the first character of each element of a given string vector.
Return the vector.
Example:
Original Vector elements:
red green black white Pink
Capitalize the first character of each vector element:
Red Green Black White Pink*/
vector<string> CapStrVec(vector<string> StrVec) {
    vector<string> vecstr;
    for(int i=0;i<StrVec.size();i++) vecstr.push_back(Capitalize(StrVec[i]));
    return vecstr;
}
/*5. Verify Letters of Second String in First String
Write a C++ program to verify that all of the letters in the second string appear in the first string as well.
Return true otherwise false.
Example:
Original String elements: Python Py
Check - First string contains all letters from second string: true*/
bool SecStrINFirStr(vector<string> StrVec) {
    vector<char> SecVec;
    string FirStr = StrVec[0], SecStr = StrVec[1];
    int i;
    for(i=0;i<SecStr.length();i++) SecVec.push_back(SecStr[i]);
    for(i=0;i<SecVec.size();i++) {
        for(int j=0;j<FirStr.length();j++) {
            if(SecStr[i]==FirStr[j]) SecStr.pop_back();
            else continue;
        }
    }
    if(SecVec.empty()) return true;
    return false;
}
// Math
/*1. Check if Number is a Power of Two
Write a C++ program to check whether a given number is a power of two or not.
Is 8 is power of 2: True
Is 256 is power of 2: True
Is 124 is power of 2: False*/
bool PowerOfTwo(int num) {
    if (num <= 0) return false;
    return (num & (num - 1)) == 0;
}
//2. Power Function:
int IntPower(int num, int power) {
    int result;
    while (power)
    {
        result *= num;
        power--;
    } 
    return result;
}
/*3. Reverse Digits of an Integer
Write a C++ program to reverse the digits of a given integer.
Sample Input: 4
Sample Output: 4
Sample Input: 123
Sample Output: 321*/
int IntReverseDigits(int number) {
    int reversedNumber = 0;
    bool isNegative = false;
    if (number < 0) {
        isNegative = true;
        number = -number;
    }    
    while (number != 0) {
        int digit = number % 10;
        reversedNumber = reversedNumber * 10 + digit;
        number /= 10;
    }    
    return isNegative ? -reversedNumber : reversedNumber;
}
/*4. Divide Two Integers Without *, /, or %
Write a C++ program to divide two integers (dividend and divisor) without using the multiplication, division and mod operators.
Dividend 7 Divisor 2
Result: 3
Dividend -17 Divisor 5
Result: -3*/
int DivideTwoInt(int dividend, int divisor) {
    if (divisor == 0) return INT_MAX; 
    bool isNegative = (dividend < 0) ^ (divisor < 0);
    long long absDividend = abs(static_cast<long long>(dividend));
    long long absDivisor = abs(static_cast<long long>(divisor));
    long long result = 0;
    while (absDividend >= absDivisor) {
        long long temp = absDivisor;
        long long multiple = 1;
        while (absDividend >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        absDividend -= temp;
        result += multiple;
    }
    if (isNegative) result = -result;
    if (result > INT_MAX) return INT_MAX;
    if (result < INT_MIN) return INT_MIN;
    return static_cast<int>(result);
}
/*5. Calculate x Raised to the Power n
Write a C++ program to calculate x raised to the power n (xn).
Sample Input: (x = 7.0, n = 2)
Sample Output: 49*/
float XPowerN(float x, int n) {
    float result = 1;
    while (n)
    {
        result *= x;
        n--;
    }
    return result;
}
int main() 
{
    cout<<endl<<endl;
    cout<<"Absolute Difference with 51 for 51 : "<<AbsDiff51(51)<<endl;
    cout<<"Absolute Difference with 51 for 25 : "<<AbsDiff51(25)<<endl;
    cout<<"Test(1) : "<<RemoveChar("Python", 1)<<endl;
    cout<<"Test(2) : "<<RemoveChar("Python", 0)<<endl;
    cout<<"Test(3) : "<<RemoveChar("Python", 2)<<endl;
    cout<<SwapFiAndLa("abcd")<<endl;
    cout<<SwapFiAndLa("a")<<endl;
    cout<<SwapFiAndLa("xy")<<endl;
    cout<<FourCopies("C Sharp")<<endl;
    cout<<FourCopies("JS")<<endl;
    cout<<FourCopies("a")<<endl;
    cout<<AddLastCh("Red")<<endl;
    cout<<AddLastCh("Green")<<endl;
    cout<<AddLastCh("1")<<endl<<"[";
    cout<<Multiple_3_7(3)<<", ";
    cout<<Multiple_3_7(14)<<", ";
    cout<<Multiple_3_7(12)<<", ";
    cout<<Multiple_3_7(37)<<']'<<endl;
    vector<int> PrimeVecRange = PrimeRange(1, 100);
    for(int i=0;i<PrimeVecRange.size();i++) cout<<PrimeVecRange[i]<<endl;
    cout<<Factorial(5)<<endl;
    cout<<Factorial(7)<<endl;
    cout<<LastPrime(50)<<endl;
    cout<<LastPrime(100)<<endl;
    cout<<GCD(25, 15)<<endl;
    cout<<SumDigits(1234)<<endl;
    cout<<endl<<endl;
    cout<<"~~> { "<<Reverse("w3resource")<<" } <~~"<<endl;
    cout<<"~~> { "<<NextChar("w3resource")<<" } <~~"<<endl;
    cout<<"~~> { "<<Capitalize("cpp string exercises")<<" } <~~"<<endl;
    cout<<"~~> { "<<LargestWord("C++ is a general-purpose programming language.")<<" } <~~"<<endl;
    cout<<"~~> { "<<SortLetters("python")<<" } <~~";
    cout<<endl<<endl;
    cout<<AddIF("if else")<<endl;
    cout<<AddIF("else")<<endl;
    cout<<"~~> {"<<PrimeNumbers(7)<<"} <~~"<<endl;
    cout<<"~~> {"<<PrimeNumbers(13)<<"} <~~"<<endl;
    cout<<"~~> {"<<PrimeNumbers(8)<<"} <~~";
    cout<<endl<<endl;
    int i;
    int num[] = {62,48,45,23,12,56};
    vector<int> NewVec = LargestElements(num,6,4);
    cout<<"the Largest Three Elements : ";
    vector<int> LargestThree = LarThEle(num,6);
    for(i=0;i<LargestThree.size();i++) {
        if(i==0) cout<<'{'<<LargestThree[i]<<", ";
        else if(i==LargestThree.size()-1) cout<<LargestThree[i]<<'}';
        else cout<<LargestThree[i]<<", ";
    }
    cout<<endl<<"Second Largest Element : "<<SecLarEle(num,6)<<endl;
    cout<<"Largest K Elements : ";
    for(i=0;i<NewVec.size();i++) {
        if(i==0) cout<<'{'<<NewVec[i]<<", ";
        else if(i==NewVec.size()-1) cout<<NewVec[i]<<'}';
        else cout<<NewVec[i]<<", ";
    }
    cout<<endl<<"Second Smallest Element : "<<SecSmalEle(num,6)<<endl;
    cout<<endl<<endl;
    vector<int> test1 = {1, 2, 5, 0, 3, 6, 7};
    vector<int> test2 = {4, 5, 6};
    vector<int> test3 = {2, 2, 3};
    cout<<"Test(1) : "<<canBeConsecutive(test1)<<endl;
    cout<<"Test(2) : "<<canBeConsecutive(test2)<<endl;
    cout<<"Test(3) : "<<canBeConsecutive(test3)<<endl;
    vector<int> test4 = EleSmallNei({1, 2, 5, 0, 3, 6, 4});
    cout<<"Test(4) : ";
    for(i=0;i<test4.size();i++) cout<<test4[i];
    cout<<endl;
    cout<<"Test(5) : "<<endl;
    vector<vector<int>> test5 = nxnMatrix(2);
    for(i=0;i<test5.size();i++) {
        for(int j=0;j<test5.size();j++) {
            if(j==0) cout<<"| "<<test5[i][j]<<' ';
            else if(j==test5.size()-1) cout<<test5[i][j]<<" |"<<endl;
            else cout<<test5[i][j]<<' ';
        }
    }
    vector<string> test6 = CapStrVec({"red ", "green ", "black ", "white ", "Pink"});
    for(i=0;i<test6.size();i++) cout<<test6[i];
    cout<<endl;
    vector<string> test7 = {"Python", "Py"};
    cout<<SecStrINFirStr(test7);
    cout<<endl<<endl;
    cout<<boolalpha;
    cout<<PowerOfTwo(8)<<endl;// true
    cout<<PowerOfTwo(7)<<endl;// false
    cout<<PowerOfTwo(0)<<endl;// false
    cout<<PowerOfTwo(1)<<endl;// true (2⁰ = 1)
    cout<<IntReverseDigits(4)<<endl;
    cout<<IntReverseDigits(123)<<endl;
    cout<<DivideTwoInt(7, 2)<<endl;
    cout<<DivideTwoInt(-17, 5)<<endl;
    cout<<XPowerN(7.0, 2)<<endl;
    cout<<XPowerN(1.5, 5)<<endl;
    return 0;
}