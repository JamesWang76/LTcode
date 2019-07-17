#include <iostream>
#include <vector>
using namespace std;
int canCompleteCircuit(vector<int>& gas, vector<int>& cost);

int main(){
    int data[] = {6,1,4,3,5};
    int data2[] = {3,8,2,4,2};
    vector<int > nums;
    vector<int > nums2;
    // 3 -4 -2 -3 0 
    //       2  1 4 7 0
    for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        nums.push_back(data[i]);
    }
    for (int i = 0; i < (sizeof(data2) / sizeof(data2[0])); i++) {
        nums2.push_back(data2[i]);
    }
    cout<<canCompleteCircuit(nums, nums2);
}
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int firstPositiveIdx = -1, sum=0;
    bool positiveHead = true;
    for(int i=0;i<gas.size();i++){
        sum += (gas[i] - cost[i]);
        cout<<(gas[i] - cost[i])<<" ";
        if((gas[i] - cost[i]) >= 0 && positiveHead){
            firstPositiveIdx = i;
            positiveHead = false;
        }else{
            positiveHead = true;
        }
    }
    if(sum < 0)return -1;
    else return firstPositiveIdx;
}