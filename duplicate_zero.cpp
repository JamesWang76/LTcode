#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void duplicateZeros(vector<int>& arr);



int main(){
    vector<int> nums;
    int data[] = {1,0,2,3,0,4,5,0};
    for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        nums.push_back(data[i]);
    }
    duplicateZeros(nums);
}

void duplicateZeros(vector<int>& arr) {
    int shift[arr.size()];
    int shift_bias = 0;

    for(int i=0;i<arr.size();i++){
        shift[i] = shift_bias;
        if(arr[i] == 0){
            shift_bias++;
        }
    }
    for(int i=arr.size()-1;i>=0;i--){
        if(i + shift[i] < arr.size()){
            swap(arr[i], arr[i+shift[i]]);
        }else{
            arr[i] = 0;
        }
    }
}