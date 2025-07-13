#include <iostream>
#include <vector>
using namespace std;
/*========================= Complexity Overview =========================
 * When solving problems using algorithms, it's important to analyze the time and space complexity of the solution.
 * In real-world applications, we often prioritize time complexity because modern computers can handle large memory capacities.
 */
 /* <~~~~~~~~~~ Search Example ~~~~~~~~~~>
 * Index : [0, 1, 2, 3, 4, 5]
 * Array : [10, 5, 15, 2, 25, 55]
 * - Best case: element found at index[0] → Ω (Omega) notation.
 * - Average case: element found in the middle → Θ (Theta) notation.
 * - Worst case: element found at index[5] → O (Big O) notation.
 * In algorithm analysis, we usually focus on the worst-case scenario
 * to ensure performance under all conditions.
 */
 /* ========================= Time Complexity Notations =========================
 * - Constant time: O(1) → operations like +, -, *, /, %, if, else, etc.
 * - Linear time: O(n) → single loop with addition or subtraction.
 * - Logarithmic time: O(log n) → loop with division or multiplication.
 * - Linearithmic time: O(n log n) → nested loops with O(n) and O(log n).
 * - Quadratic time: O(n^2) → nested loops, both O(n).
 * - Exponential time: O(2^n) → recursive calls doubling each time.
 * - Factorial time: O(n!) → permutations or exhaustive recursive solutions.
 */
// Linear time: O(n)
int sum1(int num) {
    int sum = 0;
    for (int i = 0; i <= num; i++) sum += i;
    return sum;
}
// Constant time: O(1)
int sum2(int num) {
    return (num * (num + 1)) / 2;
}
// Linear time: O(n)
int vectorSum(const vector<int>& vec) {
    int vecSum = 0;
    for (int i = 0; i < vec.size(); i++) vecSum += vec[i];
    return vecSum;
}
// Time complexity: O(n * m)
// Where n = number of students, m = number of marks per student
double marksAverage(const vector<vector<int>>& ave) {
    double average = 0.0;
    for (int i = 0; i < ave.size(); i++) average += vectorSum(ave[i]);
    return average / ave.size();
}
int main() {
    cout << endl << endl;
    cout << "sum1 of 100 numbers: " << sum1(100) << endl;
    cout << "sum2 of 100 numbers: " << sum2(100) << endl;
    vector<vector<int>> marks = {
        {22, 17, 46},
        {24, 15, 37},
        {17, 10, 40},
        {30, 20, 50},
        {11, 5, 20}
    };
    cout << "The average = " << marksAverage(marks) << endl;
    return 0;
}