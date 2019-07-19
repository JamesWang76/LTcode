#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * Get the next permutation in lexicographical rule
 * 
 * - Assgin a variable X starts from the second last index to 0, and sort the list on the right hand side of X
 * - Swap the value which is just bigger than X
 *      - It means sort the whole value at the right hand side of X, then pick the value which is just bigger than X
 *      - Ex: 132 
 *              sort: [1] 23
 *              pick the one num bigger than 1: [2] 13
 *      - We want to make sure the new value has the smallest increment and in accordance with the lexicographical order.
 * Faster than 99%
 */

vector<int> nextPermutation(vector<int> &nums);
void printArr(vector<int> x);
void swap(int &a, int &b);

int main() {
    vector<int> nums;
    int data[] = {3, 2, 1};
    for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        nums.push_back(data[i]);
    }
    nextPermutation(nums);
}

void printArr(vector<int> x) {
    for (int i = 0; i < x.size(); i++)
        cout << x[i] << " ";
    cout << "\n";
}

void swap(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
vector<int> nextPermutation(vector<int> &nums) {
    bool swaped = false;
    for (int i = nums.size() - 2; i >= 0; i--) {
        sort(nums.begin() + i + 1, nums.end());
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] < nums[j]) {
                swap(nums[i], nums[j]);
                swaped = true;
            }
            if (swaped) break;
        }
        if (swaped) break;
    }

    // The case which is in the descending order.
    if (!swaped) {                         // Ex: 51234 -> 12345
        nums.insert(nums.end(), nums[0]);  // 512345
        nums.erase(nums.begin());          // 12345
    }
    // cout<<"swap"<<swaped<<"\n";
    printArr(nums);
    return nums;
}