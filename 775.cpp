#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool isIdealPermutation(vector<int>& A);
void printArr(vector<int> x);
/**
 * Check if the amount of local inversion equals to the global one
 * 
 * - Make sure that the upper bound is the maximum value, and the lower bound is the second big
 * - Notice the difference between two cases : [2,0,1] and [0,2,1] 
 * 
 */
int main() {
    vector<int> nums;
    int data[] = {0, 1, 3, 2};
    for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        nums.push_back(data[i]);
    }
    if (isIdealPermutation(nums)) {
        cout << "Y";
    } else {
        cout << "N";
    };
}

bool isIdealPermutation(vector<int>& A) {
    int i, lastValue, upperBound, lowerBound;
    if (A.size() <= 2) return true;
    if (A[0] > A[1]) {
        upperBound = A[0];
        lowerBound = A[1];
    } else {
        upperBound = A[1];
        lowerBound = A[0];
    }
    for (i = 2; i < A.size(); i++) {
        if (A[i] > upperBound) {
            lowerBound = upperBound;
            upperBound = A[i];

        } else if (A[i] < upperBound && A[i] > lowerBound) {
            if (lowerBound == A[i - 1])
                return false;
            lowerBound = A[i];
        } else {
            return false;
        }
    }
    return true;
}

void printArr(vector<int> x) {
    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << " ";
    }
    cout << "\n";
}