#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int calculate(string s);
int calculateForward(vector<char> stackElement);
void printArr(vector<char> x);

int main() {
    string expr = "12+2+33+4-(2+4+3)";
    calculate(expr);
    // vector<char> x;
    // for (int k = 0; k < expr.size(); k++) {
    //     x.push_back(expr[k]);
    // }
    // calculateForward(x);
}
void printArr(vector<char> x) {
    for (int i = 0; i < x.size(); i++)
        cout << x[i] << " ";
    cout << "\n";
}

int calculate(string s) {
    vector<char> stackElement;
    int i;
    char top;
    for (i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            if (s[i] != ')')
                stackElement.push_back(s[i]);
            else {
                top = stackElement[stackElement.size() - 1];
                int tmpSum = 0, elem = 0, digit = 1, s = 0;
                while (top != '(') {
                    if (top == '+') {
                        // cout<<"op"<<" ";
                        tmpSum += elem;
                        digit = 1;
                        elem = 0;
                    } else if (top == '-') {
                        // cout<<"op- "<<elem<<" ";
                        tmpSum -= (elem);
                        digit = 1;
                        elem = 0;
                    } else {
                        // cout<<"top "<<top<<"\n";
                        elem += (top - '0') * digit;
                        digit *= 10;
                    }
                    stackElement.pop_back();
                    top = stackElement[stackElement.size() - 1];
                }
                stackElement.pop_back();
                tmpSum += elem;
                string tmpSumStr = to_string(tmpSum);
                for (int k = 0; k < tmpSumStr.size(); k++) {
                    stackElement.push_back(tmpSumStr[k]);
                }
                // printArr(stackElement);
                cout << "====="
                     << "\n";
                return calculateForward(stackElement);
            }
        }
    }
}

int calculateForward(vector<char> stackElement) {
    char top;
    int finalSum = 0, elem = 0, digit = 1, sign = 1;
    for (int i = stackElement.size() - 1; i >= 0; i--) {
        top = stackElement[i];
        if (top == '+') {
            finalSum += elem;
            digit = 1;
            elem = 0;
        } else if (top == '-') {
            finalSum -= (elem);
            digit = 1;
            elem = 0;
        } else {
            elem += (top - '0') * digit;
            digit *= 10;
        }
    }
    finalSum += elem;
    cout << "Final Sum " << finalSum << "\n";
    return finalSum;
}