#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * Check if the parenthesis rule is correct or not.
 * 
 * - The newer way:
 *      - Delete the pair "()" first, ignore all the '*' symbol
 *      - decrease the stack of '(' if meet the '*', and decrease the '*' if meet the ')'
 * 
 * - The old way:
 *      - Delete the previous '(' when meet to '*'
 *      - Error: "(*)"
 * 
 * Faster than 77%
 */

bool checkValidString(string s);
int main() {
    // "(((((()**********" true
    // "(******((" false
    // "(*)" true
    // **********))))))))**))))))
    string word = "";
    if (checkValidString(word))
        cout << "true";
    else
        cout << "false";
}

bool checkValidString(string s) {
    int all = 0, left = 0, right = 0;
    vector<int> leftParThIdx;
    if (s.size() == 0) return true;
    if (s.size() == 1 && s[0] == '(') return false;
    bool exist[s.size()], ans = true;
    memset(exist, true, s.size() * sizeof(bool));
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            leftParThIdx.insert(leftParThIdx.begin(), i);
        } else if (s[i] == ')') {
            if (leftParThIdx.size() > 0) {
                exist[i] = false;
                exist[leftParThIdx[0]] = false;
                leftParThIdx.erase(leftParThIdx.begin());
            }
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (exist[i]) {
            if (s[i] == '(') {
                left++;
            } else if (s[i] == ')') {
                if (all > 0)
                    all--;
                else
                    right++;
            } else {
                if (left > 0)
                    left--;
                else
                    all++;
            }
        }
    }
    // cout << s << "\n";
    // for (int i = 0; i < s.size(); i++) {
    //     cout << exist[i];
    // }
    // cout << "\n";
    // cout << "left:" << left << "\n";
    // cout << "right:" << right << "\n";
    ans = (left > 0 || right > 0) ? false : true;
    return ans;
}