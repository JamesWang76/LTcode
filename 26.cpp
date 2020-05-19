#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int>& nums);

int main(){
    vector<int> nums;
    int data[] = {0,0,1,1,1,2,2,3,3,4};
    for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        nums.push_back(data[i]);
    }
    removeDuplicates(nums);

}

int removeDuplicates(vector<int>& nums) {
    int idx = 1;
    int last_value = nums[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i] != last_value){
            last_value = nums[i];
            nums[idx] = last_value;
            idx++;
        }
    }
    return idx;
}