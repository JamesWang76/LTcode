#include <iostream>
#include <vector>
#include <string>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
double getMedian(bool odd, vector<int>merge);

vector<int>a;
vector<int>b;


/**
 * Q: Find the median of two subarrays
 * 
 * 1. Using the mergesort concept to merge them into a new array.
 * 2. Stop merge if new array's length equals to the median index.
 */ 

int main(){
    a.push_back(1);
    // a.push_back(3);
    b.push_back(2);
    b.push_back(4);
    findMedianSortedArrays(a, b);
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    double ans;
    int totalSize = nums1.size()+nums2.size();
    int medianIdx;
    vector<int>merge;
    bool odd ;
    if((totalSize%2) == 1){
        odd=true;
        medianIdx = (totalSize+1)/2;
    }else{
        odd=false;
        medianIdx = (totalSize+2)/2;
    }
    int curN1=0, curN2=0;
    while(curN1 < nums1.size() && curN2 < nums2.size()){
        if(nums1[curN1] >= nums2[curN2]){
            merge.push_back(nums2[curN2]);
            curN2++;
        }else{
            merge.push_back(nums1[curN1]);
            curN1++;
        }
        if((curN2 + curN1)==medianIdx){
            ans = getMedian(odd, merge);
        }
    }

    while(curN1 < nums1.size()){
        merge.push_back(nums1[curN1]);
        curN1++;
        if((curN2 + curN1)==medianIdx){
            ans = getMedian(odd, merge);
        }
    }
    while(curN2 < nums2.size()){
        merge.push_back(nums2[curN2]);
        curN2++;
        if((curN2 + curN1)==medianIdx){
            ans = getMedian(odd, merge);
        }
    }
    return ans;
}

double getMedian(bool odd, vector<int>merge){
    if(odd){
        return (double)merge[merge.size()-1];
    }else{
        return (double)(merge[merge.size()-1] + merge[merge.size()-2])/2;
    }
}
