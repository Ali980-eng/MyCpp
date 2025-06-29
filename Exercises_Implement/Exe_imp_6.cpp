#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
void NewLines(short num = 2) {
    for(int i = 0;i<num;i++)
    cout<<endl;
}
/*    Weekly Function Implementation Series – Week 6
------------------------------------------------------------
    Author   : Ali Mohammed Ali Lafi
    Language : C++
    Duration : June 22, 2025 – June 29, 2025
    Topics Covered:
        - Basic Algorithms
        - For-Loops
        - String Manipulation
    Description:
    This program contains a collection of implemented functions
    related to the topics listed above. Each function represents 
    a small challenge or utility that reinforces core C++ concepts.
    The purpose of this series is to develop and demonstrate 
    programming skills through consistent and focused implementation.
*/
//Basic Algorithm
/*61. First Half of Even-Length String
Write a C++ program to create the string of the first half of a given string of even length.
Sample Input:["Hello", "Hi"]
Sample Output:[He, H]*/
string FirHalfStr(string str) {
    if(str.empty()) return "Empty Erorr";
    string result;
    if(str.length()==2) {
        result += str[0];
        return result;
    }
    size_t HalfLength = str.length()/2;
    for(int i = 0;i<HalfLength;i++) result += str[i];
    return result;
}
/*62. Remove First and Last Characters
Write a C++ program to create a new string without the first and last characters of a given string of length at least two.
Sample Input:["Hello", "Hi", "Python"]
Sample Output:[ell, ytho]*/
string RemoveFirandLas(string str) {
    if(str.length()<=2) return "";
    string result;
    for(int i = 1;i<str.length()-1;i++) result += str[i];
    return result;
}
/*63. Long+Short+Long String Combination
Write a C++ program to create a new string from two given strings, one of which is shorter and the other is larger.
The format of the updated string will be long string + short string + long string.
Sample Input:[("Hello", "Hi"), ("JS", "Python")]
Sample Output:[HelloHiHello, PythonJSPython]*/
string LongShortLong(string str1, string str2) {
    if(str1.empty()||str2.empty()) return "Empty Erorr";
    if(str1.length()>str2.length()) return str1+str2+str1;
    else return str2+str1+str2;
}
/*64. Combine Strings Without First Characters
Write a C++ program to combine two strings of length at least 1, after removing their first character.
Sample Input:[("Hello", "Hi"), ("JS", "Python")]
Sample Output:[elloi, Sython]*/
string ComStrOutFir(string str1, string str2) {
    string result, temp1, temp2;
    for(int i = 1;i<str1.length();i++) temp1 += str1[i];
    for(int j = 1;j<str2.length();j++) temp2 += str2[j];
    result = temp1+temp2;
    return result;
}
/*65. Move First Two Characters to End
Write a C++ program to move the first two characters to the end of a given string of length at least two.
Sample Input:["Hello", "JS"]
Sample Output:[lloHe, JS]*/
string MoveFirTwoToEnd(string str) {
    if(str.length() <= 2) return str;
    string temp, result;
    for(int i = 2;i<str.length();i++) temp += str[i];
    result += temp;
    for(int j = 0;j<2;j++) result += str[j];
    return result;
}
/*66. String Without First and Last Characters
Write a C++ program to create a new string without the first and last characters of a given string of any length.
Sample Input:["Hello", "JS", ""]
Sample Output: ell */
string WithouFirLast(string str) {
    return RemoveFirandLas(str);
}
/*67. Two Middle Characters of Even-Length String
Write a C++ program to create a string using the two middle characters of a given string of even length (at least 2).
Sample Input:["Hell", "JS"]
Sample Output:[el, JS]*/
string TwoMiddChar(string str) {
    size_t StrLen = str.length();
    if(StrLen <= 2) return str;
    if(StrLen%2 == 0) return RemoveFirandLas(str);
    string result;
    for(int i = (StrLen-1)/2;i<StrLen-1;i++) result += str[i];
    return result;
}
/*68. First and Last n Characters from String
Write a C++ program to create a new string using the first and last n characters from a given string of length at least n.
Sample Input:[("Hello", 1), ("Python", 2), ("on", 1), ("o", 1)]
Sample Output:[Ho, Pyon, on, oo]*/
string FirLasNChar(string str, short n) {
    size_t StrLen = str.length();
    if(n > StrLen|| n == StrLen-1) return str;
    if(n == StrLen) return str+str;
    string result;
    for(int i = 0;i<n;i++) result += str[i];
    for(int j = StrLen-n;j<StrLen;j++) result += str[j];
    return result;
}
/*69. String of Length 2 Starting at Given Index
Write a C++ program to create a string of length 2 starting at the given index of a given string.
Sample Input:[("Hello", 1), ("Python", 2), ("on", 1)]
Sample Output:[el, th, on]*/
string cut2Ind(string str, short n) {
    if(n+2 > str.length()) return str;
    string result;
    for(int i = n;i<n+2;i++) result += str[i];
    return result;
}
/*70. Middle Characters String
Write a C++ program that takes at least 3 characters from the middle of a given string that would be used to create a string.
Sample Input:["Hello", "Python", "abc"]
Sample Output:[ell, yth, abc]*/
string Midd3Char(string str) {
    if(str.length() <= 3) return str;
    string result;
    if(str.length()%2==0) {
        for(int j = 1;j<4;j++) result += str[j];
        return result;
    }
    short MiddLen = str.length()/2;
    for(int i = MiddLen-1;i<=MiddLen+1;i++) result += str[i];
    return result;
}
/*71. Two Characters or Pad with #
Write a C++ program to create a new string of length 2, using the first two characters of a given string.
If the given string length is less than 2 use '#' as missing characters.
Sample Input:["Hello", "Python", "a", ""]
Sample Output:[He, Py, a#, ##]*/
string TwoChPad(string str) {
    if(str.empty()) return "##";
    if(str.length()==1) return str+"#";
    if(str.length()==2) return str;
    string result;
    for(int i = 0;i<1;i++) result += str[i];
    return result;
}
/*72. First and Last Character from Two Strings
Write a C++ program to create a string taking the first character from a string and the last character from another given string.
If the length of any given string is 0, use '#' as its missing character.
Sample Input:[("Hello", "Hi"), ("Python", "PHP"), ("JS", "JS"), ("Csharp", "")]
Sample Output:[Hi, PP, JS, C#]*/
string FirLasChTwoStr(string str1, string str2) {
    string result;
    if(str1.empty()&&str2.empty()) return TwoChPad("");
    if(str1.empty()) {
        result += "#";
        result += str2[str2.length()-1];
        return result;
    }
    if(str2.empty()) {
        result += str1[0];
        result += "#";
        return result;
    }
    result += str1[0];
    result += str2[str2.length()-1];
    return result;
}
/*73. Swap Last Two Characters
Write a C++ program to create a new string from a given string after swapping the last two characters.
Sample Input:["Hello", "Python", "PHP", "JS", "C"]
Sample Output:[Helol, Pythno, PPH, SJ, C]*/
string SwapLastTwo(string str) {
    string result, temp;
    int StrLen = str.length();
    if(str.empty()) return "Empty Erorr";
    if(StrLen==1) return str;
    if(StrLen==2) {
        for(int i = StrLen-1;i>=0;i--) result += str[i];
        return result;
    }
    for(int i = 0;i<StrLen-2;i++) result += str[i];
    for(int j = StrLen-1;j>=StrLen-2;j--) result += str[j];
    return result;
}
/*74. Starts with 'abc' or 'xyz', Return It or Empty
Write a C++ program to check if a given string begins with 'abc' or 'xyz'.
If the string begins with 'abc' or 'xyz' return 'abc' or 'xyz' otherwise return the empty string.
Sample Input:["abc", "abcdef", "C", "xyz", "xyzsder"]
Sample Output:[abc, abc,  , xyz, xyz]*/
string AXStart(string str) {
    string substr = str.substr(0, 3);
    if(substr=="abc") return substr;
    else if(substr=="xyz") return substr;
    return "";
}
/*75. First Two = Last Two Characters Check
Write a C++ program to check whether the first two characters and the last two characters of a given string are the same.
Sample Input:["abab", "abcdef", "xyzsderxy"]
Sample Output:[1, 0, 1]*/
bool FirLasTwoCheck(string str) {
    if (str.length() < 2) return false;
    string sub1 = str.substr(0, 2);
    string sub2 = str.substr(str.length() - 2, 2);
    return sub1 == sub2;
}
/*76. Add Strings After Trimming Longer String
Write a C++ program to add two given strings.
If the given strings have different lengths, remove the characters from the longer string.
Sample Input:[("abc", "abcd"), ("Python", "Python"), ("JS", "Python")]
Sample Output:[abcbcd, PythonPython, JSon]*/
string AddAftTrimm(string str1, string str2) {
    if(str1.empty()||str2.empty()) return "";
    string result;
    if(str1.length()>str2.length()) {
        result += str2;
        result += str1.substr(str1.length()-str2.length(), str2.length());
    }
    else if(str2.length()>str1.length()) {
        result += str1;
        result += str2.substr(str2.length()-str1.length(), str1.length());
    }
    else result = str1+str2;
    return result;
}
/*77. 3 Copies of First 2 Characters or Full String
Write a C++ program to create a new string using 3 copies of the first 2 characters of a given string.
If the length of the given string is less than 2 use the whole string.
Sample Input:["abc", "Python", "J"]
Sample Output:[ababab, PyPyPy, JJJ]*/
string copiesOfFir2(string str) {
    if(str.empty()) return "";
    string result;
    if(str.length()<=2) {
        for(int i = 0;i<3;i++) result += str;
        return result;
    }
    string temp = str.substr(0, 2);
    for(int i = 0;i<3;i++) result += temp;
    return result;
}
/*78. Remove First Two Characters if Start = End
Write a C++ program to create a new string from a string.
Return the given string without the first two characters if the two characters at the beginning and end are the same.
Otherwise, return the original string.
Sample Input:["abcab", "Python", "abcabab"]
Sample Output:[cab, Python, cabab]*/
string RemFirTwoCh(string str) {
    if(str.empty()) return "";
    if(str.length()<=2) return str;
    if(FirLasTwoCheck(str)) return str.substr(2, str.length()-2);
    return str;
}
/*79. Remove First/Last 'a' or Return Original
Write a C++ program to create a string from a given string without the first and last character.
This is possible if the first or last characters are 'a' otherwise return the original given string.
Sample Input:["abcab", "python", "abcda", "jython"]
Sample Output:[bcab, python, bcd, jython]*/
string RemoveFirLasA(string str) {
    if(str.empty()) return "";
    string result;
    for(int i = 0;i<str.length();i++) {
        if(str[i] == 'a'&&(i==0||i==str.length()-1)) continue;
        result += str[i];
    }
    return result;
}
/*80. Remove First/First Two 'a's if Present
Write a C++ program to create a new string from a given string.
If the first or first two characters are 'a', return the string without those 'a' characters, otherwise return the original string.
Sample Input:["abcab", "python", "aacda", "jython"]
Sample Output:[bcab, python, cda, jython]*/
string RemFirFirTwoA(string str) {
    if(str.empty()) return "";
    string result;
    for(int i = 0;i<str.length();i++) {
        if(str[i] == 'a'&&(i==0||i==1)) continue;
        result += str[i];
    }
    return result;
}
//For-Loops
/*46. Pascal's Triangle as Right-Angle Triangle
Write a C++ program to display Pascal's triangle like a right angle triangle.
Sample Output:
Input number of rows: 7
1
1   1
1   2   1
1   3   3   1
1   4   6   4   1
1   5   10   10   5   1
1   6   15   20   15   6   1*/
vector<vector<int>> generatePascal(int rows) {
    vector<vector<int>> triangle(rows);
    for(int i = 0; i < rows; ++i) {
        triangle[i].resize(i + 1);
        triangle[i][0] = triangle[i][i] = 1;
        for(int j = 1; j < i; ++j) triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
    }
    return triangle;
}
void RightAnglePascal(int rows) {
    vector<vector<int>> Pascalvec = generatePascal(rows);
    for(vector<int> Vec : Pascalvec) {
        for(int number : Vec) cout<<number<<"   ";
        cout<<endl;
    }
}
/*47. Number Pyramid with 1 at Ends and Row Number in Middle
Write a program in C++ to display such a pattern for n number of rows using numbers.
Odd numbers will appear in each row. The first and last number of each row will be 1 and the middle column will be the row number.
Sample Output:
Input number of rows: 5
    1
   121
  12321
 1234321
123454321*/
void NumberPyramid(int rows) {
    if (rows <= 0) {
        cerr << "The number of rows must be greater than zero." << endl;
        return;
    }
    for (int i = 1; i <= rows; i++) {
        for (int s = 1; s<=rows-i;s++) cout<<" ";
        for (int j = 1;j<=i;j++)cout<<j;
        for (int j = i - 1;j>=1;j--)cout<<j;
        cout << endl;
    }
}
/*48. Alphabet Pyramid
Write a program in C++ to display the pyramid pattern using the alphabet.
Sample Output:
Input the number of Letters (less than 26) in the Pyramid: 5          
        A
      A B A
    A B C B A
  A B C D C B A
A B C D E D C B A*/
void AlphabetPyramid(int rows) {
    if(rows<=0) cerr<<"the rows input is smaller or equale to zero";
    else if(rows == 1) cout<<" A ";
    else {
        int spaces = 2*(rows-1);
        char start = 'A';
        for (int i = 0;i<=rows;i++) {
            for (int s = 0;s<rows-i;s++) cout<<"  ";
            for (int j = 0;j<i;j++)cout<<char(start+j)<<' ';
            for (int j = i - 2;j>=0;j--)cout<<char(start+j)<<' ';
            cout << endl;
        }
    }
}
/*49. Digit Pyramid Pattern
Write a C++ program to print a pyramid of digits as shown below for n number of lines.
    1                                                                                                         
   232                                                                                                        
  34543                                                                                                       
 4567654                                                                                                      
567898765
Sample Output:
Input the number of rows: 5                                           
    1
   232
  34543
 4567654
567898765 */
void DigitPyrPatt(int rows) {
    if(rows<=0) {
        cerr << "The number of rows must be greater than zero." << endl;
        return;
    }
    for(int i = 1;i<=rows;i++) {
        for(int s = 1;s<=rows-i;s++) cout<<" ";
        int num = i;
        for(int j = 1;j<=i;j++) cout<<num++;
        num -= 2;
        for(int j = 1;j<i;j++) cout<<num--;
        cout<<endl;
    }
}
/*50. Descending Column Pattern
Write a C++ program to print a pattern in which the highest number of columns appears in the first row.
Sample Output:
Input the number of rows: 5                                                                                  
12345                                                                                                         
2345                                                                                                          
345                                                                                                           
45                                                                                                            
5*/
void DesColPatt(int rows) {
    if(rows<=0) {
        cerr << "The number of rows must be greater than zero." << endl;
        return;
    }
    for(int i = 0;i<rows;i++) {
        for(int j = i+1;j<=rows;j++) cout<<j;
        cout<<endl;
    }
}
/*51. Right-Justified Descending Pattern
Write a C++ program that displays the pattern with the highest columns in the first row and digits with the right justified digits.
Sample Output:
Input number of rows: 5
12345
 1234
  123
   12
    1*/
