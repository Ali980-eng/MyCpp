#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <array>
#include <cmath>
#include <functional>
using namespace std;
/*
  Weekly C++ Function Implementation Series – Week 3
  Author: Ali Mohammed Ali Lafi
  Date: April 29 – May 6, 2025

  Topics Covered:
  - Basic Algorithmic Problems
  - For-Loops and Iterative Solutions
  - String Manipulation Tasks

  Description:
  This program contains multiple self-contained functions designed to solve
  different beginner-to-intermediate level problems. Each function includes
  comments for explanation and follows a modular structure.

  Note:
  This file showcases the clean/optimized implementations.
  Common challenges and debugging notes will be shared separately.
*/
int factorial(int n) {
    if (n < 0) return -1;
    return static_cast<int>(tgamma(n + 1));
}
// Basic Algorithm
/*21. Larger Value in Range 20?30
Write a C++ program to find the larger value from two positive integer values that is in the range 20..30 inclusive.
Also, return 0 if neither is in that range.
Sample Input:[(78, 95), (20, 30), (21, 25), (28, 28)]
Sample Output:[0, 30, 25, 28]*/
int LarValInRange(int num1, int num2) {
    if((num1>=20&&num1<=30)&&(num2>=20&&num2<=30)) {
        if(num1>num2) return num1;
        else if(num2>num1) return num2;
        else return num1;
    }
    else if(num1>=20&&num1<=30) {
        return num1;
    }
    else if(num2>=20&&num2<=30) {
        return num2;
    }
    else return 0;
}
/*22. Check 2?4 'z' Characters
Write a C++ program to check if a given string contains between 2 and 4 'z' characters.
Sample Input:["frizz", "zane", "Zazz", "false"]
Sample Output:[1, 0, 1, 0]*/
bool CheckZChar(string str) {
    short count = 0;
    for(char ch : str) {
        if(ch=='z'||ch=='Z') count++;
        else continue;
    }
    if(count>=2&&count<=4) return true;
    return false;
}
/*23. Same Last Digit for Integers
Write a C++ program to check if two given non-negative integers have the same last digit.
Sample Input:[(123, 456), (12, 512), (7, 87), (12, 45)]
Sample Output:[0, 1, 1, 0]*/
bool SameLasDig(int num1, int num2) {
    vector<int> numbers1,numbers2;
    while (num1) {
        numbers1.push_back(num1%10);
        num1 /= 10;
    }
    while (num2) {
        numbers2.push_back(num2%10);
        num2 /= 10;
    }
    return (numbers2[0]==numbers1[0]);
}
/*24. n Copies of String
Write a C++ program to create the string which is n (non-negative integer) copies of a given string.
Sample Input:[("JS", 2), ("JS", 3), ("JS", 1)]
Sample Output:[JSJS, JSJSJS, JS]*/
string StrNCop(string str, int n) {
    if(str.empty()) {
        cerr<<"the string is empty"<<endl;
        return "";
    }
    string result;
    if(n==1) return str;
    else if(n<=0) {
        cerr<<"wrong value for the numbers of copies"<<endl;
        return "";
    }
    else for(int i=1;i<=n;i++) result += str;
    return result;
}
/*25. n Copies of First 3 Characters
Write a C++ program to create another string which is n (non-negative integer) copies of the first 3 characters of a given string.
If the length of the given string is less than 3 then return n copies of the string.
Sample Input:[("Python", 2), ("Python", 3), ("JS", 3)]
Sample Output:[PytPyt, PytPytPyt, JSJSJS]*/
string StrNCopCh(string str, int n) {
    string substr, result;
    if(n<=0) {
        cerr<<"wrong value for n"<<endl;
        return "";
    }
    if(str.empty()) {
        cerr<<"empty string passed to the function"<<endl;
        return "";}
    else if(str.length()<3) return str+str+str;
    else {
        for(int i=0;i<3;i++) substr += str[i];
        for(int j=0;j<n;j++) result += substr;
    }
    return result;
}
/*26. Count "aa" in String
Write a C++ program to count the string "aa" in a given string and assume "aaa" contains two "aa".
Sample Input:["bbaaccaag", "jjkiaaasew", "JSaaakoiaa"]
Sample Output:[2, 2, 3]*/
int CountAA(string str) {
    int count = 0;
    for(int i = 0; i < str.length() - 1; i++) {
        if(str[i] == 'a' && str[i + 1] == 'a') {
            count++;
        }
    }
    return count;
}
/*27. Check 'aa' Immediately After First 'a'
Write a C++ program to check if the first appearance of "a" in a given string is immediately followed by another "a".
Sample Input:["caabb", "babaaba", "aaaaa"]
Sample Output:[1, 0, 1]*/
bool CheckAftFir(string str) {
    for(int i = 0; i < str.length() - 1; i++) {
        if(str[i] == 'a') {
            return str[i + 1] == 'a';
        }
    }
    return false;
}
/*28. String with Every Other Character
Write a C++ program to create another string made of every other character starting with the first from a given string.
Sample Input:["Python", "PHP", "JS"]
Sample Output:[Pto, PP, J]*/
string StrOthChar(string str) {
    if(str.empty()) return "the string is empty";
    string result;
    for(int i=0;i<str.length();i+=2) result += str[i];
    return result;
}
/*29. Create Sequence String
Write a C++ program to create a string like "aababcabcd" from a given string "abcd".
Sample Input:["abcd", "abc", "a"]
Sample Output:[aababcabcd, aababc, a]*/
string CreateSequence(string str) {
    string result;
    for(int i = 1; i <= str.length(); i++) {
        result += str.substr(0, i);
    }
    return result;
}
/*30. Count Substrings of Length 2
Write a C++ program to count the number of times a substring of length 2 appears in a given string as well as its last two characters.
Do not count the end substring.
Sample Input:["abcdsab", "abcdabab", "abcabdabab", "abcabd"]
Sample Output:[1, 2, 3, 0]*/
int countSubStr(string str) {
    short count = 0;
    size_t StrLen = str.length();
    if (StrLen < 2) return 0;
    string sub = str.substr(StrLen - 2, 2);
    for (int i = 0; i < StrLen - 2; i++) {
        if (str.substr(i, 2) == sub)
        count++;
    }
    return count;
}
/*31. Check Sequence 1, 2, 3 in Array
Write a C++ program to check whether the sequence of numbers 1, 2, 3 appears in a given array of integers somewhere.
Sample Input:[{1,1,2,3,1}, {1,1,2,4,1}, {1,1,2,1,2,3}]
Sample Output: [1, 0, 1]*/
bool CheckSeq123(vector<int> arr) {
    for(int i=0;i<arr.size();i++) {
        if(arr[i] == 3 && arr[i-1] == 2 && arr[i-2] == 1)
        return true;
    }
    return false;
}
/*32. Compare Two integers in array for Same Length 2 Substrings
Write a C++ program that takes a list of integer arrays.
For each array, count how many times a pair of the same number appears consecutively (i.e., two adjacent elements with the same value).
Each such pair should be counted only once, even if the same value appears in multiple such pairs.
Return a list of counts, one for each array.
Sample Input:[{ 5, 5, 1, 15, 15 }, { 15, 2, 3, 4, 15 }, { 3, 3, 15, 15, 5, 5}, { 1, 5, 15, 7, 8, 15}]
Sample Output:[1, 0, 1, 0]*/
bool ComIntInarr(vector<int> arr) {
    short bool_count = 2;
    for(int i=1;i<arr.size();i++) {
        if((arr[i] == arr[i-1])&&bool_count)
        bool_count--;
    }
    if(bool_count == 0) return true;
    return false;
}
/*33. Remove Specified Character Except at Ends
Write a C++ program to create a new string from a given string where a specified character is removed except at the beginning and end.
Sample Input:[("xxHxix", "x"), ("abxdddca", "a"), ("xabjbhtrb", "b")]
Sample Output:[xHix, abxdddca, xajhtrb]*/
string RemoveSpeChar(string str, char ch) {
    string result;
    for(int i=0;i<str.length();i++) {
        if(str[i] == ch && (i == 0||i == str.length()-1)) result += str[i];
        else if(str[i] == ch) continue;
        else result += str[i];
    }
    return result;
}
/*34. Characters at Index 0, 1, 4, 5, ...
Write a C++ program to create the string of the characters at indexes 0,1,4,5,8,9 ... from a given string.
Sample Input:["Python", "JavaScript", "HTML"]
Sample Output:[Pyon, JaScpt, HT]*/
string CharIndex(string str) {
    short range = 2;
    string result;
    for(int i=0;i<str.length();i++) {
        if(range) {
            result += str[i];
            range--;
        }
        else {
            range = 2;
            i++;
        }
    }
    return result;
}
/*35. Count Consecutive 5's in Array
Write a C++ program to count the number of 5's next to each other in an array of integers.
Count the situation where the second 5 is actually a 6.
Sample Input: {{ 5, 5, 2 }, { 5, 5, 2, 5, 5 }, { 5, 6, 2, 9}}
Sample Output:[1, 2, 1]*/
int CountCons5(vector<int> vrr) {
    short count = 0;
    bool NumSw = false, NotNum = false;
    for(int num : vrr) {
        if(num!=5&&NumSw) {
            count++;
            NumSw = false;
            NotNum = true;
            continue;
        }
        if(num == 5&&NotNum) {
            count++;
            NotNum = false;
        }
        else if(num == 5) {
            NumSw = true;
            continue;
        }
    }
    return count;
}
// For-Loops
/*21. Sum of n Even Natural Numbers
Write a C++ program that displays the sum of the n terms of even natural numbers.
Sample Output:
Input number of terms: 5
The even numbers are: 2 4 6 8 10
The Sum of even Natural Numbers upto 5 terms: 30 */
int SumNEven(int terms) {
    if(terms<=0) return -1;
    int sum = 0, EvenNum = 2;
    for(int i=0;i<terms;i++) {
        sum += EvenNum;
        EvenNum += 2;
    }
    return sum;
}
/*22. Display n Terms of a Harmonic Series and Their Sum
Write a program in C++ to display the n terms of a harmonic series and their sum.
1 + 1/2 + 1/3 + 1/4 + 1/5 ... 1/n terms.
Sample Output:
Input number of terms: 5 => 1/1 + 1/2 + 1/3 + 1/4 + 1/5
The sum of the series upto 5 terms: 2.2833*/
double SumOfHarSer(int terms) {
    if(terms<=0) return -1;
    double sum = 0.0, DNum = 1.0;
    while(DNum<=terms) {
        sum += (1/DNum);
        DNum++;
    }
    return sum;
}
/*23. Sum of the Series [9 + 99 + 999 + ...]
Write a program in C++ to display the sum of the series [ 9 + 99 + 999 + 9999 ...].
Sample Output:
Input number of terms: 5 => 9+99+999+9999+99999
The sum of the sarise = 111105*/
long int SumOf9Ser(int terms) {
    if(terms<=0) return -1;
    long int sum = 0, Num9 = 9;
    for(int i=1;i<=terms;i++) {
        sum += Num9;
        Num9 += (9*pow(10, i));
    }
    return sum;
}
/*24. Sum of the Series [1 + x + x^2/2! + x^3/3! + ...]
Write a program in C++ to display the sum of the series [ 1+x+x^2/2!+x^3/3!+....].
Sample Output:
Input the value of x: 3
Input number of terms: 5
The sum is : 16.375 */
double SumOfTySer(double value, int terms) {
    if(value == 0) return 1;
    else if(terms<=0) return -1;
    double sum = 1.0+value;
    for(int i=2;i<terms;i++) sum += pow(value, i)/factorial(i);
    return sum;
}
/*26. Sum of the Series [1 + 11 + 111 + ...]
Write a program in C++ to find the sum of the series 1 +11 + 111 + 1111 + .. n terms.
Sample Output:
Input number of terms: 5
1 + 11 + 111 + 1111 + 11111
The sum of the series is: 12345 */
long int SumOf1Ser(int terms) {
    if(terms <= 0) return -1;
    long int sum = 0, Num1 = 1;
    for(int i=1;i<=terms;i++) {
        sum += Num1;
        Num1 += (1*pow(10, i));
    }
    return sum;
}
/*27. Display the First n Terms of the Fibonacci Series
Write a program in C++ to display the first n terms of the Fibonacci series.
Sample Output:
Input number of terms to display: 10
Here is the Fibonacci series upto to 10 terms: 0 1 1 2 3 5 8 13 21 34 */
vector<int> FibonacciSequence(int terms) {
    if (terms <= 0) return {};
    if (terms == 1) return {0};
    if (terms == 2) return {0, 1};
    vector<int> Fibonacci = {0, 1};
    for (int i = 2; i < terms; i++) 
    Fibonacci.push_back(Fibonacci[i-1] + Fibonacci[i-2]);
    return Fibonacci;
}
/*28. Sum of Integers Between 100 and 200 Divisible by 9
Write a program in C++ to find the number and sum of all integers between 100 and 200 which are divisible by 9.
Sample Output:
Numbers between 100 and 200, divisible by 9: 108+117+126+135+144+153+162+171+180+189+198
The sum : 1683 */
int sumBetTwoNum(int begin = 100, int end = 200,int step = 9) {
    if(step <= 0) return -1;
    long int sum = 0;
    for(int i=begin-1;i<end;i+=step) {
        if(i==begin-1) continue;
        else sum += i;
    }
    return sum;
}
/*29. Find the LCM of Two Numbers Using HCF
Write a program in C++ to find the LCM of any two numbers using HCF.
Sample Output:
Input 1st number for LCM: 15
Input 2nd number for LCM: 25
The LCM of 15 and 25 is: 75*/
int HCF(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
    /*Function to compute the Greatest Common Divisor (GCD) of two integers using the Euclidean Algorithm.
        The algorithm works as follows:
        - Given two integers a and b, where a ≥ b, divide a by b and get the remainder r.
        - Replace a with b and b with r.
        - Repeat the process until the remainder is 0.
        - The last non-zero remainder is the GCD of the original two numbers.
        Mathematical Justification:
        - Any common divisor of a and b also divides a % b.
        - Therefore, the set of common divisors remains unchanged as we reduce the problem.
        - This makes the algorithm efficient and guarantees termination.
        Time Complexity: O(log(min(a, b)))
        Example:
        GCD(48, 18)
        → 48 % 18 = 12 → GCD(18, 12)
        → 18 % 12 = 6  → GCD(12, 6)
        → 12 % 6 = 0   → GCD = 6
    */
}
int LCM(int num1, int num2) {
    return abs(num1*num2)/HCF(num1, num2);
}
/*30. Display the Number in Reverse Order
Write a program in C++ to display the numbers in reverse order.
Sample Output:
Input a number: 12345
The number in reverse order is : 54321*/
int ReverseNum(int num) {
    int HoldNum = 0, resultNum = 0;
    while (num) {
        HoldNum = (num%10);
        num/=10;
        resultNum = (resultNum*10)+(HoldNum);
    }
    return resultNum;
}
// String
/*11. Find the Word with the Most Repeated Letters
Write a C++ program to find a word in a given string that has the highest number of repeated letters.
Example:
Sample Input: Print a welcome text in a separate line.
Sample Output: Word which has the highest number of repeated letters. separate*/
vector<string> StrSplit(string str) {
    string substr;
    vector<string> result;
    for(int i=0;i<str.length();i++) {
        if(str[i] == ' '||str[i] == '-'||str[i] == '~'||i==str.length()-1) {
            result.push_back(substr);
            substr = "";
        }
        else substr += str[i];   
    }
    return result;
}
int countRepeatedLetters(string word) {
    map<char, int> freq;
    int repeats = 0;
    for(char c : word) {
        freq[c]++;
    }
    for(auto p : freq) {
        if(p.second > 1)
            repeats += p.second;
    }
    return repeats;
}
string MostRepLetter(string str) {
    vector<string> words = StrSplit(str);
    string mostRepeatedWord = "";
    int maxRepeat = 0;
    for(string word : words) {
        int rep = countRepeatedLetters(word);
        if(rep > maxRepeat) {
            maxRepeat = rep;
            mostRepeatedWord = word;
        }
    }
    return mostRepeatedWord;
}
/*12. Insert Dash Between Two Odd Numbers in a String
Write a C++ program to insert a dash character (-) between two odd numbers in a given string of numbers.
Example:
Sample Input: 1345789
Sample Output: Result-> 1-345-789*/
string DashOddNum(string str) {
    bool NextNum = false;
    string result;
    for(char ch : str) {
        if((ch == '1'||ch == '3'||ch == '5'||ch == '7'||ch == '9')&&(NextNum)) {
            result += '-';
            result += ch;
        }
        else if(ch == '0'||ch == '2'||ch == '4'||ch == '6'||ch == '8') {
            result += ch;
            NextNum = false;
        }
        else if(ch == '1'||ch == '3'||ch == '5'||ch == '7'||ch == '9') {
            NextNum = true;
            result += ch;
        }
        else NextNum = false;
    }
    return result;
}
/*13. Toggle Case of Each Character in a String
Write a C++ program to change the case (lower to upper and upper to lower cases) of each character in a given string.
Example:
Sample Input: Pythpn
Sample Output: pYTHON*/
string ToggleCase(string str) {
    string result;
    for(char ch : str) {
        if(ch>='a'&&ch<='z') result += toupper(ch);
        else if(ch>='A'&&ch<='Z') result += tolower(ch);
        else result += ch;
    }
    return result;
}
/*14. Sum of Numbers in a String
Write a C++ program to find the numbers in a given string and calculate the sum of all numbers.
Example:
Sample Input: w3resource from 2008
Sample Output: Sum of the numbers: 2011*/
int SumNumInStr(string str) {
    int sum = 0;
    string number;
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i])) number += str[i];
        else {
            if (!number.empty()) {
                sum += stoi(number);
                number.clear();
            }
        }
    }
    if (!number.empty()) sum += stoi(number);
    return sum;
}
/*15. Convert a Non-Negative Integer to English Words
Write a C++ program to convert a given non-negative integer into English words.
Example:
Sample Input: 12
Sample Output: Twelve
Sample Input: 29
Sample Output: Twenty Nine*/
string NumberToWords(int num) {
    if (num == 0) return "Zero";
    vector<string> below_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};
    function<string(int)> helper = [&](int n) -> string {
        if (n == 0) return "";
        else if (n < 20) return below_20[n] + " ";
        else if (n < 100) return tens[n / 10] + " " + helper(n % 10);
        else return below_20[n / 100] + " Hundred " + helper(n % 100);
    };
    string result;
    int i = 0;
    while (num > 0) {
        if (num % 1000 != 0) result = helper(num % 1000) + thousands[i] + " " + result;
        num /= 1000;
        i++;
    }
    while (!result.empty() && result.back() == ' ') result.pop_back();
    return result;
}
int main() {
    int i=0;
    cout<<endl<<endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t"<<"Basic Algorithm"<<endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    vector<int> Test1_1 = {78, 20, 21, 28};
    vector<int> Test1_2 = {95, 30, 25, 28};
    for(i=0;i<4;i++)cout<<LarValInRange(Test1_1[i], Test1_2[i])<<endl;
    vector<string> Test2 = {"frizz", "zane", "Zazz", "false"};
    for(string str : Test2) cout<<CheckZChar(str)<<endl;
    vector<int> Test3_1 = {123, 12, 7, 12};
    vector<int> Test3_2 = {456, 512, 87, 45};
    for(i=0;i<4;i++)cout<<SameLasDig(Test3_1[i], Test3_2[i])<<endl;
    vector<int> Test4 = {2, 3, 1};
    for(i=0;i<3;i++) cout<<StrNCop("JS", Test4[i])<<endl;
    vector<string> Test5_1 = {"Python", "Python", "JS"};
    vector<int> Test5_2 = {2, 3, 3};
    for(i=0;i<3;i++)cout<<StrNCopCh(Test5_1[i], Test5_2[i])<<endl;
    vector<string> Test6 = {"bbaaccaag", "jjkiaaasew", "JSaaakoiaa"};
    for(i=0;i<3;i++) cout<<CountAA(Test6[i])<<endl;
    vector<string> Test7 = {"caabb", "babaaba", "aaaaa"};
    for(i=0;i<3;i++) cout<<CheckAftFir(Test7[i])<<endl;
    vector<string> Test8 = {"Python", "PHP", "JS"};
    for(i=0;i<3;i++) cout<<StrOthChar(Test8[i])<<endl;
    vector<string> Test9 = {"abcd", "abc", "a"};
    for(i=0;i<3;i++) cout<<CreateSequence(Test9[i])<<endl;
    vector<string> Test10 = {"abcdsab", "abcdabab", "abcabdabab", "abcabd"};
    for(i=0;i<4;i++) cout<<countSubStr(Test10[i])<<endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t"<<"For-Loops"<<endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<SumNEven(5)<<endl;
    cout<<SumOfHarSer(5)<<endl;
    cout<<SumOf9Ser(5)<<endl;
    cout<<SumOfTySer(3, 5)<<endl;
    cout<<SumOf1Ser(5)<<endl;
    vector<int> NewSer = FibonacciSequence(10);
    for(i=0;i<NewSer.size();i++) {
        if(i==0) cout<<" ["<<NewSer[i]<<", ";
        else if(i==NewSer.size()-1) cout<<NewSer[i]<<"] "<<endl;
        else cout<<NewSer[i]<<", ";
    }
    cout<<sumBetTwoNum()<<endl;
    cout<<LCM(15, 25)<<endl;
    cout<<ReverseNum(12345)<<endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t"<<"String"<<endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    vector<string> sstr = StrSplit("Print a welcome text in a separate line.");
    for(i=0;i<sstr.size();i++) {
        if(i==0) cout<<" ["<<sstr[i]<<", ";
        else if(i==sstr.size()-1) cout<<sstr[i]<<"] "<<endl;
        else cout<<sstr[i]<<", ";
    }
    cout<<MostRepLetter("Print a welcome text in a separate line.")<<endl;
    cout<<DashOddNum("1345789")<<endl;
    cout<<DashOddNum("13579")<<endl;
    cout<<ToggleCase("Python")<<endl;
    cout<<SumNumInStr("w3resource from 2008")<<endl;
    cout<<NumberToWords(12)<<endl;
    cout<<NumberToWords(29)<<endl;
    vector<vector<int>> Test11 = {
        {1, 1, 2, 3, 1}, 
        {1, 1, 2, 4, 1}, 
        {1, 1, 2, 1, 2, 3}
    };
    for(i=0;i<Test11.size();i++) {
        if(i==0) cout<<" ["<<CheckSeq123(Test11[i])<<", ";
        else if(i==Test11.size()-1) cout<<CheckSeq123(Test11[i])<<"] "<<endl;
        else cout<<CheckSeq123(Test11[i])<<", ";
    }
    vector<vector<int>> Test12 = {
        { 5, 5, 1, 15, 15 }, 
        { 15, 2, 3, 4, 15 }, 
        { 3, 3, 15, 15, 5, 5}, 
        { 1, 5, 15, 7, 8, 15}
    };
    for(i=0;i<Test12.size();i++) {
        if(i==0) cout<<" ["<<ComIntInarr(Test12[i])<<", ";
        else if(i==Test12.size()-1) cout<<ComIntInarr(Test12[i])<<"] "<<endl;
        else cout<<ComIntInarr(Test12[i])<<", ";
    }
    cout<<RemoveSpeChar("xxHxix", 'x')<<endl;
    cout<<RemoveSpeChar("abxdddca", 'a')<<endl;
    cout<<RemoveSpeChar("xabjbhtrb", 'b')<<endl;
    vector<string> Test13 = {"Python", "JavaScript", "HTML"};
    for(i=0;i<Test13.size();i++) {
        if(i==0) cout<<" ["<<CharIndex(Test13[i])<<", ";
        else if(i==Test13.size()-1) cout<<CharIndex(Test13[i])<<"] "<<endl;
        else cout<<CharIndex(Test13[i])<<", ";
    }
    vector<vector<int>> Test14 = {
        { 5, 5, 2 }, 
        { 5, 5, 2, 5, 5 }, 
        { 5, 6, 2, 9}
    };
    for(i=0;i<Test14.size();i++) {
        if(i==0) cout<<" ["<<CountCons5(Test14[i])<<", ";
        else if(i==Test14.size()-1) cout<<CountCons5(Test14[i])<<"] "<<endl;
        else cout<<CountCons5(Test14[i])<<", ";
    }
    return 0;
}