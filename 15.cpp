#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums);
int binarySearch(vector<int> arr, int l, int r, int x);
void printDoubleArr(vector<vector<int>> x);
int neighborSearch(vector<int> arr, int l, int r);

void printArr(vector<int> x);
/**
 * The better way:
 *      - Using difference between two value (right and left) 
 *          -9,-7,-4,-3,-2,-1,2,5,7,8,11
 *          -9 + 11 => mid: find -2
 *          -9 + 8 => mid: find -2+(11-8) => 1 not found
 *          -9 + 7 => mid: find 1 + (8-7) => find 2
 *          -9 + 5 => mid: find 2 + (7-5) => 4 not found
 *          STOP (UNTIL mid > right);
 * The bad way:
 *      - Using greedy algorithm
 *      - ERROR: Time limit.
 */
  
int main() {
    vector<int> nums;
    int data[] = {-1,-1,-1,0,0,0,1,2,1,1,2};
    for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        nums.push_back(data[i]);
    }
    printDoubleArr(threeSum(nums));
}

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    int i=0, j, lastPositiveValue = -1, lastNegativeValue = 1;
    int complementLowerIdx = 0, tmpIdx, zeroCtr = 1;
    bool zeroCalculated = false;
    while(nums[i]<0){
        if(lastNegativeValue == nums[i]){i++;continue;}
        lastNegativeValue = nums[i];
        complementLowerIdx = 0;
        j=nums.size()-1;
        while(nums[j]>=0 && j > complementLowerIdx){
            if(!zeroCalculated && nums[j] == 0){
                zeroCalculated = true;
                if(nums [j-1] == nums[j-2] == 0){
                    vector<int> zeros;
                    for(i=0;i<3;i++)
                        zeros.push_back(0);
                    ans.push_back(zeros);
                }
            }

            if(lastPositiveValue == nums[j]){
                if(nums[j]==0)zeroCtr++;
                j--;
                continue;
            }
            lastPositiveValue = nums[j];
            if(complementLowerIdx == 0){
                tmpIdx = binarySearch(nums, complementLowerIdx, j-1, -1*(nums[i]+nums[j]));
                if(tmpIdx){
                    complementLowerIdx = tmpIdx;
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[complementLowerIdx]);
                    ans.push_back(tmp);
                    tmp.clear();
                    neighborSearch(nums, complementLowerIdx, j-1);
                }
            }
            
            
            j--;
        }
        i++;
    }
    if(zeroCtr >= 3){
        
    }
    return ans;
}

void printArr(vector<int> x){
    for(int i=0;i<x.size();i++){
        cout<<x[i]<<" ";
    }
    cout<<"\n";
}

void printDoubleArr(vector<vector<int>> x){
    for(int i=0;i<x.size();i++){
        for(int j=0;j<x[i].size();j++){
            cout<<x[i][j]<<" ";
        }cout<<"\n";
    }
    
}

int binarySearch(vector<int> arr, int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }
    return 0;
}

int neighborSearch(vector<int> arr, int l, int r) {
    
}
