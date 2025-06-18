#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <array>
#include <iomanip>
#include <algorithm>
using namespace std;
// Basic Algorithm
/*46. Strict Increasing Order with Equality Option
Write a C++ program to check if three given numbers are in strict increasing order.
For example, 4, 7, 15, or 45, 56, 67, but not 4 ,5, 8 or 6, 6, 8.
However, if a fourth parameter is true, equality is allowed, such as 6, 6, 8 or 7, 7, 7.
Sample Input:{(1, 2, 3, false), (1, 2, 3, true), (10, 2, 30, false), (10, 10, 30, true)}
Sample Output:[1, 1, 0, 1]*/
bool StrIncOrd(int num1, int num2, int num3, bool AllowToEqu) {
    if(AllowToEqu) {
        if(num1<=num2&&num2<=num3)
        return true;
    }
    else if(num1<num2&&num2<num3) return true;
    return false;
}
/*47. Same Rightmost Digit for Non-Negative Integers
Write a C++ program to check if two or more integers that are not negative have the same rightmost digit.
Sample Input:[(11, 21, 31), (11, 22, 31), (11, 22, 33)]
Sample Output:[1, 1, 0]*/
bool SameRighDigi(int num1, int num2, int num3) {
    if((num1%10==num2%10)||(num1%10==num3%10)||(num2%10==num3%10)) {
        if((num1%10==num2%10)||(num1%10==num3%10)||(num2%10==num3%10)) return true;
        else return false;
    }
    return false;
}
/*48. 20 Less Than Another Integer
Write a C++ program to check three given integers and return true if one of them is 20 lower than one of the others.
Sample Input:[(11, 21, 31), (11, 22, 31), (10, 20, 15)]
Sample Output:[1, 1, 0]*/
bool LessThAnoInt(int num1, int num2, int num3) {
    return abs(num1 - num2) == 20 || abs(num1 - num3) == 20 || abs(num2 - num3) == 20;
}
/*49. Larger Integer or Smaller with Same Remainder Modulo 7
Write a C++ program to find the larger of two given integers.
However if the two integers have the same remainder when divided by 7, then return the smaller integer.
If the two integers are the same, return 0.
Sample Input:[(11, 21), (11, 20), (10, 10)]
Sample Output:[21, 20, 0]*/
int LarIntRem7(int num1, int num2) {
    if(num1%7==num2%7) {
        if(num1>num2) return num2;
        else if(num1==num2) return 0;
        else return num1;
    }
    if(num1<num2) return num2;
    else return num1;
}
/*50. Shared Digit Between Two Integers (Range 10?99)
Write a C++ program to check two given integers.
Each integer is in the range 10..99.
Return true if a digit appears in both numbers, such as the 3 in 13 and 33.
Sample Input:[(11, 21), (11, 20), (10, 10)]
Sample Output:[1, 0, 1]*/
bool SharDigi(int num1, int num2) {
    if((num1>=10&&num1<=90)&&(num2>=10&&num2<=90)) {
        if(num1==num2) return true;
        else if((num1%10)==(num2%10)) return true;
        else if((num1/10)==(num2/10)) return true;
    }
    return false;
}
/*51. Sum with Same Number of Digits or Return x
Write a C++ program to compute the sum of two given non-negative integers x and y as long as the sum has the same number of digits as x.
If the sum has more digits than x, return x without y.
Sample Input:[(4, 5), (7, 4), (10, 10)]
Sample Output:[9, 7, 20]*/
int SumSameX(int XNum, int YNum) {
    if(XNum<0||YNum<0) return -1;
    int sum = XNum+YNum;
    string SumStr = to_string(sum), XStr = to_string(XNum);
    if(SumStr.length()==XStr.length()) return sum;
    return XNum;
}
/*52. Sum or Third Integer if Two are Equal
Write a C++ program to compute the sum of three given integers.
Return the third value if the two values are the same.
Sample Input:[(4, 5, 7), (7, 4, 12), (10, 10, 12), (12, 12, 18)]
Sample Output:[16, 23, 12, 18]*/
int SumThiInt(int num1, int num2, int num3) {
    if(num1==num2) return num3;
    else return num1+num2+num3;
}
/*53. Sum Ignoring 13 and Right Values
Write a C++ program to compute the sum of the three integers.
If one of the values is 13 then do not count it and its right towards the sum.
Sample Input:[(4, 5, 7), (7, 4, 12), (10, 13, 12), (13, 12, 18)]
Sample Output:[16, 23, 10, 0]*/
int SumIgn13(int num1, int num2, int num3) {
    if(num1==13) return 0;
    else if(num2==13) return num1;
    else if(num3==13) return num1+num2;
    else return num1+num2+num3;
}
/*54. Sum with 10?20 Treated as Zero Except 13/17
Write a C++ program to compute the sum of the three given integers.
Except for 13 and 17, any value in the range 10..20 inclusive counts as 0.
Sample Input:[(4, 5, 7), (7, 4, 12), (10, 13, 12), (17, 12, 18)]
Sample Output:[16, 11, 13, 17]*/
int SumTrea1317(int num1, int num2, int num3) {
    if(num1==13||num2==13||num3==13) return 13;
    else if(num1==17||num2==17||num3==17) return 17;
    else if((num1+num2>=10)&&(num1+num2<=20)) return num1+num2;
    else if((num1+num2+num3>=10)&&(num1+num2+num3<=20)) return num1+num2+num3;
    return num1;
}
/*55. Nearest to 13 Without Crossing Over
Write a C++ program to check two integers and return the value nearest to 13 without crossing over.
Return 0 if both numbers go over.
Sample Input:[(4, 5), (7, 12), (10, 13), (17, 33)]
Sample Output:[5, 12, 13, 0]*/
int Near13Cross(int num1, int num2) {
    if(num1==13||num2==13) return 13;
    else if(num1<13&&num2<13) {
        if(num1>num2) return num1;
        else return num2;
    }
    return 0;
}
/*56. Equal Differences for Three Integers
Write a C++ program to check three given integers (small, medium and large) and return true if the difference between small and medium and the difference between medium and large is same.
Sample Input:[(4, 5, 6), (7, 12, 13), (-1, 0, 1)]
Sample Output:[1, 0, 1]*/
int EquDiffThr(int num1, int num2, int num3) {
    if(num2>num1&&num3>num2) {
        if(num2-num1==num3-num2) return true;
    }
    return false;
}
/*57. String Format s1s2s2s1
Write a C++ program to create another string using two given strings s1, s2, the format of the new string will be s1s2s2s1.
Sample Input:[("Hi", "Hello"), ("whats", "app")]
Sample Output:[HiHelloHelloHi, whatsappappwhats]*/
string StrNewFor(string str1, string str2) {
    return str1+str2+str2+str1;
}
/*58. Insert String in Middle of Another
Write a C++ program to insert a given string into middle of the another given string of length 4.
Sample Input:[("[[]]","Hello"), ("(())", "Hi")]
Sample Output:[[[Hello]], ((Hi))]*/
string InsStrInMidd(string brackets, string str) {
    if(brackets.length()!=4) return "***";
    string result;
    for(int i=0;i<brackets.length();i++) {
        if(i==1) result += brackets[i]+str;
        else result += brackets[i];
    }
    return result;
}
/*59. Three Copies of Last Two Characters
Write a C++ program to create another string using three copies of the last two characters of a given string of length at least two.
Sample Input:["Hello", "Hi"]
Sample Output:[lololo, HiHiHi]*/
string ThrCopLastTwo(string str) {
    if(str.empty()) return "";
    size_t len = str.length();
    string result, NewSub;
    if(len<=2)  NewSub = str;
    else NewSub = str.substr(len-2, 2);
    for(int i = 0;i<3;i++) result += NewSub;
    return result;
}
/*60. First Two Characters or Full String if Less Than 2
Write a C++ program to create a new string using the first two characters of a given string.
If the string length is less than 2, return the original string.
Sample Input:["Hello", "Hi", "H", " "]
Sample Output:[He, Hi, H]*/
string FirTwoCh(string str) {
    string result;
    if(str.length()<=2) return str;
    else {
        for(int i=0;i<2;i++) result += str[i];
    }
    return result;
}
// For-Loops
/*41. Repeating Number Pyramid
Write a C++ program to make such a pattern, like a pyramid, with a repeating number.
Sample Output:
Input number of rows: 5                                               
    1 
   2 2 
  3 3 3 
 4 4 4 4 
5 5 5 5 5 */
void RepNumPyr(int rows) {
    for(int i=1;i<=rows;i++) {
        for(int k=i;k<=rows-1;k++) cout<<' ';
        for(int j=1;j<=i;j++) cout<<i<<' ';
        cout<<endl;
    }
}
/*42. Pyramid Asterisk Pattern with Odd Numbers
Write a C++ program that displays the pattern like a pyramid using asterisks, with odd numbers in each row.
Sample Output:                                              
Input number of rows: 5                                                               
   *  
  ***
 *****
******* */
void PyrAstPatt(int rows) {
    string stars = "*";
    for(int i=1;i<=rows;i++) {
        for(int j=1;j<=rows-i;j++) cout<<' ';
        cout<<stars<<endl;
        stars +="**";
    }
}
/*43. Floyd's Triangle
Write a C++ program to print Floyd's Triangle.
Sample Output:
Input number of rows: 5                                               
1
01
101
0101
10101*/
void FloTri(int rows) {
    bool B = true;
    for(int j=rows-1;j>=0;j--) {
        for(int i=1;i<=rows-j;i++) {
            cout<<B;
            if(B) B = false;
            else B = true;
        }
        if((rows-j)%2 != 0) B = false;
        else B = true;
        cout<<endl;
    }
}
/*44. Diamond Pattern
Write a C++ program to display a pattern like a diamond.
Sample Output:
Input number of rows (half of the diamond): 5                                                                                        
    *
   ***
  *****
 *******
********* 
 *******
  ***** 
   ***
    * */
