#include <iostream>
#include <vector>
using namespace std;

int candy(vector<int> &ratings);

int main() {
    vector<int> x = {1, 3, 2, 2, 1};
    cout << candy(x);
}

int candy(vector<int> &ratings) {
    int arr[ratings.size()], ans = 0, minValue = 0;
    memset(arr, 0, ratings.size() * sizeof(int));
    for (int i = 1; i < ratings.size() - 1; i++) {
        if (ratings[i] > ratings[i - 1] || ratings[i] > ratings[i + 1]) {
            arr[i] = arr[i - 1] + 1;
        } else if (ratings[i] < ratings[i - 1] || ratings[i] < ratings[i + 1]) {
            arr[i] = arr[i - 1] - 1;
        }
        if (minValue > arr[i]) {
            minValue = arr[i];
        }
        ans += arr[i];
    }
    ans += (-minValue + 1) * ratings.size();
    return ans;
}
