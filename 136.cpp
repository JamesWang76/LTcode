#include <iostream>
#include <vector>
using namespace std;
int singleNumber(vector<int>& nums);

/**
 * Find the number which appears only once(Other numbers appear twice).
 * 
 * - XOR all the numbers, and the numbers which apppear twice would be eliminated.
 */ 
int main(){
    int data[] = {4,1,2,1,2};
    vector<int>nums;
    for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        nums.push_back(data[i]);
    }
    singleNumber(nums);
}
int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); i ++){
        res = nums[i] ^ res;
    }
    return res;
}