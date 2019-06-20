#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
string largestNumber(vector<int> &nums);
string getStringVec(int maxDigit, vector<int> &nums, vector<pair<int, int>> dataInfo);

struct comp {
    template <typename T>
    bool operator()(const T &l, const T &r) const {
        return l > r;
    }
};

int main() {
    vector<int> x = {10, 2};
    // 31131
    // 31311
    cout << largestNumber(x);
}

string largestNumber(vector<int> &nums) {
    int maxDigit = 0;
    vector<pair<int, int>> dataInfo;
    for (int i = 0; i < nums.size(); i++) {
        int tmpDigit = 0;
        int tmpValue = nums[i];
        while (tmpValue != 0) {
            tmpValue /= 10;
            tmpDigit++;
        }
        pair<int, int> tmpData;
        tmpData.first = nums[i];
        tmpData.second = tmpDigit;
        dataInfo.push_back(tmpData);
        if (tmpDigit > maxDigit)
            maxDigit = tmpDigit;
    }
    return getStringVec(maxDigit, nums, dataInfo);
}

string getStringVec(int maxDigit, vector<int> &nums, vector<pair<int, int>> dataInfo) {
    vector<pair<string, int>> stringVec;
    string ans = "";
    for (int i = 0; i < nums.size(); i++) {
        // cout<<dataInfo[i].first<<" "<<dataInfo[i].second<<"\n";
        string x = to_string(dataInfo[i].first);
        int q, rmd;
        q = maxDigit / dataInfo[i].second;
        rmd = maxDigit % dataInfo[i].second;
        for (int i = 0; i < q - 1; i++) {
            x += x;
        }
        for (int i = 0; i < rmd; i++) {
            x += x[i];
        }
        pair<string, int> tmpData;
        tmpData.first = x;
        tmpData.second = dataInfo[i].first;
        stringVec.push_back(tmpData);
    }
    sort(stringVec.begin(), stringVec.end(), comp());
    for (int i = 0; i < stringVec.size(); i++) {
        ans += to_string(stringVec[i].second);
    }
    return ans;
}