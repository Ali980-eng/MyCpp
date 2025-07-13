#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
double CharToNum(char ch) {
    return ch - '0';
}
bool isExpression(char ch) {
    vector<char> expressions = {'+', '-', '^', '=', '/', '*'};
    for(char sym : expressions) {
        if(ch==sym)
        return true;
    }
    return false;
}
double PFEE(const string &postfix) {// PFEE: postfix evaluation expression
    double resulteva = 0;
    string temp;
    stack<double> evaluation;
    for(int k = 1;k<postfix.length();k++) {
        if(isdigit(postfix[k-1])&&(isExpression(postfix[k])||postfix[k]==' ')) evaluation.push(CharToNum(postfix[k-1]));
        else if(isdigit(postfix[k-1])&&isdigit(postfix[k])) {
            for(int j = k-1;j<postfix.length();j++) {
                if(isdigit(postfix[j])) temp += postfix[j];
                else {
                    evaluation.push(stoi(temp));
                    temp.clear();
                    break;
                }
            }
        }
        if(isExpression(postfix[k])) {
            if(postfix[k] == '+') {
                for(int i = evaluation.size()-1;i>=0;i--) { // to loop at the value have been add for the string
                    resulteva += evaluation.top(); // to get the top value and add it to the result
                    evaluation.pop(); // to remove the last element that been evaluated
                }
            }
            else if(postfix[k] == '-') {
                for(int i = evaluation.size()-1;i>=0;i--) { // to loop at the value have been add for the string
                    resulteva -= evaluation.top(); // to get the top value and subtract from the result
                    evaluation.pop(); // to remove the last element that been evaluated
                }
            }
            else if(postfix[k] == '/') {
                if(!resulteva) resulteva = 1; // to avoid the appears of zero in division
                for(int i = evaluation.size()-1;i>=0;i--) { // to loop at the value have been add for the string
                    resulteva /= evaluation.top(); // to get the top value to the division operation
                    evaluation.pop(); // to remove the last element that been evaluated
                }
            }
            else if(postfix[k] == '*') {
                if(!resulteva) resulteva = 1; // to avoid the appears of zero in multiplication
                for(int i = evaluation.size()-1;i>=0;i--) { // to loop at the value have been add for the string
                    resulteva *= evaluation.top(); // to get the top value to the multiplication operation
                    evaluation.pop(); // to remove the last element that been evaluated
                }
            }
            else {
                cerr<<"not valde opreation"<<endl;
                return -1;
            }
        }
    }
    return resulteva;
}
bool isNumber(const string &num) {
    if(num.empty()) {
        cerr<<"The number string is empty."<<endl;
        return "Empty Error";
    }
    for(char ch : num) {
        if(!isdigit(ch))
        return false;
    }
    return true;
}
string InfixToPostfix(const string &infix) {
    string postFix; 
    string temp;
    stack<char> operators;
    auto getPrecedence = [](char op) -> int {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    };
    for (size_t i = 0; i < infix.length(); i++) {
        char ch = infix[i];
        if (isdigit(ch)) temp += ch;
        else if (isExpression(ch)) {
            if (!temp.empty()) {
                postFix += temp;
                postFix += ' ';
                temp.clear();
            }
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(ch)) {
                postFix += operators.top();
                postFix += ' ';
                operators.pop();
            }
            operators.push(ch);
        }
        else if (ch == ' ') {
            if (!temp.empty()) {
                postFix += temp;
                postFix += ' ';
                temp.clear();
            }
        }
    }
    if (!temp.empty()) {
        postFix += temp;
        postFix += ' ';
        temp.clear();
    }
    while (!operators.empty()) {
        postFix += operators.top();
        postFix += ' ';
        operators.pop();
    }
    if (!postFix.empty() && postFix.back() == ' ') postFix.pop_back();
    return postFix;
}
int main() {
    cout<<endl<<endl<<endl;
    cout<<PFEE(InfixToPostfix("2*4-2"))<<endl;
    return 0;
}