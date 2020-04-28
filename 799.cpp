#include <iostream>
#include <vector>

using namespace std;
double champagneTower(int poured, int query_row, int query_glass);
void pour(int idx, int level, double value);

double arr[100];
int main() {
    champagneTower(8, 4, 5);
}
double champagneTower(int poured, int query_row, int query_glass) {
    for (int i = 0; i < 100; i++)
        arr[i] = 0;
    double value = poured;
    arr[0] = value;
    pour(0, 1, value);

    int tmpCtr = 1;
    int level = 2;
    for (int i = 0; i < 100; i++) {
        cout << arr[i] << " ";
        if (i == tmpCtr - 1) {
            tmpCtr += level;
            level++;
            cout << endl;
        }
    }
}

void pour(int idx, int level, double value) {
    if (value < 1)
        return;
    value = (value - 1) / 2;
    arr[idx + level] += value;
    arr[idx + level + 1] += value;
    pour(idx+level, level+1, value);
    pour(idx+level+1, level+1, value);
}
