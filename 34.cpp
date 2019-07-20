#include <iostream>
#include <vector>
using namespace std;

/**
 * Find a section equals to the target value
 * 
 * - Modify the binary search algorithm to meet the question
 * 
 * - Better way:
 *      - Run binary search twice time for finding the lower/upper index
 *      - Lower bound: If it exists a mid index, and if its left element is target as well, then keep search left part (So this mid index is the new r) and vice versa
 * 
 * - The bad way :
 *      - Using binary search firstly, get the index and "expand" the head and tail if the neighbor equals to the target too.
 * 
 * Faster than 88%
 */ 


vector<int> searchRange(vector<int>& nums, int target);
int binarySearch(vector<int>& arr, int l, int r, int x, bool left);

int main(){
    vector<int> nums;
    int target=6;
    int data[] = {1};
    for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        nums.push_back(data[i]);
    }
    searchRange(nums, target);
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans;
    ans.push_back(binarySearch(nums, 0, nums.size(), target, true));
    ans.push_back(binarySearch(nums, 0, nums.size(), target, false));
    return ans;
}

int binarySearch(vector<int>& arr, int l, int r, int x, bool left) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x){
            if(left){
                if(mid == 0)return mid;
                else if(arr[mid-1] == x){
                    return binarySearch(arr, l, mid - 1, x, left);
                }
            }else{
                if(mid == arr.size()-1)return mid;
                else if(arr[mid+1] == x){
                    return binarySearch(arr, mid+1, r, x, left);
                }
            }
            return mid;
        }
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x, left);
        return binarySearch(arr, mid + 1, r, x, left);
    }
    return -1;
}