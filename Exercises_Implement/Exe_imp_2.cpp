#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>
using namespace std;
/*
  ------------------------------------------------------------
  Weekly C++ Function Implementation Series – Week 2
  Author       : Ali Mohammed Ali Lafi
  Date Range   : April 22 – April 29, 2025
  Language     : C++
  ------------------------------------------------------------
  Topics Covered:
  - Basic Algorithms
  - For-Loops and Iteration Logic
  - String Manipulation
  - Date Calculations
  - Vector Usage and Operations

  Description:
  This program contains a collection of independent functions,
  each solving a specific task related to the topics above.
  The implementation focuses on clarity, correctness, and 
  reusability. Each function is documented with a comment 
  describing the problem it solves.

  Note:
  This file is part of a weekly self-initiated project to
  practice and demonstrate proficiency in C++ through 
  structured function design.
  ------------------------------------------------------------
*/
bool PrimeNumbers(int num) {
    for(int i=2;i<num;i++) 
    if(num%i==0) return false;
    return true;
}
int Factorial(int num) {
    int FacNum = 1;
    while (num>=1)
    {
        FacNum*=num;
        num--;
    }
    return FacNum;
}
// Basic Algorithm
/*11. Add First 3 Characters to Front and Back
Write a C++ program to create a string taking the first 3 characters of a given string.
Then, return the string with the 3 characters added to both the front and back.
If the given string length is less than 3, use whatever characters are there.
Sample Input: ["Python", "JS", "Code"]
Sample Output: [PytPythonPyt, JSJSJS, CodCodeCod]*/
string AddFirst_3(string str) {
    string result, substr;
    if(str.length()<=3) {
        for(int i=1;i<=3;i++)
        result += str;
    }
    else {
        int i;
        for(i=0;i<3;i++) substr += str[i];
        for(i=0;i<str.length();i++) {
            if(i==0) result += substr + str[i];
            else if (i==str.length()-1) result += str[i] + substr;
            else result += str[i];
        }
    }
    return result;
}
/*12. Check If String Starts with 'C#'
Write a C++ program to check if a given string starts with 'C#' or not.
Sample Input:["C++ Sharp", "C#", "C++"]
Sample Output:[1, 1, 0]*/
bool CheckCSharp(string str) {
    bool startsWithCSharp = false;
    bool containsSharp = false;
    if (str.size() >= 2 && str[0] == 'C' && str[1] == '#') startsWithCSharp = true;
    for (int i = 0; i < str.size(); i++) {
        if (tolower(str[i]) == 's') { 
            if (i + 4 < str.size()) { 
                string substring = "";
                for(int j=i;j<str.size();j++) substring += str[j];
                for (auto& c : substring) c = tolower(c);
                if (substring == "sharp") {
                    containsSharp = true;
                    break;
                }
            }
        }
    }
    return startsWithCSharp || containsSharp;
}
/*13. Temperature Less than 0 or Greater than 100
Write a C++ program to check if one given temperature is less than 0 and the other is greater than 100.
Sample Input:[(120, -1), (-1, 120), (2, 120)]
Sample Output:[1, 1, 0] */
bool Temp_100_0(int temp1, int temp2) {
    if((temp1>100 && temp2<0)||(temp1<0 && temp2>100)) return true;
    return false;
}
/*14. Check if Integers are in Range 100?200
Write a C++ program to check two given integers whether either of them is in the range 100..200 inclusive.
Sample Input:[(100, 199), (250, 300), (105, 190)]
Sample Output:[1, 0, 1]*/
bool RangeCheck(int RangeStart, int RangeEnd) {
    if(RangeStart>=100 && RangeEnd<=200) return true;
    return false;
}
/*15. Check if Integers are in Range 20?50
Write a C++ program to check whether three given integer values are in the range 20..50 inclusive.
Return true if 1 or more of them are in the range, otherwise false.
Sample Input:[(11, 20, 12), (30, 30, 17), (25, 35, 50), (15, 12, 8)]
Sample Output:[1, 1, 1, 0]*/
bool InRange(int num1, int num2, int num3) {
    if((num1>=20 && num1<=50)||(num2>=20 && num2<=50)||(num3>=20&&num3<=50)) return true;
    return false;
}
/*16. Check if Either Integer is in Range 20?50
Write a C++ program to check whether two given integer values are in the range 20..50 inclusive.
Return true if 1 or other is in the range, otherwise false.
Sample Input:[(20, 84), (14, 50), (11, 45), (25, 40)]
Sample Output:[1, 1, 1, 0]*/
bool InRange(int num1, int num2) {
    if((num1>=20 && num1<=50)||(num2>=20 && num2<=50)) return true;
    return false;
}
/*17. Remove 'yt' at Index 1
Write a C++ program to check if the string 'yt' appears at index 1 in a given string.
If it appears return a string without 'yt' otherwise return the original string.
Sample Input:["Python", "ytade", "jsues"]
Sample Output:[Phon, ytade, jsues]*/
string Remove_yt_i1(string str) {
    bool RemoveSW = false;
    string result, substr;
    for(int i=1;i<=2;i++) substr += str[i];
    if(substr=="yt") RemoveSW = true;
    if(RemoveSW) {
        for(int i=0;i<str.length();i++) {
            if(i==1 || i==2) continue;
            else result += str[i];
        }
    }
    else return str;
    return result;
}
/*18. Largest of Three Integers
Write a C++ program to check the largest number among three given integers.
Sample Input:[(1,2,3), (1,3,2), (1,1,1), (1,2,2)]
Sample Output:[3, 3, 1, 2]*/
int LarThrInt(int num1, int num2, int num3) {
    if((num1>num2 && num2>num3)||(num1>num3 && num3>num2)) return num1;
    else if((num2>num1 && num1>num3)||(num2>num3 && num3>num1)) return num2;
    else if((num3>num2 && num2>num1)||(num3>num1 && num1>num2)) return num3;
    else return -1;
}
/*19. Closest to 100
Write a C++ program to check which number is closest to the value 100 among two given integers.
Return 0 if the two numbers are equal.
Sample Input:[(78, 95), (95, 95), (99, 70)]
Sample Output:[95, 0, 99]*/
int closestTo100(int num1, int num2) {
    int diff1 = abs(100-num1), diff2 = abs(100-num2);
    if(diff1==diff2) return num1;
    if(diff1>diff2) return num2;
    else return num1;
}
/*20. Check Two Integers in Ranges 40?50 or 50?60
Write a C++ program to check whether two given integers are in the range 40..50 inclusive, or they are both in the range 50..60 inclusive.
Sample Input:[(78, 95), (25, 35), (40, 50), (55, 60)]
Sample Output:[0, 0, 1, 1]*/
int InRange(int num1, int num2, bool Range60) {
    if(Range60) {
        if((num1>=50 && num1<=60)||(num2>=50 && num2<=60))
        return true;
    }
    else {
        if((num1>=40 && num1<=50)||(num2>=40 && num2<=50))
        return true;
    }
    return false;
}
// For-Loops
/*11. Sum of the Series 1 + 1/2^2 + 1/3^3 + ... + 1/n^n
Write a program in C++ to find the sum of the series 1 + 1/2^2 + 1/3^3 + ..+ 1/n^n.
Sample Output:
Input the value for nth term: 5
(1/1^1 = 1)+(1/2^2 = 0.25)+(1/3^3 = 0.037037)+(1/4^4 = 0.00390625)+(1/5^5 = 0.00032) = 1.29126
The sum of the above series is: 1.29126*/
double SerSum_1(int index) {
    if(index==0) return 0;
    double sum = 0;
    for(int i=1;i<=index;i++) sum += 1/(pow(i, i));
    return sum;
}
/*12. Sum of the Series (1*1) + (2*2) + ... + (n*n)
Write a program in C++ to calculate the sum of the series (1*1) + (2*2) + (3*3) + (4*4) + (5*5) + ... + (n*n).
Sample Output:
Input the value for nth term: 5
(1*1 = 1)+(2*2 = 4)+(3*3 = 9)+(4*4 = 16)+(5*5 = 25) = 55
The sum of the above series is: 55*/
int SerSum_2(int index) {
    if(index==0)return 0;
    int sum = 0;
    for(int i=1;i<=index;i++) sum += pow(i, 2);
    return sum;
}
/*13. Sum of the Series (1) + (1+2) + ... + (1+2+...+n)
Write a program in C++ to calculate the series (1) + (1+2) + (1+2+3) + (1+2+3+4) + ... + (1+2+3+4+...+n).
Sample Output:
Input the value for nth term: 5
(1 = 1)+(1+2 = 3)+(1+2+3 = 6)+(1+2+3+4 = 10)+(1+2+3+4+5 = 15) = 35
The sum of the above series is: 35*/
int SerSum_3(int index) {
    int sum = 0;
    for(int i=1;i<=index;i++) sum += i*(index-i+1);
    return sum;
}
/*14. Sum of Series 1 - X^2/2! + X^4/4! - ... up to nth Term
Write a program in C++ to find the sum of series 1 - X^2/2! + X^4/4!-.... upto nth term.
Sample Output:
Input the value of X: 3
Input the value for nth term: 4
term 1 value is: 1
term 2 value is: -4.5
term 3 value is: 3.375
term 4 value is: -1.0125
The sum of the above series is: -1.1375*/
double SerSum_4(int num, int index) {
    int powerindex = 2;
    double sum = 1;
    for(int i = 2;i<=index;i++) {
        if(i%2==0) sum -= pow(num, powerindex)/Factorial(powerindex);
        else sum += pow(num, powerindex)/Factorial(powerindex);
        powerindex += 2;
    }
    return sum;
}
/*15. Process Positive Integers Until Termination Signal (-1)
Write a C++ program that asks the user to enter positive integers in order to process count,
maximum, minimum, and average or terminate the process with -1.
Sample Output:
Your input is for termination.
Here is the result below:
Number of positive integers is: 4
The maximum value is: 9
The minimum value is: 3
The average is 6.00 */
vector<double> ProcessPosInt(vector<double> Numbers) {
    sort(Numbers.begin(), Numbers.end(), greater<int>());
    double maximum = Numbers[0], minimum = Numbers.back(), average = 0;
    for(double number : Numbers) average += number;
    average /= Numbers.size();
    return {maximum, minimum, average};
}
/*16. List Non-Prime Numbers from 1 to Upper Bound
Write a C++ program to list non-prime numbers from 1 to an upperbound.
Sample Output:
Input the upperlimit: 25
The non-prime numbers are:
4 6 8 9 10 12 14 15 16 18 20 21 22 24 25 */
vector<int> NonPrime(int num) {
    vector<int> NonPrimeVec;
    for(int i=1;i<=num;i++) {
        if(!PrimeNumbers(i))
        NonPrimeVec.push_back(i);
    }
    return NonPrimeVec;
}
/*17. Print a Square Pattern with '#' Character
Write a program in C++ to print a square pattern with the # character.
Sample Output:
Print a pattern like square with # character:
--------------------------------------------------
Input the number of characters for a side: 4
# # # #
# # # #
# # # #
# # # # */
void PrintSquare(int sizeOfSqu) {
    for(int i=0;i<sizeOfSqu;i++) {
        for(int j=0;j<sizeOfSqu;j++)cout<<"# ";
        cout<<endl;
    }
}
/*18. Display the Cube of Numbers Up to an Integer
Write a program in C++ to display the cube of the number up to an integer.
Sample Output:
Input the number of terms : 5
Number is : 1 and the cube of 1 is: 1
Number is : 2 and the cube of 2 is: 8
Number is : 3 and the cube of 3 is: 27
Number is : 4 and the cube of 4 is: 64
Number is : 5 and the cube of 5 is: 125 */
int CubeNum(int num) {
    int cubenum = 1;
    for(int i=1;i<=3;i++) cubenum *= num;
    return cubenum;
}
/*19. Display Multiplication Table Vertically from 1 to n
Write a program in C++ to display the multiplication table vertically from 1 to n.
Sample Output:
Input the number upto: 5
Multiplication table from 1 to 5
1x1=1 2x1=2 3x1=3 4x1=4 5x1=5
1x2=2 2x2=4 3x2=6 4x2=8 5x2=10
1x3=3 2x3=6 3x3=9 4x3=12 5x3=15
1x4=4 2x4=8 3x4=12 4x4=16 5x4=20
1x5=5 2x5=10 3x5=15 4x5=20 5x5=25
1x6=6 2x6=12 3x6=18 4x6=24 5x6=30
1x7=7 2x7=14 3x7=21 4x7=28 5x7=35
1x8=8 2x8=16 3x8=24 4x8=32 5x8=40
1x9=9 2x9=18 3x9=27 4x9=36 5x9=45
1x10=10 2x10=20 3x10=30 4x10=40 5x10=50 */
void DisplayMultTab() {
    for(int i=1;i<=10;i++) {
        for(int j=1;j<=5;j++) cout<<j<<'x'<<i<<'='<<i*j<<' ';
        cout<<endl;
    }
}
/*20. Sum of n Odd Natural Numbers
Write a C++ program that displays the sum of n odd natural numbers.
Sample Output:
Input number of terms: 5
The odd numbers are: 1 3 5 7 9
The Sum of odd Natural Numbers upto 5 terms: 25*/
int SNNON(int index) {
    int sum = 0, num = 1;
    while(index) {
        sum += num;
        num += 2;
        index--;
    }
    return sum;
}
// String
/*6. Check Separation of 'e' and 'g' by Exactly 2 Characters
Write a C++ program to check whether the characters e and g are separated by exactly 2 places anywhere in a given string at least once.
+ Example:
Sample Input: eagerer
Sample Output: eagerer -> 1 */
bool CheckSeparation(string str) {
    int testCounter = 2;
    for(char testCh : str) {
        if(testCh == 'e'||testCh == 'g') testCounter--;
        if(!testCounter) return true;
    }
    return false;
}
/*7. Count Vowels in a String
Write a C++ program to count all the vowels in a given string.
Example:
Sample Input: eagerer
Sample output: number of vowels -> 4*/
int CountVowels(string str) {
    int Vowelcounter = 0;
    for(char ch : str) {
        if(ch=='e'||ch=='a'||ch=='i'||ch=='o'||ch=='u') 
        Vowelcounter++;
    }
    return Vowelcounter;
}
/*8. Count the Words in a String
Write a C++ program to count all the words in a given string.
Example:
Sample Input: Python
Sample Output: number of words -> 1 */
int CountWords(string str) {
    vector<string> words;
    string substr;
    for(int i=0;i<str.length();i++) {
        if(str[i]==' '||i==str.length()-1) words.push_back(substr);
        else substr += str[i];
    }
    return words.size();
}
/*9. Check Equal Occurrence of Two Characters
Write a C++ program to check whether two characters appear equally in a given string.
Example:
Sample Input: aabcdeef
Sample Output: True */
bool OccuEqual(string str, char ch1, char ch2) {
    int count1 = 0, count2 = 0;
    for(char ch : str) {
        if(ch == ch1) count1++;
        else if(ch == ch2) count2++;
        else continue;
    }
    return (count1==count2);
}
/*10. Check if a String is a Palindrome
Write a C++ program to check if a given string is a Palindrome or not.
A palindrome is a word, number, phrase, or other sequence of characters which reads the same backward as forward, such as madam, racecar.
Example:
Sample Input: madam
Sample Output: True*/
bool PaliCheck(string str) {
    string result;
    for(int i=str.length()-1;i>=0;i--) result += str[i];
    if(result == str) return true;
    return false;
}
// Date
/*1. Current Date and Time
Write a C++ program to get the current date and time.
The current date and time is:
Tue Mar 15 14:28:05 2022
N.B.: The result may vary for your current system date and time.*/
void CurrentDate() {
    time_t now = time(0);
    tm* local_time = localtime(&now);
    cout << "Current date and time is: ";
    cout << asctime(local_time);
}
/*2. Day of the Week from a Given Date
Write a C++ program to get the day of the week from a given date. Return the day as a string.
The format of the day is MM/DD/YYYY.
Date: 02/05/1980 Day of the week: Tuesday
Date: 01/24/1990 Day of the week: Wednesday
Date: 01/05/2019 Day of the week: Saturday
Date: 11/17/2022 Day of the week: Thursday*/
string DayOfWeek(int year, int month, int day) {
    tm timeStruct = {};
    vector<string> DaysOfWeek = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    timeStruct.tm_year = year - 1900;
    timeStruct.tm_mon = month - 1;
    timeStruct.tm_mday = day;
    mktime(&timeStruct);
    return DaysOfWeek[timeStruct.tm_wday];
}
/*3. Convert a Given Year to a Century
Write a C++ program to convert a given year to a century.
Year: 1900, Century of the year: 19
Year: 1999, Century of the year: 20
Year: 2000, Century of the year: 20
Year: 2010, Century of the year: 21
Year: 2020, Century of the year: 21*/
int YearToCentury(int year) {
    if(year<0) return -1;
    else if(year==0) return 1;
    if(year%100>0) return (year/100)+1;
    else return year/100;
}
/*4. Check Whether a Given Year is a Leap Year
Write a C++ program to check whether a given year is a leap year or not.
Is Leap year: 1900? Century of the year: 0
Is Leap year: 1999? Century of the year: 0
Is Leap year: 2000? Century of the year: 1
Is Leap year: 2010? Century of the year: 0
Is Leap year: 2020? Century of the year: 1*/
/*Note:
The solution presented here reflects my original thinking process at the time of solving the problem.
While there may exist more optimized or conventional solutions, I preferred to showcase my own approach
to emphasize how I analyze and tackle challenges, rather than simply presenting the best available solution.*/
bool IsLeapYear(int year) {
    // complexity ~~> O(n) this make the function slow in high difference between RefYear and year
    // in other words, while year gets bigger; the function while take more time to get the result
    bool LeapTest = false;
    int RefYear = 2000;
    if(year == RefYear) return true;
    else if(year>RefYear) {
        while (year >= RefYear) {
            year -= 4;
            if(year == RefYear) LeapTest = true;
        }
    }
    else {
        while (year <= RefYear) {
            year -= 4;
            if(year == RefYear) LeapTest = true;
        }
    }
    return LeapTest;
}
/*5. Compute the Number of Days in a Month for a Given Year and Month
Write a C++ program to compute the number of days in a month for a given year and month.
Input Year: 2019
Input Month: 04
Number of days of the year 2019 and month 4 is: 30*/
int CompNumOfDays(int year, int month) {
    if(month < 1 || month > 12) return -1;
    vector<int> NumOfDay = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        if(month == 2) return 29;
    }
    return NumOfDay[month - 1];
}
/*6. Count the Number of Days Between Two Given Dates
Write a C++ program to count the number of days between two given dates.
Date Format -> YYYY-MM-DD
Days between 2022/01/31 to 2022/01/01 = 30
Days between 2000/01/31 to 2019/02/01 = 6938
Days between 1980/05/31 to 1995/12/12 = 5677*/
/*Note:
This function estimates the number of days between two dates based on a simplified calculation.
It assumes 365.25 days per year and 30 days per month, so minor inaccuracies are expected.*/
int CountNumOfDays(int year2, int month2, int day2, int year1 = 2000, int month1 = 1, int day1 = 1) {
    float CDays = 0;
    if(year2>0 && year1>0) {
        CDays += abs(((year2-1)-(year1-1))*365.25);
        if(month2>0 && month1>0) {
            CDays += abs(((month2-1)-(month1-1))*30);
            if(day2>0 && day1>0) CDays += abs((day2-1)-(day1-1));
            else return -1;
        }
        else return -1;
    }
    else return -1;
    return CDays;
}
// vector
/*6. Filter Strings Containing Numbers from a Vector
Write a C++ program that takes a vector of strings and returns only those strings that contain a number(s).
Return an empty vector if none.
Example:
Original Vector elements:(red green23 1black white)
Find strings that contain a number(s) from the said vector:(green23 1black)*/
vector<string> FilterStrNum(vector<string> VecStr) {
    bool NumChecker = false;
    vector<string> result;
    for(int i=0;i<VecStr.size();i++) {
        for(char ch : VecStr[i]) {
            if(ch>='0'&&ch<='9')
            NumChecker = true;
        }
        if(NumChecker) result.push_back(VecStr[i]);
        NumChecker = false;
    }
    return result;
}
int main() {
    cout<<endl<<endl;
    cout<<AddFirst_3("Python")<<endl;
    cout<<AddFirst_3("JS")<<endl;
    cout<<AddFirst_3("Code")<<endl;
    cout<<"Check If String Starts with (C++ Sharp) : "<<CheckCSharp("C++ Sharp")<<endl;
    cout<<"Check If String Starts with (C#) : "<<CheckCSharp("C#")<<endl;
    cout<<"Check If String Starts with (C++) : "<<CheckCSharp("C++")<<endl;
    cout<<"(120, -1) : "<<Temp_100_0(120, -1)<<endl;
    cout<<"(-1, 120) : "<<Temp_100_0(-1, 120)<<endl;
    cout<<"(2, 120) : "<<Temp_100_0(2, 120)<<endl;
    cout<<"(100, 199) : "<<RangeCheck(100, 199)<<endl;
    cout<<"(250, 300) : "<<RangeCheck(250, 300)<<endl;
    cout<<"(105, 190) : "<<RangeCheck(105, 190)<<endl;
    cout<<"(11, 20, 12) : "<<InRange(11, 20, 12)<<endl;
    cout<<"(30, 30, 17) : "<<InRange(30, 30, 17)<<endl;
    cout<<"(25, 35, 50) : "<<InRange(25, 35, 50)<<endl;
    cout<<"(15, 12, 8) : "<<InRange(15, 12, 8)<<endl;
    cout<<"(20, 84) : "<<InRange(20, 84)<<endl;
    cout<<"(14, 50) : "<<InRange(14, 50)<<endl;
    cout<<"(11, 45) : "<<InRange(11, 45)<<endl;
    cout<<"(25, 40) : "<<InRange(25, 40)<<endl;
    cout<<Remove_yt_i1("Python")<<endl;
    cout<<Remove_yt_i1("ytade")<<endl;
    cout<<Remove_yt_i1("jsues")<<endl;
    cout<<"(25, 40, 45) : "<<LarThrInt(25, 40, 45)<<endl;
    cout<<"(14, 50, 11) : "<<LarThrInt(14, 50, 11)<<endl;
    cout<<"(20, 84, 50) : "<<LarThrInt(20, 84, 50)<<endl;
    cout<<"(78, 95) : "<<closestTo100(78, 95)<<endl;
    cout<<"(95, 95) : "<<closestTo100(95, 95)<<endl;
    cout<<"(99, 70) : "<<closestTo100(99, 70)<<endl;
    cout<<"(78, 95, true) : "<<InRange(78, 95, true)<<endl;
    cout<<"(25, 35, false) : "<<InRange(78, 95, false)<<endl;
    cout<<"(40, 50, false) : "<<InRange(40, 50, false)<<endl;
    cout<<"(55, 60, true) : "<<InRange(55, 60, true)<<endl;
    cout<<endl<<endl;
    cout<<SerSum_1(5)<<endl;
    cout<<SerSum_2(5)<<endl;
    cout<<SerSum_3(5)<<endl;
    cout<<SerSum_4(3, 4)<<endl;
    vector<double> numbers = ProcessPosInt({55, 35, 26});
    cout<<"maximum = "<<numbers[0]<<endl;
    cout<<"minimum = "<<numbers[1]<<endl;
    cout<<"average = "<<numbers[2]<<endl;
    vector<int> NonPr = NonPrime(25);
    for(int i=0;i<NonPr.size();i++) {
        if(i==0) cout<<'{'<<NonPr[i]<<", ";
        else if(i==NonPr.size()-1) cout<<NonPr[i]<<'}'<<endl;
        else cout<<NonPr[i]<<", ";
    }
    PrintSquare(4);
    PrintSquare(10);
    cout<<"cube value for number 5 : "<<CubeNum(5)<<endl;
    cout<<"cube value for number 4 : "<<CubeNum(4)<<endl;
    cout<<"cube value for number 3 : "<<CubeNum(3)<<endl;
    cout<<"cube value for number 2 : "<<CubeNum(2)<<endl;
    cout<<"cube value for number 1 : "<<CubeNum(1)<<endl;
    DisplayMultTab();
    cout<<"Sum of n Odd Natural Numbers in 5 tarmes : "<<SNNON(5)<<endl;
    cout<<endl<<endl;
    cout<<"eagerer -> "<<CheckSeparation("eagerer")<<endl;
    cout<<"number of vowels -> "<<CountVowels("eagerer")<<endl;
    cout<<CountWords("number of vowels")<<endl;
    cout<<OccuEqual("aabcdeef", 'a', 'e')<<endl;
    cout<<OccuEqual("aabcdeef", 'c', 'e')<<endl;
    cout<<OccuEqual("aabcdeef", 'f', 'b')<<endl;
    cout<<PaliCheck("madam")<<endl;
    cout<<PaliCheck("eagerer")<<endl;
    vector<string> FilVec = FilterStrNum({"red ", "green23 ", "1black ", "white"});
    for(string str : FilVec) cout<<str;
    cout<<endl;
    CurrentDate();
    cout<<DayOfWeek(2025, 4, 26)<<endl;
    cout<<YearToCentury(1900)<<endl;
    cout<<YearToCentury(1999)<<endl;
    cout<<YearToCentury(2000)<<endl;
    cout<<YearToCentury(2010)<<endl;
    cout<<YearToCentury(2020)<<endl;
    cout<<IsLeapYear(1900)<<endl;
    cout<<IsLeapYear(1999)<<endl;
    cout<<IsLeapYear(2000)<<endl;
    cout<<IsLeapYear(2010)<<endl;
    cout<<IsLeapYear(2020)<<endl;
    cout<<CompNumOfDays(2019, 4)<<endl;
    cout<<CompNumOfDays(2025, 4)<<endl;
    cout<<CompNumOfDays(2020, 7)<<endl;
    cout<<CountNumOfDays(2022, 1, 31, 2022, 1, 1)<<endl;// True Erorr = (abs(30-30)/30)*100% = 0%
    cout<<CountNumOfDays(2000, 1, 31, 2019, 2, 1)<<endl;// True Erorr = (abs(6938-6999)/6938)*100% = 0.88%
    cout<<CountNumOfDays(1980, 5, 31, 1995, 12, 12)<<endl;// True Erorr = (abs(5677-5707)/5677)*100% = 0.53%
    return 0;
}