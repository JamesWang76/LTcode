#include <iostream>
#include <vector>
using namespace std;

/**
 * Find a number in a "rotate array"
 * 
 * - Record the number to be searched is in the first part or second.
 * - Adjust the mid in accordance with the part
 *      - 2 situation to investigate (Assuming the number is in the SECOND pard):
 *          - If the mid is in FIRST part => (mid+1 = LEFT bound)
 *          - If the mid is in SECOND part => Normal binary search algo.
 * - Binary search focal point
 *      - [o] target > [mid] or otherwise
 *      - [x] target > [mid], target < [mid]
 * 
 * - Faster than 88%, but mem usage is a little bit more.
 */

enum part {
    FIRST,
    SECOND
};
int search(vector<int>& nums, int target);
int binarySearch(vector<int>& nums, int l, int r, int x, part p);

int main() {
    vector<int> nums;
    int data[] = {3, 4, 5, 1, 2};
    for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        nums.push_back(data[i]);
    }
    cout << "ans: " << search(nums, 4);
}

int search(vector<int>& nums, int target) {
    part p;

    if (target <= nums[nums.size() - 1])
        p = SECOND;
    else if (target >= nums[0])
        p = FIRST;
    else
        return -1;

    return binarySearch(nums, 0, nums.size() - 1, target, p);
}

int binarySearch(vector<int>& arr, int l, int r, int x, part p) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;

        if (p == FIRST) {
            if (arr[mid] < arr[l])
                return binarySearch(arr, l, mid - 1, x, p);
            else {
                if (arr[mid] <= x)
                    return binarySearch(arr, mid + 1, r, x, p);
                else
                    return binarySearch(arr, l, mid - 1, x, p);
            }
        } else if (p == SECOND) {
            if (arr[mid] > arr[r])
                return binarySearch(arr, mid + 1, r, x, p);
            else {
                if (arr[mid] <= x)
                    return binarySearch(arr, mid + 1, r, x, p);
                else
                    return binarySearch(arr, l, mid - 1, x, p);
            }
        }
    }

    return -1;
}