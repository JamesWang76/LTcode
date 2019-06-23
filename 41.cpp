#include <iostream>
#include <vector>
using namespace std;

/**
 * Q: Find the min first missing positive value in the array
 * 
 * 1. Sort it and find it.
 * 2. Be cautious of the continuos value 
 */ 


int firstMissingPositive(vector<int>& nums);
struct compare {
    bool operator()(const int& l, const int& r) {
        return l > r;
    }
};
int main() {
    vector<int> nums;
    // [0, 2, 2, 1, 1]
    int data[] = {1,1,1,1,1,1,1,1,1};
    for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        nums.push_back(data[i]);
    }
    cout<<firstMissingPositive(nums);
}
int firstMissingPositive(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int firstMissing = 1, prevNum=INT_MAX;;
    bool continuous = true;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>0 && nums[i]!=prevNum){
            prevNum = nums[i];
            // cout<<nums[i]<<" "<<firstMissing<<"---\n";
            if(nums[i] != firstMissing){
                // cout<<firstMissing;
                return firstMissing;
                continuous = false;
            }else{
                firstMissing++;
            }
        }
    }
    if(continuous){
        // cout<<firstMissing;
        return firstMissing;
    }
    return 0;
}