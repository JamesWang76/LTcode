#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k);
int getMaxSumArr(int a[], int size, int k);
int S;
int main() {
    int arr[] = {56, -21, 56, 35, -9};
    int K = 61;
    S = sizeof(arr) / sizeof(arr[0]);
    int ans = getMaxSumArr(arr, S, K);
    cout << "ans: " << ans << "\n"; // Expect 2
}

int getMaxSumArr(int A[], int size, int K) {
    long long maxSum = INT_MIN, curSum = 0;
    int lastIdx = 0, curIdx = 0;
    for (int i = 0; i < size; i++) {
        curSum = curSum + A[i];
        if (maxSum < curSum) {
            lastIdx = curIdx;
            curIdx = i;
            maxSum = curSum;
            if (curSum >= K)
                break;
        }
        if (curSum < 0) {
            curSum = 0;
        }
    }
    cout << lastIdx << "  " << curIdx << "\n";
    if (maxSum < K)
        return -1;
    else
        return (curIdx - lastIdx + 1);
}