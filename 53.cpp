#include <iostream>
#include <vector>
using namespace std;
int maxSubArray(vector<int>& nums);


int main(){
    vector<int> nums;
    int data[] = {-2,1,-3,4,-1,2,1,-5,4};
    for (unsigned int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        nums.push_back(data[i]);
    }
    int a = maxSubArray(nums);
    cout<<"\n"<<a;
}


int maxSubArray(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    int* max_sum = (int*) malloc(nums.size() * sizeof(int));
    int max_value = nums[0];
    max_sum[0] = nums[0];

    for(unsigned int i=1;i<nums.size();i++){
        if(max_sum[i-1] + nums[i] > nums[i]){
            max_sum[i] = max_sum[i-1] + nums[i];
        }else{
            max_sum[i] =  nums[i];
        }
        if(max_value < max_sum[i])max_value = max_sum[i];
    }
    return max_value;
}
