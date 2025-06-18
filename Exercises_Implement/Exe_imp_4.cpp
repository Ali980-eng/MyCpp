#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
/*
  ------------------------------------------------------------
  C++ Function Implementation Series - Week 4
  ------------------------------------------------------------
  Date: May 13, 2025

  Topics Covered:
    - Basic Algorithms
    - For-Loops
    - String Operations
    - Recursion
    - Mathematical Functions

  Description:
    This file contains independent implementations of various
    functions designed to reinforce core C++ programming concepts.
    Each function is presented with the following:
      - A clear problem description (included as a comment)
      - A complete implementation
      - Inline documentation for clarity

  Notes:
    This series focuses on presenting correct and clean solutions.
    Any encountered issues, bugs, or alternative approaches
    will be documented in a separate file or illustrative example
    if properly tracked during development.

  Author: Ali Mohammed Ali Lafi
  ------------------------------------------------------------
*/

// Basic Algorithm
/*36. Check for Triple in Array
Write a C++ program to check if a triple is present in an array of integers or not.
If a value appears three times in a row in an array it is called a triple.
Sample Input:{{ 1, 1, 2, 2, 1 }, { 1, 1, 2, 1, 2, 3 }, { 1, 1, 1, 2, 2, 2, 1 }}
Sample Output:[0, 0, 1]*/
bool CheckForTriple(vector<int> vrr) {
    short count = 0;
    sort(vrr.begin(), vrr.end(), greater<int>());
    int NumHold = vrr[0];
    for(int i=0;i<vrr.size();i++) {
        if(vrr[i] == NumHold) count++;
        else {
            NumHold == vrr[i];
            count = 1;
        }
        if(count==3) return true;
    }
    return false;
}
/*37. Sum of Integers, Return 30 in Range 10?20
Write a C++ program to compute the sum of the two given integers.
If the sum is in the range 10..20 inclusive return 30.
Sample Input:[(12, 17), (2, 17), (22, 17), (20, 0)]
Sample Output:[29, 30, 39, 30]*/
bool RangeCheck(int sum, int RangeStart, int RangeEnd) {
    if((sum>=RangeStart && sum<=RangeEnd)) return true;
    return false;
}
int SumIn30Range(int num1, int num2) {
    int sum = num1 + num2;
    if(RangeCheck(sum, 10, 20)) return 30;
    return sum;
}
/*38. Check if 5, Sum 5, or Difference 5
Write a C++ program that accepts two integers and returns true if either one is 5 or their sum or difference is 5.
Sample Input:[(5, 4), (4, 3), (1, 4)]
Sample Output:[1, 0, 1]*/
bool Check5fac(int num1, int num2) {
    if(num1==5||num2==5) return true;
    else if(num1+num2 == 5) return true;
    else if(abs(num1-num2)==5) return true;
    return false;
}
/*39. Multiple of 13 or One More
Write a C++ program to test if a given non-negative number is a multiple of 13 or it is one more than a multiple of 13.
Sample Input:[13, 14, 27, 41]
Sample Output:[1, 1, 1, 0]*/
bool MultOf13(int num) {
    if(num%13==0||num%13==1) return true;
    return false;
}
/*40. Multiple of 3 or 7 but Not Both
Write a C++ program to check if a given number that is not negative is a multiple of 3 or 7, but not both.
Sample Input:[3, 7, 21]
Sample Output:[1, 1, 0]*/
bool Mult3Or7(int num) {
    if((num%3==0&&num%7!=0)||(num%3!=0&&num%7==0)) return true;
    return false;
}
/*41. Within 2 of Multiple of 10
Write a C++ program to check if a given number is within 2 of a multiple of 10.
Sample Input:[3, 7, 8, 21]
Sample Output:[0, 0, 1, 1]*/
bool Multiple10(int num) {
    if(num<10) {
        if(num+2==10||num+1==10) return true;
        else return false;
    }
    else if(num>10) {
        if(num%10==0||num%10==1||num%10==2) return true;
        else return false;
    }
    else return true;
    return false;
}
/*42. Return 18 if Integer in Range 10?20
Write a C++ program to compute the sum of the two given integers.
Return 18 if one of the given integer values is in the range 10..20 inclusive.
Sample Input:[(3, 7), (10, 11), (10, 20), (21, 220)]
Sample Output:[10, 18, 18, 241]*/
int Ret18Ran(int num1, int num2) {
    if((num1>=10&&num1<=20)||(num2>=10&&num2<=20)) return 18;
    return num1+num2;
}
/*43. Check String Starts with 'F' or Ends with 'B'
Write a C++ program to check whether a given string begins with "F" or ends with "B".
If the string starts with "F" return "Fizz" and return "Buzz" if it finishes with "B".
If the string starts with "F" and ends with "B" return "FizzBuzz".
In other cases return the original string.
Sample Input:["FB", "Fsafs", "AuzzB", "founder"]
Sample Output:[FizzBuzz, Fizz, Buzz, founder]*/
string CheckFAndB(string str) {
    size_t endStr = str.length()-1;
    if(str[0]=='f'||str[endStr]=='b') return str;
    else if(str[0]=='F'&&str[endStr]=='B') return "FizzBuzz";
    else if(str[0]=='F') return "Fizz";
    else if(str[endStr]=='B') return "Buzz";
    return "***";
}
/*44. Add Two Integers to Get Third
Write a C++ program to check if it is possible to add two integers to get the third integer from three given integers.
Sample Input:[(1, 2, 3), (4, 5, 6), (-1, 1, 0)]
Sample Output:[1, 0, 1]*/
bool AddTwoToThird(int num1, int num2, int num3) {
    if((num1+num2==num3)||(num2+num3==num1)||(num1+num3==num2)) return true;
    return false;
    
}
/*45. Check y > x and z > y
Write a C++ program to check if y is greater than x, and z is greater than y from three given integers x,y,z.
Sample Input:[(1, 2, 3), (4, 5, 6), (-1, 1, 0)]
Sample Output:[1, 1, 0]*/
bool CheckXYZ(int x, int y, int z) {
    if(y>x&&z > y) return true;
    return false;
}
// For-Loops
/*31. Sum of an A.P. Series
Write a C++ program to find the sum of an A.P. series.
Sample Output:
Input the starting number of the A.P. series: 1
Input the number of items for the A.P. series: 8
Input the common difference of A.P. series: 5
The Sum of the A.P. series are : 1 + 6 + 11 + 16 + 21 + 26 + 31 + 36 = 148*/
// best case for the series sum
int A_P_SerSum(int start, int ComDiff, int NumItem) {
    return (ComDiff*(NumItem - 1)+2*start)*(NumItem/2);
}
int VecSum(vector<int> vrr) {
    int sum = 0;
    for(int i=0;i<vrr.size();i++) sum += vrr[i];
    return sum;
}
vector<int> AP_Ser(int start, int ComDiff, int NumItem) {
    vector<int> APSer;
    for(int i=1;i<=NumItem;i++) APSer.push_back(start+ComDiff*(i-1));
    return APSer;
}
int AP_SerSum(int start, int ComDiff, int NumItem) {
    return VecSum(AP_Ser(start, ComDiff, NumItem));
}
/*32. Sum of a G.P. Series
Write a C++ program to find the sum of the GP series.
Sample Output:
Input the starting number of the G.P. series: 3
Input the number of items for the G.P. series: 5
Input the common ratio of G.P. series: 2
The numbers for the G.P. series:
3 6 12 24 48
The Sum of the G.P. series: 93*/
vector<int> GP_Series(int start, int NumItem, int CommRat) {
    int PushNum = start;
    vector<int> GPSer;
    for(int i = 0;i<NumItem;i++) {
        GPSer.push_back(PushNum);
        PushNum *= 2;
    }
    return GPSer;
}
int GP_SerSum(int start, int NumItem, int CommRat) {
    return VecSum(GP_Series(start, NumItem, CommRat));
}
/*33. Express a Number as the Sum of Two Primes
Write a program in C++ to check whether a number can be expressed as the sum of two.
Sample Output:
Input a positive integer: 20
20 = 3 + 17
20 = 7 + 13*/
bool PrimeNumbers(int num) {
    for(int i=2;i<num;i++) 
    if(num%i==0) return false;
    return true;
}
vector<string> ExpNumSum(int num) {
    int num1 = num, num2 = 0;
    vector<string> result;
    while(num) {
        if(PrimeNumbers(num1)&&PrimeNumbers(num2)) {
            result.push_back(to_string(num1)+" + "+to_string(num2));
            num1--;
            num2++;
        }
        else {
            num1--;
            num2++;
        }
        num--;
    }
    return result;
}
/*34. Find the Length of a String Without Using Library Functions
Write a program in C++ to find the length of a string without using the library function.
Sample Output:
Input a string: w3resource.com
The string contains 14 number of characters.
So, the length of the string w3resource.com is:14*/
size_t LenStr(string str) {
    size_t Len = 0;
    for(char ch : str) Len++;
    return Len;
}
/*35. Display a triangle Pattern with '*' Character
Write a program in C++ to display a pattern like a right angle triangle using an asterisk.
Sample Output:
Input number of rows: 5
*
**
***
****
***** */
void DisTriPat(int rows) {
    for(int i=1;i<=rows;i++) {
        for(int j=1;j<=i;j++) 
        cout<<'*';
        cout<<endl;
    }
}
/*36. Display Right-Angle Triangle Pattern with Numbers
Write a program in C++ to display the pattern like right angle triangle with number.
Sample Output:
Input number of rows: 5
1
12
123
1234
12345*/
void DisTriNum_1(int rows) {
    for(int i=1;i<=rows;i++) {
        for(int j=1;j<=i;j++) 
        cout<<j;
        cout<<endl;
    }
}
/*37. Right-Angle Triangle Pattern with Repeated Numbers
Write a C++ program that makes a pattern such as a right angle triangle using numbers that repeat.
Sample Output:
Input number of rows: 5                                                                                      
1                                                                                                             
22                                                                                                      
333                                                                                                         
4444                                                                                                         
55555 */
void DisTriNum_2(int rows) {
    for(int i=1;i<=rows;i++) {
        for(int j=1;j<=i;j++) 
        cout<<i;
        cout<<endl;
    }
}
/*38. Right-Angle Triangle Pattern with Increasing Numbers
Write a C++ program to make such a pattern like a right angle triangle with the number increased by 1.
Sample Output:
Input number of rows: 4                                                                                     
1                                                                                  
2 3                                                                                                         
4 5 6                                                                                                       
7 8 9 10 */
void DisTriNum_3(int rows) {
    int ShowNum = 1;
    for(int i=1;i<=rows;i++) {
        for(int j=1;j<=i;j++) {
            cout<<ShowNum<<' ';
            ShowNum++;
        }
        cout<<endl;
    }
}
/*39. Pyramid Pattern with Increasing Numbers
Write a C++ program to make such a pattern like a pyramid with numbers increased by 1.
Sample Output:
Input number of rows: 4                                               
   1
  2 3
 4 5 6
7 8 9 10 */
void PyrPatNum(int rows) {
    int space = rows - 1, ShowNum = 1;
    for(int i=1;i<=rows;i++) {
        while(space) {
            cout<<' ';
            space--;
        }
        space = rows - (i + 1);
        for(int j=1;j<=i;j++) {
            cout<<ShowNum<<' ';
            ShowNum++;
        }
        cout<<endl;
    }
}
/*40. Pyramid Pattern with Asterisks
Write a C++ program to make such a pattern like a pyramid with an asterisk.
Sample Output:
Input number of rows: 5                                               
    *                                                              
   * *                                                             
  * * *                                                            
 * * * *                                                           
* * * * * */
void PyrPatAst(int rows) {
    int space = rows - 1;
    for(int i=1;i<=rows;i++) {
        while(space) {
            cout<<' ';
            space--;
        }
        space = rows - (i + 1);
        for(int j=1;j<=i;j++) cout<<'*'<<' ';
        cout<<endl;
    }
}
// string
/*16. Longest Common Prefix from an Array of Strings
Write a C++ program to find the longest common prefix from a given array of strings.
Example:
The longest common prefix is: Pa
The longest common prefix is: J
The longest common prefix is: */
string LonCommPre(vector<string> VecStr) {
    string TestStr, HoldStr, result;
    for(int i=1;i<VecStr.size();i++) {
        if(i==1) {
            TestStr = VecStr[i-1];
            HoldStr = VecStr[i];
        }
        else {
            TestStr = result;
            HoldStr = VecStr[i];
            result.clear();
        }
        for(int j=0;j<HoldStr.length();j++) {
            if (j >= TestStr.length()) break;
            if(HoldStr[j]==TestStr[j]) result += HoldStr[j];
            else break;
        }
    }
    return result;
}
/*17. Well-Formed Brackets Combinations
Write a C++ program to find all combinations of well-formed brackets from a given pair of parentheses.
Example:
n = 2
[[]] [][]
n = 3
[[]] [][] [[[]]] [[][]] [[]][] [][[]] [][][]*/
bool WellForBra(string str) {
    bool OpBraSw = false, CloBraSw = false;
    short OpenBra = 0, CloseBra = 0;
    for(char bracket : str) {
        if(bracket == '['&&OpBraSw) OpenBra++;
        else if(bracket == ']'&&CloBraSw) CloseBra++;
        else if(bracket == ']'&&!OpBraSw) return false;
        else if(bracket == '[') {
            OpenBra++;
            OpBraSw = true;
        }
        else if(bracket == ']') {
            CloseBra++;
            CloBraSw = true;
        }
    }
    return (OpenBra==CloseBra);
}
/*18. Length of the Longest Valid Parentheses Substring
Write a C++ program to find the length of the longest valid (correct-formed) parentheses substring of a given string.
Example:
Original Parentheses string: [[]
Length of longest parentheses: 2
Original Parentheses string: [[]]]
Length of longest parentheses: 4
Original Parentheses string: ]]]][[[[
Length of longest parentheses: 0 */
int LenLonVal(string str) {
    int open = 0;
    int count = 0;
    int maxLen = 0;
    int current = 0;
    for(char ch : str) {
        if(ch == '[') open++;
        else if(ch == ']' && open > 0) {
            open--;
            current += 2;
            if(current > maxLen) maxLen = current;
        }
        else {
            current = 0;
            open = 0;
        }
    }
    return maxLen;
}
/*19. Reverse Only the Vowels in a String
Write a C++ program to reverse only the vowels of a given string.
A vowel is a syllabic speech sound pronounced without any stricture in the vocal tract.
Vowels are one of the two principal classes of speech sounds, the other being the consonant.
Example:
Original string: w3resource
After reversing the vowels of the said string: w3resuorce
Original string: Python
After reversing the vowels of the said string: Python
Original string: Hello
After reversing the vowels of the said string: Holle
Original string: USA
After reversing the vowels of the said string: ASU*/
string ReveVow(string str) {
    size_t index;
    vector<char> Vow;
    string substr, result;
    for(char ch : str) {
        if(ch == 'a'||ch == 'i'||ch == 'e'||ch == 'o'||ch == 'u') {
            Vow.push_back(ch);
            substr += '*';
        }
        else if(ch == 'A'||ch == 'I'||ch == 'E'||ch == 'O'||ch == 'U') {
            Vow.push_back(ch);
            substr += '*';
        }
        else substr += ch;
    }
    index = Vow.size()-1;
    for(int i=0;i<substr.length();i++) {
        if(substr[i] == '*') {
            result += Vow[index];
            index--;
        }
        else result += substr[i];
    }
    return result;
}
/*20. Length of the Longest Palindrome in a String
Write a C++ program to find the length of the longest palindrome in a given string (uppercase or lowercase letters).
Original string: adcdcdy
Length of the longest palindrome of the said string: 5
Original string: aaa
Length of the longest palindrome of the said string: 3
Original string: aa
Length of the longest palindrome of the said string: 2
Original string: abddddeeff
Length of the longest palindrome of the said string: 4
Original string: PYTHON
Length of the longest palindrome of the said string: 1*/
int LenLonPal(string str) {
    int maxLen = 1;
    int n = str.length();
    for(int i = 0; i < n; i++) {
        int l = i, r = i;
        while(l >= 0 && r < n && str[l] == str[r]) {
            int len = r - l + 1;
            if(len > maxLen) maxLen = len;
            l--;
            r++;
        }
        l = i, r = i + 1;
        while(l >= 0 && r < n && str[l] == str[r]) {
            int len = r - l + 1;
            if(len > maxLen) maxLen = len;
            l--;
            r++;
        }
    }
    return maxLen;
/*Step-by-step Explanation of the Algorithm:
1-We loop through each character in the string, treating each one as a potential center of a palindrome.
2-For every character, we check two possible cases:
~Odd-length palindrome: The center is a single character.
~We expand to the left and right as long as the characters on both sides match.
~Even-length palindrome: The center is between two adjacent characters.
~We also expand outward as long as the characters on both sides are equal.
3-During each expansion, if we find a palindrome longer than any previous one, we update the maximum length.
4-After going through the entire string, we return the length of the longest palindromic substring found.
*/
}
// Recursion
/*1. Sum of Array Using Recursion
Write a C++ program to find the sum of all elements in an array using recursion.*/
int RecSum(int num[], size_t ASize) {
    int sum = 0, index = ASize-1;
    sum = num[index];
    if(index>=0) {
        return sum+RecSum(num, index);
        index--;
    }
    return sum;
}
/*2. Factorial Using Recursion
Write a C++ program to calculate the factorial of a given number using recursion.*/
long int RecFac(int num) {
    if(num==1) return num;
    return num*RecFac(num-1);
}
/*3. Recursive nth Fibonacci Number
Write a C++ program to implement a recursive function to get the nth Fibonacci number.*/
vector<int> Fibonacci = {0, 1};
vector<int> FibReset() {
    return {0, 1};
}
vector<int> RecFibNum(int terms, int index = 1) {
    if(terms<=index) {
        vector<int> send = Fibonacci;
        Fibonacci = FibReset();
        return send;
    }
    Fibonacci.push_back(Fibonacci[index] + Fibonacci[index-1]);
    index++;
    return RecFibNum(terms, index);
}
/*4. Sum of Digits Using Recursion
Write a C++ program to implement a recursive function to calculate the sum of digits of a given number.*/
int SumDigiRec(int num) {
    int sum = 0;
    if(!num) return sum;
    sum += num%10;
    num /= 10;
    return sum+SumDigiRec(num);
}
/*5. Recursive Maximum and Minimum in an Array
Write a C++ program to implement a recursive function to find the maximum and minimum elements in an array*/
int RecMaxArr(int num[], size_t ASize, size_t index = 1, int currentMax = INT_MIN) {
    if (index == 1) currentMax = num[0];
    if (index >= ASize) return currentMax;
    if (num[index] > currentMax) currentMax = num[index];
    return RecMaxArr(num, ASize, index + 1, currentMax);
}
// Math
/*6. Get Fraction Part from Two Integers
Write a C++ program to get the fraction part from two given integers representing the numerator and denominator in string format.
Sample Input: x = 3, n = 2
Sample Output: 1.5*/
string FracPart(int numerator, int denominator) {
    return to_string(float(numerator)/float(denominator));
}
int RecMinArr(int num[], size_t ASize, size_t index = 1, int currentMin = INT_MAX) {
    if (index == 1) currentMin = num[0];
    if (index >= ASize) return currentMin;
    if (num[index] < currentMin) currentMin = num[index];
    return RecMinArr(num, ASize, index + 1, currentMin);
}
/*7. Excel Column Title from Number
Write a C++ program to get the Excel column title that corresponds to a given column number (integer value).
For example:
1 -> A
2 -> B
3 -> C
...
26 -> Z
27 -> AA
28 -> AB
...*/
string ExcelColumn(int num) {
    string result;
    while (num > 0) {
        num--;
        int remainder = num % 26;
        result = char('A' + remainder) + result;
        num /= 26;
    }
    return result;
}
/*8. Excel Column Number from Title
Write a C++ program to get the column number (integer value) that corresponds to a column title as it appears on an Excel sheet.
For example:
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28*/
int ExcelColNum(string str) {
    reverse(str.begin(), str.end());
    short count = 0;
    int ExcelNum = 0;
    for(char ch : str) {
        ExcelNum += ((ch-'A')+1)*pow(26,count);
        count++;
    }
    return ExcelNum;
}
/*9. Count Trailing Zeroes in Factorial
Write a C++ program to find the number of trailing zeroes in a given factorial.
Sample Input: n = 4
Sample Output: 0
Sample Input: n = 6
Sample Output: 1*/
short countTraiZero(int num) {
    short count = 0;
    string str = to_string(RecFac(num));
    reverse(str.begin(), str.end());
    for(char ch : str) {
        if(ch=='0') count++;
        else break;
    }
    return count;
}
/*10. Count Total Occurrences of Digit 1 Up to n
Write a C++ program to count the total number of digits 1 appearing in all positive integers less than or equal to a given integer n.
Example:
Sample Input: n = 12,
Sample Output: 5
Return 5, because digit 1 occurred 5 times in the following numbers: 1, 10, 11, 12.*/
int count1InStr(string str) {
    int count = 0;
    for(char ch : str) {
        if(ch=='1') count++;
        continue;
    }
    return count;
}
vector<int> CountOccDigi(int n) {
    if(n<=0) return {-1};
    if(n<=9&&n>=1) return {1};
    int count = n;
    vector<int> result;
    for(int i=0;i<=n;i++) {
        if(i==1) {
            result.push_back(i);
            count--;
        }
        for(int j=0;j<=n;j++) {
            if(i==1&&j==1) {
                if((i*10)+j<=n) {
                    result.push_back((i*10)+j);
                    count -= 2;
                }
            }
            else if(i==1&&j!=1) {
                if((i*10)+j<=n) {
                    result.push_back((i*10)+j);
                   count--; 
                }
            }
            else continue;
        }
    }
    return result;
}
int CountOccDi(int n) {
    if(n<=0) return -1;
    if(n<=9&&n>=1) return 1;
    int count = 0;
    for(int i=0;i<=n;i++) 
    count += count1InStr(to_string(i));
    return count;
}
int CountTotOcc(vector<int> nums) {
    int count = 0;
    vector<string> numbers;
    for(int num : nums) {
        if(num>=0)
        numbers.push_back(to_string(num));
    }
    for(string str : numbers) count += count1InStr(str);
    return count;
}
int main() {
    cout<<endl<<endl;
    int i = 0;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t"<<"Basic Algorithm"<<endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    vector<vector<int>> Test1 = {
        { 1, 1, 2, 2, 1 }, 
        { 1, 1, 2, 1, 2, 3 }, 
        { 1, 1, 1, 2, 2, 2, 1 }
    };
    cout<<"Test(1) : ";
    for(i=0;i<Test1.size();i++) {
        if(i==0) cout<<" ["<<CheckForTriple(Test1[i])<<", ";
        else if(i==Test1.size()-1) cout<<CheckForTriple(Test1[i])<<"] "<<endl;
        else cout<<CheckForTriple(Test1[i])<<", ";
    }
    cout<<"Test(2) : ";
    cout<<" ["<<SumIn30Range(12, 17)<<", ";
    cout<<SumIn30Range(2, 17)<<", ";
    cout<<SumIn30Range(22, 17)<<", ";
    cout<<SumIn30Range(20, 0)<<"] "<<endl;
    cout<<"Test(3) : ";
    cout<<" ["<<Check5fac(5, 4)<<", ";
    cout<<Check5fac(4, 3)<<", ";;
    cout<<Check5fac(1, 4)<<"] "<<endl;
    vector<int> Test4 = {13, 14, 27, 41};
    cout<<"Test(4) : ";
    for(i=0;i<Test4.size();i++) {
        if(i==0) cout<<" ["<<MultOf13(Test4[i])<<", ";
        else if(i==Test4.size()-1) cout<<MultOf13(Test4[i])<<"] "<<endl;
        else cout<<MultOf13(Test4[i])<<", ";
    }
    vector<int> Test5 = {3, 7, 21};
    cout<<"Test(5) : ";
    for(i=0;i<Test5.size();i++) {
        if(i==0) cout<<" ["<<Mult3Or7(Test5[i])<<", ";
        else if(i==Test5.size()-1) cout<<Mult3Or7(Test5[i])<<"] "<<endl;
        else cout<<Mult3Or7(Test5[i])<<", ";
    }
    vector<int> Test6 = {3, 7, 8, 21};
    cout<<"Test(6) : ";
    for(i=0;i<Test6.size();i++) {
        if(i==0) cout<<" ["<<Multiple10(Test6[i])<<", ";
        else if(i==Test6.size()-1) cout<<Multiple10(Test6[i])<<"] "<<endl;
        else cout<<Multiple10(Test6[i])<<", ";
    }
    cout<<"Test(7) : ";
    cout<<" ["<<Ret18Ran(3, 7)<<", ";
    cout<<Ret18Ran(10, 11)<<", ";
    cout<<Ret18Ran(10, 20)<<", ";
    cout<<Ret18Ran(21, 220)<<"] "<<endl;
    vector<string> Test8 = {"FB", "Fsafs", "AuzzB", "founder"};
    cout<<"Test(8) : ";
    for(i=0;i<Test8.size();i++) {
        if(i==0) cout<<" ["<<CheckFAndB(Test8[i])<<", ";
        else if(i==Test8.size()-1) cout<<CheckFAndB(Test8[i])<<"] "<<endl;
        else cout<<CheckFAndB(Test8[i])<<", ";
    }
    cout<<"Test(9) : ";
    cout<<" ["<<AddTwoToThird(1, 2, 3)<<", ";
    cout<<AddTwoToThird(4, 5, 6)<<", ";
    cout<<AddTwoToThird(-1, 1, 0)<<"] "<<endl;
    cout<<"Test(10) : ";
    cout<<" ["<<CheckXYZ(1, 2, 3)<<", ";
    cout<<CheckXYZ(4, 5, 6)<<", ";
    cout<<CheckXYZ(-1, 1, 0)<<"] "<<endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t"<<"For-loops"<<endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"Test(1) : "<<A_P_SerSum(1, 5, 8)<<endl;
    cout<<"Test(2) : "<<AP_SerSum(1, 5, 8)<<endl;
    cout<<"Test(3) : "<<GP_SerSum(3, 5, 2)<<endl;
    vector<string> Test4_F = ExpNumSum(20);
    cout<<"Test(4) : ";
    for(i=0;i<Test4_F.size();i++) {
        if(i==0) cout<<" ["<<Test4_F[i]<<", ";
        else if(i==Test4_F.size()-1) cout<<Test4_F[i]<<"] "<<endl;
        else cout<<Test4_F[i]<<", ";
    }
    cout<<"Test(5) : "<<LenStr("w3resource.com")<<endl;
    cout<<"Test(6) : "<<endl;
    DisTriPat(5);
    cout<<"Test(7) : "<<endl;
    DisTriNum_1(5);
    cout<<"Test(8) : "<<endl;
    DisTriNum_2(5);
    cout<<"Test(9) : "<<endl;
    DisTriNum_3(4);
    cout<<"Test(10) : "<<endl;
    PyrPatNum(4);
    cout<<"Test(11) : "<<endl;
    PyrPatAst(5);
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t"<<"String"<<endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"Test(1) : "<<LonCommPre({"dog", "racecar", "car"})<<endl;
    cout<<"Test(2) : "<<LonCommPre({"flower", "flow", "flight"})<<endl;
    cout<<"Test(3) : "<<WellForBra("[[]] [][]")<<endl;
    cout<<"Test(4) : "<<WellForBra("[[]] [][] [[[]]] [[][]] [[]][] [][[]] [][][]")<<endl;
    cout<<"Test(5) : "<<LenLonVal("[[]")<<endl;
    cout<<"Test(6) : "<<LenLonVal("[[]]]")<<endl;
    cout<<"Test(7) : "<<LenLonVal("]]]][[[[")<<endl;
    cout<<"Test(8) : "<<ReveVow("w3resource")<<endl;
    cout<<"Test(9) : "<<ReveVow("Python")<<endl;
    cout<<"Test(10) : "<<ReveVow("Hello")<<endl;
    cout<<"Test(11) : "<<ReveVow("USA")<<endl;
    cout<<"Test(13) : "<<LenLonPal("adcdcdy")<<endl;
    cout<<"Test(14) : "<<LenLonPal("aaa")<<endl;
    cout<<"Test(15) : "<<LenLonPal("aa")<<endl;
    cout<<"Test(16) : "<<LenLonPal("abddddeeff")<<endl;
    cout<<"Test(17) : "<<LenLonPal("PYTHON")<<endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t"<<"Recursion"<<endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    int numbers[] = {31, 29, 10, 25, 5};
    int Numbers[] = {31, 50, 60, 25, 33};
    cout<<"Test(1) : "<<RecSum(numbers, 5)<<endl;
    cout<<"Test(2) : "<<RecFac(numbers[4])<<endl;
    cout<<"Test(3) : "<<RecFac(7)<<endl;
    vector<int> Test4_R = RecFibNum(10);
    cout<<"Test(4) : ";
    for(i=0;i<Test4_R.size();i++) {
        if(i==0) cout<<" ["<<Test4_R[i]<<", ";
        else if(i==Test4_R.size()-1) cout<<Test4_R[i]<<"] "<<endl;
        else cout<<Test4_R[i]<<", ";
    }
    cout<<"Test(5) : "<<SumDigiRec(123)<<endl;
    cout<<"Test(6) : "<<SumDigiRec(666)<<endl;
    cout<<"Test(7) : "<<RecMaxArr(numbers, 5)<<endl;
    cout<<"Test(8) : "<<RecMaxArr(Numbers, 5)<<endl;
    cout<<"Test(9) : "<<RecMinArr(numbers, 5)<<endl;
    cout<<"Test(10) : "<<RecMinArr(Numbers, 5)<<endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t"<<"Math"<<endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"Test(1) : "<<FracPart(3, 2)<<endl;
    cout<<"Test(2) : "<<FracPart(5, 4)<<endl;
    cout<<"Test(3) : "<<FracPart(7, 3)<<endl;
    cout<<"Test(4) : "<<ExcelColumn(1)<<endl;
    cout<<"Test(5) : "<<ExcelColumn(26)<<endl;
    cout<<"Test(6) : "<<ExcelColumn(27)<<endl;
    cout<<"Test(7) : "<<ExcelColumn(52)<<endl;
    cout<<"Test(8) : "<<ExcelColumn(702)<<endl;
    cout<<"Test(9) : "<<ExcelColumn(703)<<endl;
    cout<<"Test(10) : "<<ExcelColNum("AA")<<endl;
    cout<<"Test(11) : "<<ExcelColNum("AB")<<endl;
    cout<<"Test(12) : "<<countTraiZero(4)<<endl;
    cout<<"Test(13) : "<<countTraiZero(6)<<endl;
    cout<<"Test(14) : "<<countTraiZero(7)<<endl;
    cout<<"Test(15) : "<<countTraiZero(10)<<endl;
    cout<<"Test(16) : "<<CountTotOcc({31, 29, 10, 25, 5})<<endl;
    cout<<"Test(17) : "<<CountTotOcc({31, 50, 60, 25, 33})<<endl;
    vector<int> Test18_N = CountOccDigi(12);
    cout<<"Test(18) : ";
    for(i=0;i<Test18_N.size();i++) {
        if(i==0) cout<<" ["<<Test18_N[i]<<", ";
        else if(i==Test18_N.size()-1) cout<<Test18_N[i]<<"] "<<endl;
        else cout<<Test18_N[i]<<", ";
    }
    cout<<"Test(19) : "<<CountOccDi(12)<<endl;
    cout<<"Test(20) : "<<CountOccDi(20)<<endl;
    return 0;
}