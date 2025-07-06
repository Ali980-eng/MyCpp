#include <iostream>
#include <string>
#include <vector>
using namespace std;
/**
 * @brief Prints a number of newline characters.
 * @param num Number of new lines to print (default = 2).
 */
void NewLines(short num = 2) { for (int i = 0; i < num; i++) cout << endl; }
/**
 * @brief Prints a value followed by a newline to standard output.
 * @tparam T Type of the value to print.
 * @param output The value to be printed.
 */
template <class dynamic> void println(const dynamic &output) { cout << output << endl; }
/**
 * @brief Prints a value without a newline to standard output.
 * @tparam T Type of the value to print.
 * @param output The value to be printed.
 */
template <class dynamic> void print(const dynamic &output) { cout << output; }
/**
 * @brief Prints an error message followed by a newline to standard error.
 * @tparam T Type of the message to print.
 * @param output The error message to be printed.
 */
template <class dynamic> void println_error(const dynamic &output) { cerr << output << endl; }
/**
 * @brief Prints an error message without a newline to standard error.
 * @tparam T Type of the message to print.
 * @param output The error message to be printed.
 */
template <class dynamic> void print_error(const dynamic &output) { cerr << output; }
/**
 * @brief Prints a prompt message and takes user input of the same type.
 * @tparam T Type of the input variable.
 * @param output The prompt message to display.
 * @return T The user input.
 */
template <class dynamic> dynamic input(const dynamic &output) {
    dynamic var;
    cout << output << endl;
    cin >> var;
    return var;
}
/**
 * @brief Prints a number of tab characters.
 * @param num Number of tabs to print (default = 2).
 */
void Tabs(short num = 2) { for(int i = 0; i < num; i++) cout << "\t"; }
/**
 * @brief Prints a standardized test output.
 * @tparam T The type of the output value.
 * @param TNum The test number.
 * @param OutPut The output value to print.
 * @param VecFun If true, skips printing the output (for use with vector functions).
 */
template <class dynamic> void Test(short TNum, const dynamic &OutPut, bool VecFun = false) {
    if (TNum <= 0) {
        cerr << "The Test Number is equal or smaller than zero" << endl;
        return;
    }
    if (VecFun) {
        cout << "Test(" << TNum << ") :";
        return;
    }
    cout << "Test(" << TNum << ") : " << OutPut << endl;
}
/**
 * @brief Prints all elements in a vector with formatting.
 * @tparam T The type of vector elements.
 * @param vec The vector to print.
 */
template <class dynamic> void PrintVec(const vector<dynamic> &vec) {
    if (vec.empty()) {
        cerr << "The vector is empty" << endl;
        return;
    }
    for (size_t i = 0; i < vec.size(); i++) {
        if (i == 0) cout << " [" << vec[i] << ", ";
        else if (i == vec.size() - 1) cout << vec[i] << "] " << endl;
        else cout << vec[i] << ", ";
    }
}
/**
 * @brief Combines Test() and PrintVec() to test and print vector content.
 * @tparam T The type of vector elements.
 * @param TNum Test number.
 * @param vec The vector to test and print.
 */
template <class dynamic> void VecTest(int TNum, const vector<dynamic> &vec) {
    if (vec.empty()) {
        cerr << "The vector is empty" << endl;
        return;
    }
    Test(TNum, 0, true);
    PrintVec(vec);
}
/**
 * @brief Prints characters of a string individually starting from a given index.
 * @param str The string to print.
 * @param index Starting index (default = 0). If out of range, starts from 0.
 */
void PrintChStr(const string &str, short index = 0) {
    if (index < 0 || index >= str.length()) index = 0;
    for (size_t i = index; i < str.length(); i++) cout << str[i] << ' ';
    cout << endl;
}
/**
 * @brief Prints a horizontal line using a specific character.
 * @param length The number of characters in the line.
 * @param ch The character to use (must be one of: ~, -, #, *, =).
 */
void separator(short length, char ch = '-') {
    if(ch == '~' || ch == '-' || ch == '#' || ch == '*' || ch == '=') {
        for(int i = length; i >= 0; i--) cout << ch;
        cout << endl;
    }
    else cerr << "Invalid separator character." << endl;
}
/**
 * @brief Prints a decorated category title.
 * @param category The category title to print.
 */
void PrintCategory(const string &category) {
    separator(2 * category.length());
    Tabs(category.length() / 10);
    cout << category << endl;
    separator(2 * category.length());
}