void RightJustDesPatt(int rows) {
    if(rows<=0) {
        cerr << "The number of rows must be greater than zero." << endl;
        return;
    }
    for(int i = 0;i<rows;i++) {
        for(int s = 0;s<i;s++) cout<<" ";
        for(int j = 1;j<=rows-i;j++) cout<<j;
        cout<<endl;
    }
}
/*52. Left-Justified Descending Pattern
Write a C++ program to display the pattern using digits with left justified spacing and the highest columns appearing in the first row in descending order.
Sample Output:
Input number of rows: 5
5 4 3 2 1
4 3 2 1
3 2 1
2 1
1*/
void LeftJustDesPatt(int rows) {
    if(rows<=0) {
        cerr << "The number of rows must be greater than zero." << endl;
        return;
    }
    for(int i = 0;i<rows;i++) {
        for(int j = rows-i;j>0;j--) cout<<j<<" ";
        cout<<endl;
    }
}
/*53. Right-Angle Triangle with Right-Justified Numbers
Write a C++ program to display the pattern like right angle triangle with right justified digits.
Sample Output:
Input number of rows: 5                                               
    1
   21
  321
 4321
54321*/
void RightAngleTri(int rows) {
    if(rows<=0) {
        cerr << "The number of rows must be greater than zero." << endl;
        return;
    }
    for(int i = 1;i<=rows;i++) {
        for(int s = 1;s<=rows-i;s++) cout<<" ";
        for(int j = i;j>0;j--) cout<<j;
        cout<<endl;
    }
}
/*54. Pyramid Pattern: Power of 2 Series
Write a program in C++ to display the pattern like pyramid, power of 2.
Sample Output:
Input the number of rows: 5
            1
         1  2  1
      1  2  4  2  1
   1  2  4  8  4  2  1
1  2  4  8  16  8  4  2  1 */
void PyrPattPowof2(int rows) {
    if (rows <= 0) {
        cerr << "The number of rows must be greater than zero." << endl;
        return;
    }
    for (int i = 1;i<=rows;i++) {
        for (int s = 1;s<=3*(rows-i);s++) cout<<" ";
        for (int j = 0;j<i;j++)cout<<pow(2, j)<<"  ";
        for (int j = i-2;j>=0;j--)cout<<pow(2, j)<<"  ";
        cout << endl;
    }
}
/*55. Odd Number Symmetric Pyramid with Row Count
Write a program in C++ to display such a pattern for n number of rows using numbers.
There will be odd numbers in each row.
The first and last number of each row will be 1 and the middle column will be the row number.
N numbers of columns will appear in the 1st row.
Sample Output:
Input number of rows: 7
1234567654321
 12345654321
  123454321
   1234321
    12321
     121
      1 */
