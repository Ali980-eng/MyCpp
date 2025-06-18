#include <iostream>
#include <vector>
#include <string>
using namespace std;     
vector<float> avevec(vector<vector<float>> vec_vec) 
{
    vector<float> avg;
    for (const auto& vec : vec_vec) 
    {
        float sum = 0;
        for (float fnum : vec) sum += fnum;
        sum /= vec.size();
        avg.push_back(sum);
    }
    return avg;
}
float avecom(vector<float> avg, bool combool = true) 
{
    float maxVal = avg[0], minVal = avg[0];
    if (combool) 
    {
        for (float fnum : avg) 
        if (fnum > maxVal) maxVal = fnum;
        return maxVal;
    } 
    else 
    {
        for (float fnum : avg) 
        if (fnum < minVal) minVal = fnum;
        return minVal;
    }
}
string HighestStudent(vector<string> Students, vector<vector<float>> grads) 
{
    if (Students.size() < grads.size()) 
    return "you have students that didn't have a grads";
    vector<float> averages = avevec(grads);
    float HighestNum = avecom(averages);
    for (int i = 0; i < (int)averages.size(); i++) 
    {
        if (averages[i] == HighestNum)
        return Students[i];
    }
    return "not found value";
}
int main() 
{
    vector<string> studentsNames = {"Osama", "Mohmmed", "Ali", "Leen"};
    vector<vector<float>> VecOfVec = {
        {60.94, 65.99, 70.68}, 
        {71.99, 88.55, 76.44}, 
        {81.30, 82.23, 88.87}, 
        {90.11, 96.25, 99.65}};
    cout << HighestStudent(studentsNames, VecOfVec);
    return 0;
}