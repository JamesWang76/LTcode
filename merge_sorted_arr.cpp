#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

int main(){
    int data[] = {0, 0, 0, 0, 0};
    int data2[] = {7, 9};
    vector<int> nums, nums2;
    for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        nums.push_back(data[i]);
    }
    for (int i = 0; i < (sizeof(data2) / sizeof(data2[0])); i++) {
        nums2.push_back(data2[i]);
    }
    merge(nums, 3, nums2, 2);
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int idx1=0, idx2=0;

    while(idx1 < m && idx2 < n){
        while(nums1[idx1] <= nums2[idx2] && idx1 < m){
            idx1++;
        }

        if(idx1 == m)break;

        int j = nums1.size()-2;

        while(j >= idx1){
            nums1[j+1] = nums1[j];
            j--;
        }

        nums1[idx1] = nums2[idx2];
        idx1++;
        idx2++;
        m++;
    }

    while(idx2 < nums2.size()){
        nums1[idx1] = nums2[idx2];
        idx1++;
        idx2++;
    }
}