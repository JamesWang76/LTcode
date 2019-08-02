#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> ) ;
struct Node{
    int lastNodeIdx=0;
    int ctr=1;
};

int main(){
    int data[] = {2,5,10,11,110};
    vector<int> nums;
    for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        nums.push_back(data[i]);
    }
    largestDivisibleSubset(nums);
}

vector<int> largestDivisibleSubset(vector<int> nums) {
    sort(nums.begin(), nums.end());
    vector<int> x;
    int maxSize = 1;
    int maxNodeIdx = 1;
    int i,j;
    Node arr [nums.size()];
    arr[0].ctr=1;
    arr[0].lastNodeIdx=0;

    for(i=0;i<nums.size()-1;i++){
        for(j=i+1;j<nums.size();j++){
            if((nums[j] % nums[i] == 0) && (arr[i].ctr+1 > arr[j].ctr)){
                arr[j].ctr = arr[i].ctr+1;
                arr[j].lastNodeIdx = i;
                maxSize++;
                maxNodeIdx = j;
            }
        }
    }

    for(int k=0;k<nums.size();k++){
        cout<<arr[k].ctr<<" "<<arr[k].lastNodeIdx<<"\n";
    }
        cout<<maxSize<<"\n";
        cout<<maxNodeIdx<<"\n";


    // Node arr [nums.size()];


    return x;

}