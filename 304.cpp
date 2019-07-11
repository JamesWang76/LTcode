#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
void NumMatrix(vector<vector<int>>& matrix);
int sumRegion(int row1, int col1, int row2, int col2);

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
vector<vector<int>> m;
void NumMatrix(vector<vector<int>>& matrix) {
    m = matrix;
    sumRegion(1, 2, 2, 4);
}

int sumRegion(int row1, int col1, int row2, int col2) {
    int sum = 0;
    for (int i = row1; i <= row2; i++) {
        for (int j = col1; j <= col2; j++) {
            sum += m[i][j];
        }
    }
    return sum;
}