void DiaPatt(int rows) {
    string stars = "*";
    int i = 0, j = 0, k = 0;
    for(i=1;i<=rows;i++) {
        for(j=1;j<=rows-i;j++) cout<<' ';
        cout<<stars<<endl;
        stars +="**";
    }
    stars = stars.substr(2);
    for(k=rows-1;k>=0;k--) {
        for(j=2;j<=rows-k;j++) cout<<' ';
        if(k != rows-1)cout<<stars<<endl;
        if(stars.length()>2) stars = stars.substr(2);
        else stars = "*";
    }
}
/*45. Pascal's Triangle as Pyramid
Write a C++ program to display Pascal's triangle like a pyramid.
Sample Output:
Input number of rows: 5
        1
      1   1
    1   2   1
  1   3   3   1
1   4   6   4   1 */
vector<vector<int>> generatePascal(int rows) {
    vector<vector<int>> triangle(rows);
    for(int i = 0; i < rows; ++i) {
        triangle[i].resize(i + 1);
        triangle[i][0] = triangle[i][i] = 1;
        for(int j = 1; j < i; ++j) triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
    }
    return triangle;
}
void printPascalPyramid(int rows) {
    vector<vector<int>> pascal = generatePascal(rows);
    for(int i = 0; i < rows; ++i) {
        cout << string((rows - i) * 2, ' ');
        for(int j = 0; j <= i; ++j) cout << setw(4) << pascal[i][j];
        cout << endl;
    }
}
//string 
/*21. Check if a String is a Subsequence of Another
Write a C++ program to check whether a given string is a subsequence of another given string.
Return 1 for true and 0 for false.
Example:
word1: apple
subse1: apl
Is subse1 is the subsequence of word1? 1
word2: apple
subse2: ppe
Is subse2 is the subsequence of word2? 1
word3: ACGGTGTCGTGCTATGCTGATGCTGACTTATATGCTA
subse3: CGTTCGGCTATGCTTCTACTTATTCTA
Is subse3 is the subsequence of word3? 1
word4: CGTTCGGCTATCGTACGTTCTATTCTATGATTTCTAA
subse4: CGTTCGGCTATGCZTTCTACTTATTCTA
Is subse4 is the subsequence of word4? 0*/
bool SubSeqCheck(string str, string subseq) {
    int i = 0;
    for (char ch : str) { // make char to loop in the original string
        if (ch == subseq[i]) i++; // if ch is equal to the subseq in index i we will increase the value of the index to the next position.
        if (i == subseq.length()) return true; // if the index i equal the length of the string that means the all chars in the subseq string match with the original string chars.
    }
    return false;
}
/*22. Remove All Special Characters from a String
Write a C++ program to remove all special characters from a given string.
Example:
Original string: abcd $ js# @acde$
New string after removing the special characters from the said string:
abcd js acde*/
string RemAllSpe(string str) {
    string result;
    for(char spech : str) {
        if((spech>='A'&&spech<='z')||(spech>='a'&&spech<='z')||spech == ' ')
        result += spech;
    }
    return result;
}
string RetAllSpe(string str) {
    string result;
    for(char spech : str) {
        if((spech>='A'&&spech<='z')||(spech>='a'&&spech<='z')||spech == ' ') continue;
        else result += spech;
    }
    return result;
}
/*23. Count Unique Characters in Two Strings
Write a C++ program that counts the number of unique characters in two given strings.
Example:
Original Strings:
String1: Python
String2: Java
Total number of unique characters: 8*/
int CountUniCh(string str) {
    short count = 0;
    int resCount = 0;
    for (int i = 0; i < str.length(); i++) {
        count = 0;
        for (int j = 0; j < str.length(); j++) {
            if (str[i] == str[j]) count++;
        }
        bool isFirst = true;
        for (int k = 0; k < i; k++) {
            if (str[k] == str[i]) {
                isFirst = false;
                break;
            }
        }
        if (count == 1 && isFirst) resCount++;
    }
    return resCount;
}
int CountUniCh(string str1, string str2) {
    return CountUniCh(str1 + str2);
}
/*24. Count Duplicate Characters in a String
Write a C++ program to count the number of duplicate characters in a given string.
Example:
Original String:
Total number of unique characters of the said two strings.
Number of duplicate characters in the said string: 36*/
string CutStr(string str, char holdch) {
    string result;
    for (char c : str) {
        if (c == ' ') continue;
        if (c != holdch) result += c; 
    }
    return result;
}
int CountDupCh(string str) {
    int dupCount = 0;
    string work = str;
    while (!work.empty()) {
        char c = work[0];
        string next = CutStr(work, c);
        int removed = work.length() - next.length();
        if (removed > 1) dupCount++;
        work = next;
    }
    return dupCount;
}
/*25. Longest Sequence of Consecutive Ones in a Binary String
Write a C++ program to find the longest sequence of consecutive ones in a given binary string.
Example:
Original Binary String:1100110001
Longest sequence of consecutive ones of the said binary string:11*/
vector<size_t> StrsIndex(vector<string> VecStr) {
    vector<size_t> Index;
    for(int i = 0;i<VecStr.size();i++) 
    Index.push_back(VecStr[i].length());
    return Index;
}
size_t mixInd(vector<size_t> Index) {
    size_t resInd = 0, max = Index[0];
    for(int i = 0;i<Index.size();i++) {
        if(Index[i]>max) {
            max = Index[i];
            resInd = i;
        }
    }
    return resInd;
}
string LonSeqOfOne(string str) {
    vector<string> temp;
    string result;
    for(int i = 0;i<str.length();i++) {
        if(str[i] == '1') result.push_back(str[i]);
        else if(str[i] == '0') {
            temp.push_back(result);
            result = "";
        }
        else return "***";
    }
    vector<size_t> index = StrsIndex(temp);
    return temp[mixInd(index)];
}
int main() {
    cout<<endl<<endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t"<<"Basic Algorithm"<<endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"Test(1) : ";
    cout<<" ["<<StrIncOrd(1, 2, 3, false)<<", ";
    cout<<StrIncOrd(1, 2, 3, true)<<", ";
    cout<<StrIncOrd(10, 2, 30, false)<<", ";
    cout<<StrIncOrd(10, 10, 30, true)<<"] "<<endl;
    cout<<"Test(2) : ";
    cout<<" ["<<SameRighDigi(11, 21, 31)<<", ";
    cout<<SameRighDigi(11, 22, 31)<<", ";
    cout<<SameRighDigi(11, 22, 33)<<"] "<<endl;
    cout<<"Test(3) : ";
    cout<<" ["<<LessThAnoInt(11, 21, 31)<<", ";
    cout<<LessThAnoInt(11, 22, 31)<<", ";
    cout<<LessThAnoInt(10, 20, 15)<<"] "<<endl;
    cout<<"Test(4) : ";
    cout<<" ["<<LarIntRem7(11, 21)<<", ";
    cout<<LarIntRem7(11, 20)<<", ";
    cout<<LarIntRem7(10, 10)<<"] "<<endl;
    cout<<"Test(5) : ";
    cout<<" ["<<SharDigi(11, 21)<<", ";
    cout<<SharDigi(11, 20)<<", ";
    cout<<SharDigi(10, 10)<<"] "<<endl;
    cout<<"Test(6) : ";
    cout<<" ["<<SumSameX(4, 5)<<", ";
    cout<<SumSameX(7, 4)<<", ";
    cout<<SumSameX(10, 10)<<"] "<<endl;
    cout<<"Test(7) : ";
    cout<<" ["<<SumThiInt(4, 5, 7)<<", ";
    cout<<SumThiInt(7, 4, 12)<<", ";
    cout<<SumThiInt(10, 10, 12)<<", ";
    cout<<SumThiInt(12, 12, 18)<<"] "<<endl;
    cout<<"Test(8) : ";
    cout<<" ["<<SumIgn13(4, 5, 7)<<", ";
    cout<<SumIgn13(7, 4, 12)<<", ";
    cout<<SumIgn13(10, 13, 12)<<", ";
    cout<<SumIgn13(13, 12, 18)<<"] "<<endl;
    cout<<"Test(9) : ";
    cout<<" ["<<SumTrea1317(4, 5, 7)<<", ";
    cout<<SumTrea1317(7, 4, 12)<<", ";
    cout<<SumTrea1317(10, 13, 12)<<", ";
    cout<<SumTrea1317(17, 12, 18)<<"] "<<endl;
    cout<<"Test(10) : ";
    cout<<" ["<<Near13Cross(4, 5)<<", ";
    cout<<Near13Cross(7, 12)<<", ";
    cout<<Near13Cross(10, 13)<<", ";
    cout<<Near13Cross(17, 33)<<"] "<<endl;
    cout<<"Test(11) : ";
    cout<<" ["<<EquDiffThr(4, 5, 6)<<", ";
    cout<<EquDiffThr(7, 12, 13)<<", ";
    cout<<EquDiffThr(-1, 0, 1)<<"] "<<endl;
    cout<<"Test(12) : ";
    cout<<" ["<<StrNewFor("Hi", "Hello")<<", ";
    cout<<StrNewFor("whats", "app")<<"] "<<endl;
    cout<<"Test(13) : ";
    cout<<" ["<<InsStrInMidd("[[]]","Hello")<<", ";
    cout<<InsStrInMidd("(())", "Hi")<<"] "<<endl;
    cout<<"Test(14) : ";
    cout<<" ["<<ThrCopLastTwo("Hello")<<", ";
    cout<<ThrCopLastTwo("Hi")<<"] "<<endl;
    cout<<"Test(15) : ";
    cout<<" ["<<FirTwoCh("Hello")<<", ";
    cout<<FirTwoCh("Hi")<<", ";
    cout<<FirTwoCh("H")<<", ";
    cout<<FirTwoCh(" ")<<"] "<<endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t"<<"For-Loops"<<endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"Test(1) : "<<endl;
    RepNumPyr(5);
    cout<<"Test(2) : "<<endl;
    PyrAstPatt(5);
    cout<<"Test(3) : "<<endl;
    FloTri(5);
    cout<<"Test(4) : "<<endl;
    DiaPatt(5);
    cout<<"Test(5) : "<<endl;
    printPascalPyramid(5);
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t"<<"string"<<endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"Test(1) : "<<endl;
    cout<<" ["<<SubSeqCheck("apple", "apl")<<", ";
    cout<<SubSeqCheck("apple", "ppe")<<", ";
    cout<<SubSeqCheck("ACGGTGTCGTGCTATGCTGATGCTGACTTATATGCTA", "CGTTCGGCTATGCTTCTACTTATTCTA")<<", ";
    cout<<SubSeqCheck("CGTTCGGCTATCGTACGTTCTATTCTATGATTTCTAA", "CGTTCGGCTATGCZTTCTACTTATTCTA")<<"] "<<endl;
    cout<<"Test(2) : "<<RemAllSpe("abcd $ js# @acde$")<<endl;
    cout<<"Test(3) : "<<RetAllSpe("abcd $ js# @acde$")<<endl;
    cout<<"Test(4) : "<<CountUniCh("Python", "Java")<<endl;
    cout<<"Test(5) : "<<CountDupCh("Total number of unique characters of the said two strings.")<<endl;
    cout<<"Test(6) : "<<LonSeqOfOne("1100110001")<<endl;
    cout<<"Test(7) : "<<LonSeqOfOne("0011110011101")<<endl;
    return 0;
}