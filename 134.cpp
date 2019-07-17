#include <iostream>
#include <vector>
using namespace std;
int canCompleteCircuit(vector<int>& gas, vector<int>& cost);
void printDiff(vector<int>& gas, vector<int>& cost);

/**
 * Given a rotate array, and find the start index to make all of the prefix elements are positve
 * 
 * - Build the prefix sum array, and record the minimum value of them
 * - Make sure that the all elements summation is >= 0, and the answer is the minimum value's index + 1
 *      - Ex: [3] -4 -2 -3 0   -----> startIdx=0, minValue=-4, index=1
 *      -> +4) 7   0 [2] 1 4   -----> +4 MEANS startIdx=2, minValue=0  [imporatant]
 *
 * Faster than 99%
 */ 

int main(){
    int data[] = {3, 0, 14, 0, 39};
    int data2[] = {0,10,0,29,0};
    vector<int > nums;
    vector<int > nums2;
    for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        nums.push_back(data[i]);
    }
    for (int i = 0; i < (sizeof(data2) / sizeof(data2[0])); i++) {
        nums2.push_back(data2[i]);
    }
    cout<<canCompleteCircuit(nums, nums2);
    // printDiff(nums, nums2);
}

void printDiff(vector<int>& gas, vector<int>& cost){
    vector<int> prefixSum;
    int sum=0;
    for(int i=0;i<gas.size();i++){
        cout<<gas[i]-cost[i]<<" ";
        sum += gas[i]-cost[i];
        prefixSum.push_back(sum);
    }cout<<"\n";
    for(int i=0;i<gas.size();i++){
        cout<<prefixSum[i]<<" ";
    }    
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int firstPositiveIdx = -1, sum=0, minPrefixSum=INT_MAX, minIdx=0;
    bool positiveHead = true;
    vector<int> prefixSum;
    for(int i=0;i<gas.size();i++){
        sum += (gas[i] - cost[i]);
        if(minPrefixSum > sum){
            minPrefixSum = sum; 
            minIdx = i;
        } 
        prefixSum.push_back(sum);
    }
    if(sum < 0)return -1;
    else return (minIdx+1)%gas.size();
}