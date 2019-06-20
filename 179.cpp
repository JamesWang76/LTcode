#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
string largestNumber(vector<int> &nums);
string getStringVec(int maxDigit, vector<int> &nums);
vector<pair<int, int>> dataInfo;

int main() {
    vector<int> x = {31, 30, 34499, 15, 97};
    // 31131
    // 31311
    largestNumber(x);
}

string largestNumber(vector<int> &nums) {
    int maxDigit = 0;
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
    return getStringVec(maxDigit, nums);
}

string getStringVec(int maxDigit, vector<int> &nums) {
    vector<pair<string, int>> stringVec;
    string ans;
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
    return ans;
}