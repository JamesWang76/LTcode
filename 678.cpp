#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool checkValidString(string s);

int main() {
    // "(((((()**********" true
    // "(******((" false
    // "(*)" true
    string word = "(*)";
    if (checkValidString(word))
        cout << "true";
    else
        cout << "false";
}

bool checkValidString(string s) {
    int qSize = 0;
    int all = 0;
    bool ans = true, start = false;
    if (s.size() == 1 && s[0] == '(') return false;
    for (int i = 0; i < s.size(); i++) {
        // cout<<"now: "<<s[i]<<"\n";
        if (s[i] == '(') {
            qSize++;
        } else if (s[i] == ')') {
            if (qSize == 0) {
                all--;
                if (all < 0) return false;
            } else {
                qSize--;
            }
        } else {  // s[i] == *
            if (qSize > 0)
                qSize--;
            else
                all++;
        }
    }
    ans = (qSize > 0) ? false : true;
    return ans;
}