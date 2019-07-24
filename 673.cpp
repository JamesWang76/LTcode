#include <iostream>
#include <vector>
using namespace std;
int findNumberOfLIS(vector<int>& nums);
int lis(vector<int> arr, int n);

// I have no idea to solve it.

struct Node {
    bool increase;
    int level = -1;
} node;

int main() {
    vector<int> nums;
    int data[] = {12,15,3,4};
    for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        nums.push_back(data[i]);
    }
    // findNumberOfLIS(nums);
    lis(nums, nums.size());
}

int lis(vector<int> arr, int n) {
    int lis[n];

    lis[0] = 1;

    /* Compute optimized LIS values in bottom up manner */
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++){
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1){
                lis[i] = lis[j] + 1;
            }
        }
    }
        for (int j = 0; j < n; j++){
            cout<<lis[j]<<"\n";
        }
    // Return maximum value in lis[]
    // return *max_element(lis, lis + n);
}

int findNumberOfLIS(vector<int>& nums) {
    vector<Node> arr;
    int level = 1, maxValue = INT_MIN, curIdx = -1, lastIdx = -1;

    for (int i = 0; i < nums.size(); i++) {
        Node n;
        n.level = -1;
        n.increase = false;
        if (maxValue < nums[i]) {
            n.level = level;
            n.increase = true;
            level++;
            maxValue = nums[i];
            lastIdx = curIdx;
            curIdx = i;
        } else {
            cout << "i" << i << "\n";
            n.level = lastIdx;
            n.increase = false;
        }
        arr.push_back(n);
    }

    for (int i = 0; i < nums.size(); i++) {
        if (arr[i].increase) {
            cout << "T  " << arr[i].level << "\n";
        } else {
            cout << "F  " << arr[i].level << "\n";
        }
    }
}