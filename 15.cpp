#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums);
int binarySearch(vector<int> arr, int l, int r, int x, int skipIdx);
void printDoubleArr(vector<vector<int>> x);
void printArr(vector<int> x);

int main() {
    vector<int> nums;
    int data[] = {-2,-2,0,2,4};
    for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        nums.push_back(data[i]);
    }
    printDoubleArr(threeSum(nums));
}

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> negativeArr, positiveArr, tmp;
    int complementValue = 0;
    int i, j, lastNegative=1, lastPositive=-1, zeroCtr=0;
    for (i = 0; i < nums.size(); i++) {
        if (nums[i] >= 0) {
            if(nums[i]==0)zeroCtr++;
            positiveArr.push_back(nums[i]);
        } else {
            negativeArr.push_back(nums[i]);
        }
    }
    if(zeroCtr >=3){
        vector<int> zeros;
        for(i=0;i<3;i++)
            zeros.push_back(0);
        ans.push_back(zeros);
    }
    sort(positiveArr.begin(), positiveArr.end());
    sort(negativeArr.begin(), negativeArr.end());
    printArr(positiveArr);
    printArr(negativeArr);
    cout<<"==========\n";
    for (i = 0; i < positiveArr.size(); i++) {
        if(positiveArr[i] == lastPositive)continue;
        else lastPositive = positiveArr[i];
        for (j = 0; j < negativeArr.size(); j++) {
            if(negativeArr[j] == lastNegative)continue;
            else lastNegative = negativeArr[j];
            if (positiveArr[i] <= (-1 * negativeArr[j])) {
                complementValue = binarySearch(positiveArr, 0, positiveArr.size()-1, -1*(positiveArr[i]+negativeArr[j]), i);
                if(complementValue && complementValue >= i){
                    // cout<<positiveArr[i]<<"\n";
                    // cout<<negativeArr[j]<<"\n";
                    // cout<<complementValue<<"\n";
                    tmp.push_back(negativeArr[j]);
                    tmp.push_back(positiveArr[i]);
                    tmp.push_back(positiveArr[complementValue]);
                    ans.push_back(tmp);
                    tmp.clear();
                };
            }else{
                complementValue = binarySearch(negativeArr, 0, negativeArr.size()-1, -1*(positiveArr[i]+negativeArr[j]), j);
                // cout<<"cv: "<<complementValue<<"\n";
                if(complementValue && complementValue >= j){
                    // cout<<positiveArr[i]<<"\n";
                    // cout<<negativeArr[i]<<"\n";
                    // cout<<complementValue<<"\n";
                    tmp.push_back(negativeArr[j]);
                    tmp.push_back(positiveArr[i]);
                    tmp.push_back(negativeArr[complementValue]);
                    ans.push_back(tmp);
                    tmp.clear();
                };
            }
        }
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

int binarySearch(vector<int> arr, int l, int r, int x, int skipIdx) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x && mid != skipIdx)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x, skipIdx);

        return binarySearch(arr, mid + 1, r, x, skipIdx);
    }
    return 0;
}