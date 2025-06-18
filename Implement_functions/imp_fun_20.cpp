#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
long long int titration(int num, int TutraNum) 
{
    long long int BigNum = num;
    for (int i = 1; i < TutraNum; i++) 
    {
        long long int temp = 1;
        for (int j = 0; j < BigNum; j++) 
        {
            temp *= num;
            if (temp > LLONG_MAX / num) return -1; 
        }
        BigNum = temp;
    }
    return (TutraNum == 0) ? 1 : BigNum;
}
vector<long double> FracFac(long double fraction) {
    if(fraction == 0) return {1};
    else if(fraction<0) return {-1};
    vector<long double> result;
    long double FacNum = 1;
    while (fraction) {
        if(fraction>=1) {
            FacNum *= fraction;
            fraction--;
            result.push_back(FacNum);
        }
        else if(fraction<1&&fraction>0) {
            for(int i = 0;i<10;i++) {
                FacNum *= fraction;
                fraction = (fraction/2);
                result.push_back(FacNum);
            }
        }
    } 
    return result;
}
int main() {
    cout<<endl<<endl;
    // Test values for FracFac function.
    // Corresponding Gamma(x+1) values are provided as comments for external reference.
    // Gamma(x+1) = x! (where x is the input to FracFac).
    vector<double> test_values = {
        5.0,                         // For comparison: Gamma(6.0) = 120.000000000000000
        4.0,                         // For comparison: Gamma(5.0) = 24.000000000000000
        1.0,                         // For comparison: Gamma(2.0) = 1.000000000000000
        3.141592653589793,           // For comparison: Gamma(4.14159) = ~7.188082728976032
        2.5,                         // For comparison: Gamma(3.5) = ~3.323350970424835
        1.5,                         // For comparison: Gamma(2.5) = ~1.329340388179814
        0.5,                         // For comparison: Gamma(1.5) = ~0.886226925452758
        0.1,                         // For comparison: Gamma(1.1) = ~0.951350769866164
        0.0,                         // For comparison: Gamma(1.0) = 1.000000000000000
        -2.0                         // For comparison: Gamma(-1.0) = Undefined (approaches infinity)
    }; // End of test_values vector initialization
    vector<vector<long double>> TestMat;
    for(double TestNum : test_values) TestMat.push_back(FracFac(TestNum));
    for(int i = 0;i<TestMat.size();i++) {
        cout<<"Vector("<<i<<") : ";
        for(int j = 0;j<TestMat[i].size();j++) {
            if(TestMat[i].size()== 1) {
                cout<<'['<<TestMat[i][j]<<']';
                break;
            }
            if(j==0) cout<<"[ "<<TestMat[i][j]<<", ";
            else if(j==TestMat[i].size()-1) cout<<TestMat[i][j]<<"] ";
            else cout<<TestMat[i][j]<<", ";
        }
        cout<<endl;
    }
    return 0;
}