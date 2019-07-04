#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

/**
 * Find the numbers of the binary trees defined as the non-leaf node is the product of its two children.
 * 
 * - Using DP concept
 * - Sort the array, pick a node starting from the index=1(~n) and divide the whole nodes less than it.
 * - Record the divisor and quotient for avoiding be counted twice.
 * - dp[node C] = dp[divosor A] * dp[quotient B] * flip,
 *      - where C=A*B and flip=2 if(A==B), otherwise flip=1
 *      - [10 ,2, 5], [10, 5, 2] => flip=2
 *      - [4, 2, 2] => flip=1
 * 
 * TODO: Too SLOW... using TOO MUCH memory...
 */

int numFactoredBinaryTrees(vector<int>& A);
void printArray(map<int, int> dpTrees);

int main() {
    vector<int> nums;
    int data[] = {2, 7, 9, 14, 63};
    for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        nums.push_back(data[i]);
    }
    numFactoredBinaryTrees(nums);
}

void printArray(map<int, int> dpTrees) {
    for (auto it = dpTrees.begin(); it != dpTrees.end(); it++) {
        cout << it->first << " " << it->second << "\n";
    }
    cout << "\n";
}

int numFactoredBinaryTrees(vector<int>& A) {
    sort(A.begin(), A.end());
    const unsigned int M = 1000000007;
    int arrSize = A.size();
    map<int, long long> dpTrees;
    int ITSELF = 1, divisor;
    long long totalTrees = 0;
    dpTrees[A[0]] = ITSELF;
    totalTrees += dpTrees[A[0]];
    for (int i = 1; i < arrSize; i++) {
        int j = 0;
        long long tmpTrees = 0;
        map<int, bool> count;
        for (int j = 0; j < i; j++) {
            // Ignoring the case if the divisor is greater than half of the dividend (Because it's impossible that the chlid is bigger than half of the parent.)
            // EX: [2,4,6,10], pick node=10, then just considering the case: 10/2 & 10/4;
            if (A[j] >= A[i] / 2 && A[i] != 4) break;
            divisor = A[j];
            // If it had been counted, ignore it.
            if (count[divisor]) break;
            if ((A[i] % divisor) == 0) {
                int quotient = A[i] / divisor;
                int flip = (quotient == divisor) ? 1 : 2;
                long long Trees = dpTrees[quotient] * dpTrees[divisor];
                count[quotient] = true;
                count[divisor] = true;
                Trees *= flip;
                tmpTrees += Trees;
            }
        }
        tmpTrees += ITSELF;
        dpTrees[A[i]] = tmpTrees;
        totalTrees += dpTrees[A[i]];
    }
    return totalTrees % M;
}