#include <iostream>
#include <vector>
using namespace std;

/**
 * Split the string in accordance of the IP address rule.
 * 
 * Using 3 for-loop.
 * 
 * - 3 for-loop represents to the 3 dots, check the value on the left-hand side of the dot and handle extra the forth part .
 * - Check the digit in one, ignore the case like "03, 003" whose first char is 0 but the size doesn't equal to 1;
 * - Check if the value is bigger than 255 or not.
 * - NOTICE the parameter of the string.substr()
 * 
 * Faster than 80%
 */

vector<string> restoreIpAddresses(string s);
void printArr(vector<string> ans);
bool checkLRValid(string left, string right);
bool checkLeftValid(string);
bool checkDigitInOne(string digit);

int main() {
    string IP = "25525511135";
    restoreIpAddresses(IP);
}

vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    int sizeArr = s.size(), k;
    if (sizeArr < 4 || sizeArr > 12) return ans;
    for (int i = 0; i < 3; i++) {
        if (i > sizeArr - 4) break;
        string First = s.substr(0, i + 1);
        if (!checkLeftValid(First)) break;
        for (int j = i + 1; j < i + 4; j++) {  // j=i+1 means that start from the index next to the previous index.
            if (j > sizeArr - 3) break;
            string Second = s.substr(i + 1, j - i);
            if (!checkLeftValid(Second)) break;
            for (k = j + 1; k < j + 4; k++) {
                if (k > sizeArr - 2) break;
                string Third = s.substr(j + 1, k - j);
                string Forth = s.substr(k + 1, sizeArr - (k + 1));
                if (!checkLeftValid(Third)) break;
                if (checkLeftValid(Forth) && checkDigitInOne(First) && checkDigitInOne(Second) && checkDigitInOne(Third) && checkDigitInOne(Forth)) {
                    string ipAddress = First + "." + Second + "." + Third + "." + Forth;
                    ans.push_back(ipAddress);
                }
            }
        }
    }
    printArr(ans);
    return ans;
}

void printArr(vector<string> ans) {
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";
}

bool checkLRValid(string left, string right) {
    return (stoi(left) < 256) && (stoi(right) < 256);
}

bool checkLeftValid(string left) {
    return (stoi(left) < 256);
}

bool checkDigitInOne(string digit) {
    if (digit[0] == '0')
        if (digit.size() != 1)
            return false;
    return true;
}
