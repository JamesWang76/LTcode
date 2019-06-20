#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
string largestNumber(vector<int> &nums);
string getStringVec(int maxDigit, vector<int> &nums, vector<pair<int, int>> dataInfo);

/**
 * The newest way:
 *  - Compare the combine-string value and sort it
 *      - LR vs. RL, which L=left word and R=right word
 *      - L=12, R=34 => LR=1234
 * 
 * The original way: 
 *  - Get the largest digit of all words -> maxDigit
 *  - Fill every word to meet the maxDigit by repeat it
 *      - (12, 55527, 432) => (12121, 55527, 43243)
 *  - Bug: (121, 12) => (121, 121)
*/

struct comp {
    template <typename T>
    bool operator()(const T &l, const T &r) const {
        string LR, RL;
        LR = to_string(l)+to_string(r);
        RL = to_string(r)+to_string(l);
        cout<<"LR: "<<LR<<"\n";
        cout<<"RL: "<<RL<<"\n";
        if(LR > RL){
            return true;
        }else{
            return false;
        }
    }
};

int main() {
    vector<int> x = {3,30,34,5,9};
    cout << largestNumber(x);
}

string largestNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end(), comp());
    string ans="";
    for(int i=0;i<nums.size();i++){
        ans += to_string(nums[i]);
    }
    while((ans[0] == '0') && ans.size() > 1){
        ans = ans.substr(1, ans.size());
    }
    return ans;
}