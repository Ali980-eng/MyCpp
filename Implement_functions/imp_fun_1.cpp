#include <iostream>
using namespace std;
int dif(int &num1, int &num2)
{
    cout << "Enter the values: ";
    cin >> num1 >> num2;
    if (num1 > num2)
        return num1 - num2;
    else
        return num2 - num1;
}
float div(float &num3, float &num4)
{
    cout << "Enter the numbers you want to divide: ";
    cin >> num3 >> num4;
    if (num4 != 0)
        return num3 / num4;
    else
        return 0;
}
int main()
{
    int choice, x, num1, num2;
    float num3, num4;
    double sum = 0;
    cout << "To calculate the average, press 1\n";
    cout << "To calculate the difference between two numbers, press 2\n";
    cout << "To divide two numbers, press 3\n";
    cin >> choice;
    if (choice == 1)
    {
        cout << "Enter the number of students: ";
        cin >> x;
        float a[x];
        cout << "Enter the values of the array:\n";
        for (int i = 0; i < x; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        cout << "The total degrees of the students: " << sum << endl;
        cout << "The average of the degrees: " << (sum / x) << endl;
    }
    else if (choice == 2)
    {
        cout << dif(num1, num2) << endl;
    }
    else if (choice == 3)
    {
        cout << div(num3, num4) << endl;
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }
    return 0;
}