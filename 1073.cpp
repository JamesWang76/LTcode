#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2);

/**
 * Make a adder to add two value, and this two binary numbers are in base -2
 * 
 * - Sum = A ^ B ^ Current cin = (A + B + Current Cin)%2, because it (XOR) could be eliminated while two numbers are equal.
 * - Cout = If A=1 and B=1, then the next two digit should add 1
 *      - 1'b + 1'b = 110'b
 *      - 1+1 = 4 + (-2) = 100'b + 10'b
 * 
 * TODO: Speed up this program (Mem usage is better than 100%);
 */



int main() {
    vector<int> numA, numB;
    int data[] = {1};
    int data2[] = {0};
    for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        numA.push_back(data[i]);
    }
    for (int i = 0; i < (sizeof(data2) / sizeof(data2[0])); i++) {
        numB.push_back(data2[i]);
    }
    addNegabinary(numA, numB);
}

vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
    int curPositionA = arr1.size() - 1, curPositionB = arr2.size() - 1, leftOneCout = 0, leftTwoCout = 0, curCout = 0;
    vector<int> ans;
    for (int i = 0; i < max(arr1.size(), arr2.size()) + 2; i++) {
        int A, B, sum;
        A = (curPositionA < 0) ? 0 : arr1[curPositionA];
        B = (curPositionB < 0) ? 0 : arr2[curPositionB];

        sum = A + B + curCout;
        int x = (sum % 2);
        leftOneCout += (sum / 2);
        leftTwoCout += (sum / 2);

        curCout = leftOneCout;
        leftOneCout = leftTwoCout;
        leftTwoCout = 0;

        curPositionA--;
        curPositionB--;
        ans.insert(ans.begin(), x);
    }
    while (ans[0] == 0 && ans.size() > 1) {
        ans.erase(ans.begin());
    }
    return ans;
}