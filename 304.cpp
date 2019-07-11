#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

/**
 * Find the partial original matrix, summing all the elements in this area.
 * 
 * - The better way
 *      - Build a row prefix sum matrix
 *      - notice that the case should be handle if the col1 equals to 0.
 * 
 * - The old way
 *      - Using 2 for-loops to solve it
 *      - BUG: time limit, it took too much time to run.
 */

void NumMatrix(vector<vector<int>>& matrix);
int sumRegion(int row1, int col1, int row2, int col2);
void printArr(vector<vector<int>>& matrix);
int C1 = 0, R1 = 0, C2 = 0, R2 = 0;
int main() {
    vector<vector<int>> data;
    int arr[5][5] = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}};
    for (int i = 0; i < 5; i++) {
        vector<int> tmp;
        for (int j = 0; j < 5; j++) {
            tmp.push_back(arr[i][j]);
        }
        data.push_back(tmp);
    }
    NumMatrix(data);
}

void printArr(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}
vector<vector<int>> rowPrefixSum;
void NumMatrix(vector<vector<int>>& matrix) {
    rowPrefixSum = matrix;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 1; j < matrix[0].size(); j++) {
            rowPrefixSum[i][j] += rowPrefixSum[i][j - 1];
        }
    }
    printArr(rowPrefixSum);
    sumRegion(R1, C1, R2, C2);
}

int sumRegion(int row1, int col1, int row2, int col2) {
    int sum = 0;
    for (int r = row1; r <= row2; r++) {
        if (col1 > 0)
            sum += (rowPrefixSum[r][col2] - rowPrefixSum[r][col1 - 1]);
        else
            sum += (rowPrefixSum[r][col2] - 0);
    }
    cout << "sum: " << sum << "\n";
    return sum;
}