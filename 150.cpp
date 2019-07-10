#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

/**
 * Implement the postfix operation.
 * 
 * - If it is the operator, then pop out the second first element in the stack.
 *      - the first one is LEFT operand, and second one is RIGHT.
 * 
 * TOO slow, but I have no idea how to improve it.
 */

int evalRPN(vector<string>& tokens);
void printArr(vector<string> x);
bool isOperator(string x);
string operate(string left, string right, string operator_);

int main() {
    string data[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    vector<string> nums;
    for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        nums.push_back(data[i]);
    }
    evalRPN(nums);
}

void printArr(vector<string> x) {
    for (int i = 0; i < x.size(); i++)
        cout << x[i] << " ";
    cout << "\n";
}

int evalRPN(vector<string>& tokens) {
    vector<string> stack;
    for (int i = 0; i < tokens.size(); i++) {
        if (isOperator(tokens[i])) {
            string left, right, value;
            right = stack[0];
            left = stack[1];
            value = operate(left, right, tokens[i]);
            stack.erase(stack.begin());
            stack.erase(stack.begin());
            stack.insert(stack.begin(), value);
        } else {
            stack.insert(stack.begin(), tokens[i]);
        }
    }
    return stoi(stack[0]);
}

bool isOperator(string x) {
    if (x == "+" || x == "*" || x == "-" || x == "/") {
        return true;
    } else {
        return false;
    }
}

string operate(string left, string right, string operator_) {
    int value;
    if (operator_ == "+") {
        value = stoi(left) + stoi(right);
    } else if (operator_ == "-") {
        value = stoi(left) - stoi(right);
    } else if (operator_ == "*") {
        value = stoi(left) * stoi(right);
    } else {
        value = stoi(left) / stoi(right);
    }
    return to_string(value);
}