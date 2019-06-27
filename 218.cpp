#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> getSkyline(vector<vector<int>>& buildings) ;
void printVector(vector<vector<int>>& buildings);

// Have no idea

enum build{
    LEFT=0,
    RIGHT=1,
    HEIGHT=2
};
int row=5, col=3;
struct heightComp {
    template <typename T>
    bool operator()(const T &l, const T &r) const {
        // cout<<l[build::HEIGHT]<<r[build::HEIGHT]<<"\n";
        return l[build::HEIGHT] > r[build::HEIGHT];
    }
};
struct leftComp {
    template <typename T>
    bool operator()(const T &l, const T &r) const {
        // cout<<l[build::LEFT]<<r[build::LEFT]<<"\n";
        return l[build::LEFT] < r[build::LEFT];
    }
};
int main(){
    vector<vector<int>>buildings;
    int arr[5][3] = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    for(int i=0;i<row;i++){
        vector<int>tmp;
        for(int j=0;j<col;j++){
            tmp.push_back(arr[i][j]);
        }
        buildings.push_back(tmp);
    }
    getSkyline(buildings);
}

void printVector(vector<vector<int>>& buildings){
    for(int i=0;i<buildings.size();i++){
        for(int j=0;j<buildings[i].size();j++){
            cout<<buildings[i][j]<<" ";
        }
        cout<<"\n";
    }
}

vector<vector<int>> getOverlap(vector<vector<int>>& buildings){
    vector<vector<int>> overlapBuilds;
    vector<int> group;
    vector<pair<int, int>>xy;
    int heapArr[buildings.size()] , heapSize=0;
    memset(heapArr, 0, buildings.size()*sizeof(int));
    for(int i=0;i<buildings.size();i++){
        xy.push_back(pair<int, int>(buildings[i][build::LEFT], i));
        xy.push_back(pair<int, int>(buildings[i][build::RIGHT], i));
    }
    sort(xy.begin(), xy.end());
    for(int i=0;i<xy.size();i++){
        if(heapArr[xy[i].second] == 0){
            heapArr[xy[i].second]++;
            heapSize++;
        }else{
            heapArr[xy[i].second] = -1;
            heapSize--;
            group.push_back(xy[i].second);
        }
        if(heapSize == 0){
            overlapBuilds.push_back(group);
            group.clear();
        }
    }

    return overlapBuilds;
}



vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<vector<int>>points, overlapBuildGroups;
    overlapBuildGroups = getOverlap(buildings);
    int minHeight = 0;
    // printVector(overlapBuildGroups);

    
    for(int run=0;run<overlapBuildGroups.size();run++){
        int maxRight = INT_MAX;
        cout<<"..... New Run ....."<<"\n";
        vector<vector<int>> overlapBuild;
        for(int j=0;j<overlapBuildGroups[run].size();j++){
            int buildIndex = overlapBuildGroups[run][j];
            overlapBuild.push_back(buildings[buildIndex]);
        }
        sort(overlapBuild.begin(), overlapBuild.end(), leftComp());
        for(int i=0;i<overlapBuild.size();i++){
            if(overlapBuild[i][build::HEIGHT] > minHeight){
                minHeight = overlapBuild[i][build::HEIGHT];
            }
        }
        printVector(overlapBuild);
    }
    return points;
}