void OddNumSymmPyr(int rows) {
    if (rows <= 0) {
        cerr << "The number of rows must be greater than zero." << endl;
        return;
    }
    for(int i = rows;i>0;i--) {
        for(int s = rows-i;s>0;s--) cout<<" ";
        for(int j = 1;j<=i;j++) cout<<j;
        for(int j = i-1;j>0;j--) cout<<j;
        cout<<endl;
    }
}
/*56. First and Last Digits of a Number
Write a program in C++ to find the first and last digits of a number.
Sample Output:
Input any number: 5679
The first digit of 5679 is: 5
The last digit of 5679 is: 9*/
void FirandLasDigi(int num) {
    if(abs(num)<10) {
        cerr<<"The number has to be bigger than 9"<<endl;
        return;
    }
    string snum = to_string(abs(num));
    cout<<"The first digit of "<<num<<" is: "<<snum[0]<<endl;
    cout<<"The last digit of "<<num<<" is: "<<snum[snum.length()-1]<<endl;
}
/*57. Sum of First and Last Digits of a Number
Write a program in C++ to find the sum of the first and last digits of a number.
Sample Output:
Input any number: 12345
The first digit of 12345 is: 1
The last digit of 12345 is: 5
The sum of first and last digit of 12345 is: 6*/
void SumofFirandLas(int num) {
    if(abs(num)<10) {
        cerr<<"The number has to be bigger than 9"<<endl;
        return;
    }
    string snum = to_string(abs(num));
    cout<<"The first digit of "<<num<<" is: "<<snum[0]<<endl;
    cout<<"The last digit of "<<num<<" is: "<<snum[snum.length()-1]<<endl;
    cout<<"The sum of first and last digit of "<<num<<" is: "<<(snum[0]-'0')+(snum[snum.length()-1]-'0')<<endl;
}
/*58. Product of the Digits of a Number
Write a program in C++ to calculate the product of the digits of any number.
Sample Output:
Input a number: 3456
The product of digits of 3456 is: 360*/
void ProdofDigi(int num) {
    int product = 1;
    string snum = to_string(abs(num));
    vector<int> number;
    for(char n : snum) number.push_back(n-'0');
    for(int vnum : number) product *= vnum;
    cout<<"The product of digits of "<<num<<" is: "<<product<<endl;
}
/*59. Frequency of Each Digit in an Integer
Write a program in C++ to find the frequency of each digit in a given integer.
Sample Output:
Input any number: 122345
The frequency of 0 = 0
The frequency of 1 = 1
The frequency of 2 = 2
The frequency of 3 = 1
The frequency of 4 = 1
The frequency of 5 = 1
The frequency of 6 = 0
The frequency of 7 = 0
The frequency of 8 = 0
The frequency of 9 = 0*/
void FreqOfDigit(int num) {
    short count = 0;
    vector<short> freq;
    string snum = to_string(num);
    for(int i = 0;i<10;i++) {
        for(int j = 0;j<snum.length();j++) if(i==(snum[j]-'0')) count++;
        freq.push_back(count);
        count = 0;
    }
    for(int i = 0;i<10;i++) cout<<"The frequency of "<<i<<" = "<<freq[i]<<endl;
}
/*60. Convert a Number to Words (Digit by Digit)
Write a program in C++ to input any number and print it in words.
Sample Output:
Input any number: 8309
Eight Three Zero Nine*/
string ConNumToWords(int num) {
    string result;
    if (num < 0) result += "Minus ";
    string snum = to_string(abs(num));
    for(char digi : snum) {
        if(digi=='0') result += "Zero ";
        else if(digi=='1') result += "One ";
        else if(digi=='2') result += "Two ";
        else if(digi=='3') result += "Three ";
        else if(digi=='4') result += "Four ";
        else if(digi=='5') result += "Five ";
        else if(digi=='6') result += "Six ";
        else if(digi=='7') result += "Seven ";
        else if(digi=='8') result += "Eight ";
        else if(digi=='9') result += "Nine ";
    }
    return result;
}
//string
/*26. Check if a String is Title-Cased
Write a C++ program to check if a given string is a title-cased string or not.
When the string is title cased, return "True", otherwise return "False".
Example:
Original String: The Quick Brown Fox.
Check the said string is a title cased string or not! True */
bool SubStrTitle(string substr) {
    for(int i = 0;i<substr.length();i++) {
        if(i==0&&!isupper(substr[i])) return false;
        if(i>0&&!islower(substr[i])) return false;
    }
    return true;
}
bool CheckStrTitle(string str) {
    string temp;
    vector<string> vecstr;
    for(char ch : str) {
        if(ch == ' ') {
            if (!temp.empty()) vecstr.push_back(temp);
            temp.clear();
        }
        else temp += ch;
    }
    if (!temp.empty()) vecstr.push_back(temp);
    for(string s : vecstr) if(!SubStrTitle(s)) return false;
    return true;
}
/*27. Insert Space Before Lowercase Following Uppercase
Write a C++ program to insert a space when a lower character follows an upper character in a given string.
Example:
Original String: TheQuickBrownFox.
Insert white spaces between lower and uppercase Letters in the said string: The Quick Brown Fox.*/
string InsertSpace(string str) {
    bool LowerSw = false;
    string result;
    for(char ch : str) {
        if(islower(ch)) LowerSw = true;
        else if(isupper(ch)&&LowerSw) {
            result += " ";
            LowerSw = false;
        }
        result += ch;
    }
    return result;
}
/*28. Extract a Specified Number of Vowels from a String
Write a C++ program to extract the first specified number of vowels from a given string.
If the specified number is less than the number of vowels present in the text,
display "n is less than the number of vowels present in the string".
Example:
Input a string: Input a number:
Extract the first n number of vowels from the said string:
n is less than number of vowels present in the string!*/
bool isVow(char ch) {// a, e, i, o, u
    if(ch == 'a'||ch == 'e'||ch == 'i'||ch == 'o'||ch == 'u') return true;
    if(ch == 'A'||ch == 'E'||ch == 'I'||ch == 'O'||ch == 'U') return true;
    return false;
}
short VowCount(string str) {
    if(str.empty()) {
        cerr<<"The empty string is not valid to count"<<endl;
        return -1;
    }
    short count = 0;
    for(char ch : str) if(isVow(ch)) count++;
    return count;
}
vector<char> ExtVowStr(string str, int n) {
    if(n>=VowCount(str)) {
        cerr<<"n is greater than the number of vowels present in the string!"<<endl;
        return {' '};
    }
    int i = 0;
    vector<char> vowvec;
    while (n) {
        if(i>=str.length()) {
            cerr<<"The string is out of range"<<endl;
            return vowvec;
        }
        if(isVow(str[i])) {
            vowvec.push_back(str[i]);
            n--;
        }
        i++;
    }
    return vowvec;
}
/*29. Print an Integer with Commas as Thousands Separators
Write a C++ program to print a given integer with commas separating the thousands.
Example:
Input a number:
Print the said integer with commas as thousands separators: 5,000*/
string FormatNumberWithCommas(int num) {
    bool negative = false;
    short DigiCount = 0;
    if (num < 0) negative = true;
    string SNum = to_string(num);
    if (negative) SNum = SNum.substr(1); // Remove '-' for now
    string result;
    if (SNum.length() <= 3) {
        if (negative) return "-" + SNum;
        else return SNum;
    }
    for (int i = 0; i < SNum.length(); i++) {
        if ((SNum.length() - DigiCount) % 3 == 0 && DigiCount > 0) result += ",";
        result += SNum[i];
        DigiCount++;
    }
    if (negative) return "-" + result;
    return result;
}
/*30. Identify the Missing Letter in a String Sequence
Write a C++ program to identify the missing letter in a given string (list of alphabets).
The method returns, "There is no missing letter!" if no letters are missing from the string.
Example:
Original string: abcdef
Identify the missing letter in the said string:
There is no missing letter!*/
void IdenMissLette(string str, bool UpperCase = false) {
    if (UpperCase) {
        int i = 0;
        for (int j = int('A'); j <= int('Z'); j++) {
            if (i == str.length()) {
                cout << "No missing letter" << endl;
                return;
            }
            if (j != str[i]) {
                cout << "missing letter: " << char(j) << endl;
                return;
            }
            i++;
        }
    }
    else {
        int i = 0;
        for (int j = int('a'); j <= int('z'); j++) {
            if (i == str.length()) {
                cout << "No missing letter" << endl;
                return;
            }
            if (j != str[i]) {
                cout << "missing letter: " << char(j) << endl;
                return;
            }
            i++;
        }
    }
}
/*31. Check if a String Contains Only Uppercase or Lowercase Letters
Write a C++ program to check if a given string contains only uppercase or only lowercase letters.
Return "True" if the string is uppercase or lowercase, otherwise "False".
Example:
Original string: ABCDEF
Check whether the said string is uppercase or lowercase: True*/
bool CaseCheck(string str, bool upper = false) {
    if(upper) {
        for(int i = 0;i<str.length();i++) {
            if(islower(str[i]))
            return false;
        }
    }
    else {
        for(int i = 0;i<str.length();i++) {
            if(isupper(str[i])) 
            return false;
        }
    }
    return true;
}
/*32. Reverse Words of Length Three or More in a String
Write a C++ program that takes a string and reverses the words of three or more lengths in a string.
Return the updated string.
As input characters, only spaces and letters are permitted.
Example:
Original string: The quick brown fox jumps over the lazy dog
Reverse the words of three or more lengths of the said string:
ehT kciuq nworb xof spmuj revo eht yzal god*/
string RevTheLenWor(string str) {
    string temp, result;
    vector<string> vecstr;
    for(char ch : str) {
        if(ch == ' ') {
            vecstr.push_back(temp);
            temp.clear();
        }
        else temp += ch;
    }
    if (!temp.empty()) vecstr.push_back(temp);
    for(string s : vecstr) {
        if(s.length() >= 3) {
            reverse(s.begin(), s.end());
            result += s + " ";
        }
        else result += s + " ";
    }
    if (!result.empty() && result.back() == ' ') result.pop_back();
    return result;
}
/*33. Check if Letters of One String Appear in Another
A string is created using the letters of another string.
Letters are case sensitive.
Write a C++ program to verify that the letters in the second string appear in the first string.
Return true otherwise false.
Test Data:[("CPP", "Cpp") -> false, ("Java", "Ja") -> true, ("Check first string", "sifC") ->true]*/
bool CheckLettBetTow(string str1, string str2, bool CaseSens = false) {
    if (str2.empty()) {
        cerr << "The second string is empty" << endl;
        return false;
    }
    if (str1.empty()) {
        cerr << "The first string is empty" << endl;
        return false;
    }
    if (str2.length() > str1.length()) {
        cerr << "The second string is longer than the first" << endl;
        return false;
    }
    int freq1[256] = {0};
    int freq2[256] = {0};
    for (char ch : str1) {
        if (!CaseSens) ch = tolower(ch);
        freq1[(unsigned char)ch]++;
    }
    for (char ch : str2) {
        if (!CaseSens) ch = tolower(ch);
        freq2[(unsigned char)ch]++;
    }
    for (int i = 0; i < 256; i++) {
        if (freq2[i] > freq1[i])
        return false;
    }
    return true;
}
int main() {
    NewLines();
    cout<<"-------------------------------------------------"<<endl;
    cout<<"\t\t"<<"Basic Algorithm"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"Test(1): "<<FirHalfStr("Hello")<<endl;
    cout<<"Test(2): "<<FirHalfStr("Hi")<<endl;
    cout<<"Test(3): "<<RemoveFirandLas("Hello")<<endl;
    cout<<"Test(4): "<<RemoveFirandLas("Hi")<<endl;
    cout<<"Test(5): "<<RemoveFirandLas("Python")<<endl;
    cout<<"Test(6): "<<LongShortLong("Hello", "Hi")<<endl;
    cout<<"Test(7): "<<LongShortLong("JS", "Python")<<endl;
    cout<<"Test(8): "<<ComStrOutFir("Hello", "Hi")<<endl;
    cout<<"Test(9): "<<ComStrOutFir("JS", "Python")<<endl;
    cout<<"Test(10): "<<MoveFirTwoToEnd("Hello")<<endl;
    cout<<"Test(11): "<<MoveFirTwoToEnd("JS")<<endl;
    cout<<"Test(12): "<<WithouFirLast("Hello")<<endl;
    cout<<"Test(13): "<<WithouFirLast("JS")<<endl;
    cout<<"Test(14): "<<WithouFirLast("")<<endl;
    cout<<"Test(15): "<<TwoMiddChar("Hell")<<endl;
    cout<<"Test(16): "<<TwoMiddChar("JS")<<endl;
    cout<<"Test(17): "<<FirLasNChar("Hello", 1)<<endl;
    cout<<"Test(18): "<<FirLasNChar("Python", 2)<<endl;
    cout<<"Test(19): "<<FirLasNChar("on", 1)<<endl;
    cout<<"Test(20): "<<FirLasNChar("o", 1)<<endl;
    cout<<"Test(21): "<<cut2Ind("Hello", 1)<<endl;
    cout<<"Test(22): "<<cut2Ind("Python", 2)<<endl;
    cout<<"Test(23): "<<cut2Ind("on", 1)<<endl;
    cout<<"Test(24): "<<Midd3Char("Hello")<<endl;
    cout<<"Test(25): "<<Midd3Char("Python")<<endl;
    cout<<"Test(26): "<<Midd3Char("abc")<<endl;
    cout<<"Test(27): "<<TwoChPad("Hello")<<endl;
    cout<<"Test(28): "<<TwoChPad("Python")<<endl;
    cout<<"Test(29): "<<TwoChPad("a")<<endl;
    cout<<"Test(30): "<<TwoChPad("")<<endl;
    cout<<"Test(31): "<<FirLasChTwoStr("Hello", "Hi")<<endl;
    cout<<"Test(32): "<<FirLasChTwoStr("Python", "PHP")<<endl;
    cout<<"Test(33): "<<FirLasChTwoStr("JS", "JS")<<endl;
    cout<<"Test(34): "<<FirLasChTwoStr("Csharp", "")<<endl;
    cout<<"Test(35): "<<SwapLastTwo("Hello")<<endl;
    cout<<"Test(36): "<<SwapLastTwo("Python")<<endl;
    cout<<"Test(37): "<<SwapLastTwo("PHP")<<endl;
    cout<<"Test(38): "<<SwapLastTwo("JS")<<endl;
    cout<<"Test(39): "<<SwapLastTwo("C")<<endl;
    cout<<"Test(40): "<<AXStart("abc")<<endl;
    cout<<"Test(41): "<<AXStart("abcdef")<<endl;
    cout<<"Test(42): "<<AXStart("C")<<endl;
    cout<<"Test(43): "<<AXStart("xyz")<<endl;
    cout<<"Test(44): "<<AXStart("xyzsder")<<endl;
    cout<<"Test(45): "<<FirLasTwoCheck("abab")<<endl;
    cout<<"Test(46): "<<FirLasTwoCheck("abcdef")<<endl;
    cout<<"Test(47): "<<FirLasTwoCheck("xyzsderxy")<<endl;
    cout<<"Test(48): "<<AddAftTrimm("abc", "abcd")<<endl;
    cout<<"Test(49): "<<AddAftTrimm("Python", "Python")<<endl;
    cout<<"Test(50): "<<AddAftTrimm("JS", "Python")<<endl;
    cout<<"Test(51): "<<copiesOfFir2("abc")<<endl;
    cout<<"Test(52): "<<copiesOfFir2("Python")<<endl;
    cout<<"Test(53): "<<copiesOfFir2("J")<<endl;
    cout<<"Test(54): "<<RemFirTwoCh("abcab")<<endl;
    cout<<"Test(55): "<<RemFirTwoCh("Python")<<endl;
    cout<<"Test(56): "<<RemFirTwoCh("abcabab")<<endl;
    cout<<"Test(57): "<<RemoveFirLasA("abcab")<<endl;
    cout<<"Test(58): "<<RemoveFirLasA("Python")<<endl;
    cout<<"Test(59): "<<RemoveFirLasA("abcda")<<endl;
    cout<<"Test(60): "<<RemoveFirLasA("jython")<<endl;
    cout<<"Test(61): "<<RemFirFirTwoA("abcab")<<endl;
    cout<<"Test(62): "<<RemFirFirTwoA("python")<<endl;
    cout<<"Test(63): "<<RemFirFirTwoA("aacda")<<endl;
    cout<<"Test(64): "<<RemFirFirTwoA("jython")<<endl;
    cout<<"---------------------------------------------"<<endl;
    cout<<"\t\t"<<"For-Loops"<<endl;
    cout<<"---------------------------------------------"<<endl;
    cout<<"Test(1): "<<endl; RightAnglePascal(7);
    cout<<"Test(2): "<<endl; NumberPyramid(5);
    cout<<"Test(3): "<<endl; AlphabetPyramid(5);
    cout<<"Test(4): "<<endl; DigitPyrPatt(5);
    cout<<"Test(5): "<<endl; DesColPatt(5);
    cout<<"Test(6): "<<endl; RightJustDesPatt(5);
    cout<<"Test(7): "<<endl; LeftJustDesPatt(5);
    cout<<"Test(8): "<<endl; RightAngleTri(5);
    cout<<"Test(9): "<<endl; PyrPattPowof2(5);
    cout<<"Test(10): "<<endl; OddNumSymmPyr(7);
    cout<<"Test(11): "<<endl; FirandLasDigi(5679);
    cout<<"Test(12): "<<endl; SumofFirandLas(12345);
    cout<<"Test(13): "<<endl; ProdofDigi(3456);
    cout<<"Test(14): "<<endl; FreqOfDigit(122345);
    cout<<"Test(15): "<<ConNumToWords(8309)<<endl;
    cout<<"---------------------------------------------"<<endl;
    cout<<"\t\t"<<"String"<<endl;
    cout<<"---------------------------------------------"<<endl;
    cout<<"Test(1): "<<CheckStrTitle("The Quick Brown Fox")<<endl;
    cout<<"Test(2): "<<InsertSpace("TheQuickBrownFox")<<endl;
    cout<<"Test(3): ";
    vector<char> Testvec = ExtVowStr("Hello Universe", 2);
    for(char TCh : Testvec) cout<<TCh;
    cout<<endl;
    cout<<"Test(4): "<<FormatNumberWithCommas(5000)<<endl;
    cout<<"Test(5): "<<FormatNumberWithCommas(1000000)<<endl;
    cout<<"Test(6): "<<FormatNumberWithCommas(150)<<endl;
    cout<<"Test(7): "<<FormatNumberWithCommas(-150)<<endl;
    cout<<"Test(8): "<<FormatNumberWithCommas(-150000)<<endl;
    cout<<"Test(9): "; IdenMissLette("abcdef");
    cout<<"Test(10): "; IdenMissLette("abcdf");
    cout<<"Test(11): "<<CaseCheck("ABCDEF", true)<<endl;
    cout<<"Test(12): "<<CaseCheck("ABCdEF", true)<<endl;
    cout<<"Test(13): "<<CaseCheck("abcdef")<<endl;
    cout<<"Test(14): "<<CaseCheck("aBcdef")<<endl;
    cout<<"Test(15): "<<RevTheLenWor("The quick brown fox jumps over the lazy dog")<<endl;
    cout<<"Test(16): "<<CheckLettBetTow("CPP", "Cpp", true)<<endl;
    cout<<"Test(17): "<<CheckLettBetTow("Java", "Ja", true)<<endl;
    cout<<"Test(18): "<<CheckLettBetTow("Check first string", "sifC", true)<<endl;
    return 0;
}