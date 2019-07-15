#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
using namespace std;
int minPatches(vector<int>& nums, int n);

/**
 * Find all patch to complete a continuous range list
 * 
 * - Using induction rule.
 * - Build the continuous number list whose maximun value is the biggest value in vector
 *      - If meet the n, then break the loop;
 * - Ex: 
 *      [1,2,4,6] -> I can make sure that 1+2+4=7 is continuos, 7 > 6 so  6 ~ (6+7) is continuous 
 *      [1,2,4,8] -> 1~7 is continuous and alos 8 ~ (8+7), 7&8 conjucate two seperate list.
 *      [1,2,4,9] -> 1~7 is continuous but 7->9 is discontinuous, so add a patch for conjunction.
 * 
 * - Extended concept: Notice that 1,2,4,8 can build from 1 to 15
 *   Faster than 79% and low memory usage.
 */

int main() {
    vector<int> nums;
    int n = 16;
    int data[] = {1, 2};
    for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        nums.push_back(data[i]);
    }
    cout << minPatches(nums, n);
}

int minPatches(vector<int>& nums, int n) {
    int i = 0, checkRange = 0, patchCtr = 0;
    for (i = 0; i < nums.size(); i++) {
        if (checkRange >= nums[i] - 1) {
            checkRange += nums[i];
        } else {
            checkRange *= 2;
            checkRange++;
            patchCtr++;
            i--;
        }
        if (checkRange >= n) break;
    }
    while (checkRange < n) {
        checkRange *= 2;
        checkRange++;
        patchCtr++;
    }
    return patchCtr;
}