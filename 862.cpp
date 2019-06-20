#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k);
int getMaxSumArr(vector<int> a, int size, int k);
int S;
int main() {
    // int arr[] = {77,19,35,10,-14};
    // int K = 19;
    // int arr[] = {84,-37,32,40,95};
    vector<int> arr;
    arr.push_back(84);
    arr.push_back(-37);
    arr.push_back(32);
    arr.push_back(40);
    arr.push_back(95);
    int K = 167;
    // int arr[] = {56,-21,56,35,-9};
    // int K = 61;
    // S = sizeof(arr) / sizeof(arr[0]);
    int ans = getMaxSumArr(arr, arr.size(), K);
    cout << ans;
}

int getMaxSumArr(vector<int> A, int size, int K) {
    if (A.size() < 1)
        return -1;

    int st = 0;
    int en = 0;
    int res = INT_MAX;
    int sum[A.size() + 1];
    int q[A.size() + 1];

    sum[0] = 0;

    for (int i = 0; i < A.size(); ++i)
        sum[i + 1] = sum[i] + A[i];

    for (int i = 0; i < A.size() + 1; ++i) {
        if (en == st)
            q[en++] = i;
        else {
            cout << "st: " << st << "\n";
            cout << "en: " << en << "\n";
            cout << "sum[i] " << sum[i] << "\n";
            cout << "sum[q[en - 1]] " << sum[q[en - 1]] << "\n";
            cout << "sum[q[st]] " << sum[q[st]] << "\n";
            for (int k = st; k < en; k++) {
                cout << q[k] << "\n";
            }
            while (en != st && sum[i] <= sum[q[en - 1]])
                --en;
            while (en != st && sum[i] - sum[q[st]] >= K) {
                res = min(res, i - q[st]);
                ++st;
            }
            q[en++] = i;
        }
    }
    return res == INT_MAX ? -1 : res;
}