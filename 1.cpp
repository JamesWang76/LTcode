#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> twoSum(vector<int> nums, int target);

/**
 * Q: Two Sum:
 * 
 * 1. Sort the array first
 * 2. (Target - arr[i]), and using binary search to find the other number.
 * 
 * - Faster than 95%, but the memory usage less than 5%
 *      (The reason that consuming so much memory is duplicating the whole vector, and using the struct to record index and value. )
*/

struct data{
    int value;
    int index;
};

int main(){
    int arr [] = {15, 11, 7, 2};
    vector<int> data;

    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        data.push_back(arr[i]);
    }

    data=twoSum(data, 9);

    for(int i=0;i<data.size();i++)
        cout<<data[i];
}


int binarySearch(vector<struct data>arr, int l, int r, int x, int skipIdx) { 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (arr[mid].value == x && arr[mid].index != arr[skipIdx].index) 
            return mid; 
  
        if (arr[mid].value > x) 
            return binarySearch(arr, l, mid - 1, x, skipIdx); 
  
        return binarySearch(arr, mid + 1, r, x, skipIdx); 
    } 
    return -1; 
} 


bool compareData(struct data i1, struct data i2) { 
    return (i1.value < i2.value); 
} 



vector<int> twoSum(vector<int> nums, int target) {
    vector<int> ans;
    vector<struct data> numsObj;
    for(int i=0;i<nums.size();i++){
        struct data tmp;
        tmp.value = nums[i];
        tmp.index = i;
        numsObj.push_back(tmp);
    }
    sort(numsObj.begin(), numsObj.end(), compareData);

    for(int i=0;i<numsObj.size();i++){
        int res = binarySearch(numsObj, 0, numsObj.size()-1, target-numsObj[i].value, i);
        if(res != -1){
            ans.push_back(numsObj[i].index);
            ans.push_back(numsObj[res].index);
            return ans;
        }
    }
    return ans;
}