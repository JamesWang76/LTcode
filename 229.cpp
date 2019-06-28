#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
vector<int> majorityElement(vector<int>& nums);

/**
 * Find the majority number in the array.
 * 
 * - Count it and store the number if the number of occurrence is bigger than floor(n/3)
 * - Return it if
 *      - the array size if less than 3 
 *      - the output.size() equals 2 (Because it couldn't exist more than 3 majority numbers)
 */


int main() {
    vector<int> nums;
    int data[] = {10, 0};
    for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        nums.push_back(data[i]);
    }

    nums = majorityElement(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << "\n";
    }
}

vector<int> majorityElement(vector<int>& nums) {
    vector<int> majority;
    int arrSize = nums.size();
    int bound = arrSize / 3;
    map<int, int> table;
    if (arrSize == 1) {
        return nums;
    } else if (arrSize == 2) {
        if (nums[0] == nums[1]) {
            nums.erase(nums.begin());
        }
        return nums;
    }
    for (int i = 0; i < arrSize; i++) {
        if (table[nums[i]] != -1) {
            table[nums[i]]++;
            if (table[nums[i]] > bound) {
                majority.push_back(nums[i]);
                table[nums[i]] = -1;
                if (majority.size() == 2) break;
            }
        }
    }
    return majority;
}