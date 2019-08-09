#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals);

/**
 * Find the intervals (It should consider some overlay situation)
 * 
 * - Just consider the tail
 *      - If current tail is smaller than other head
 *      - If current tail is smaller than other tail
 * 
 * - NOTE: How to sort the 2D vector by column
 * 
 * - Fast than 93% and memory usage is 100% !
 */ 


// sort compare function
bool sortCol(vector<int>& v1,
             vector<int>& v2) {
    if (v1[0] > v1[1]) {
        int tmp;
        tmp = v1[0];
        v1[0] = v1[1];
        v1[1] = tmp;
    }
    if (v2[0] > v2[1]) {
        int tmp;
        tmp = v2[0];
        v2[0] = v2[1];
        v2[1] = tmp;
    }
    return v1[0] < v2[0];
}

int main() {
    // int arr[4][2] = {{6, 2}, {13, 1}, {8, 10}, {15, 18}};
    int arr[1][2] = {{1, 4}};
    vector<vector<int>> x;
    vector<int> tmp;
    // 2D transfering from array
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 2; j++) {
            tmp.push_back(arr[i][j]);
        }
        x.push_back(tmp);
        tmp.clear();
    }
    x.clear();
    merge(x);
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.size() == 0){
        return intervals;
    }
    vector<vector<int>> ans;
    vector<int> tmpInterval;
    int i, j;
    const int INTERVAL_SIZE = 2;
    sort(intervals.begin(), intervals.end(), sortCol); 
    tmpInterval.push_back(intervals[0][0]);
    tmpInterval.push_back(intervals[0][1]);

    for(i=1;i<intervals.size();i++){
        for(j=0;j<INTERVAL_SIZE;j++){
            if(tmpInterval[1] < intervals[i][j]){
                if(j==0){
                    ans.push_back(tmpInterval);
                    tmpInterval[0] = intervals[i][0];
                    tmpInterval[1] = intervals[i][1];
                }else{
                    tmpInterval[1] = intervals[i][j];
                }
            }
        }
    }
    ans.push_back(tmpInterval);
    // print 2D array
    for(i=0;i<ans.size();i++){
        for(j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return ans;
}