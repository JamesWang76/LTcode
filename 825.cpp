#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
/**
 * Find how many numbers meet the rules.
 * 
 * - Sort it at the first.
 * - Start from the index=1 and find all the values smaller than it.
 * 
 * TODO:
 *  Too slow, IMPROVE IT
 *  - Binary search to find the lower value(x/2 + 7) and minus it by current index value(x).
*/

int numFriendRequests(vector<int>& ages);

int main() {
    int data[] = {101,56,69,48,30};
    vector<int>nums;
    for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        nums.push_back(data[i]);
    }
}

int numFriendRequests(vector<int>& ages) {
    int ctr=0;
    sort(ages.begin(), ages.end());
    for(int i=1;i<ages.size();i++){
        for(int j=i-1;j>=0;j--){
            int big=ages[i], small=ages[j];
            if((0.5*big+7) >= (double)small)
                break;
            if(big>100 && small < 100)
                break;
            ctr++;
        }
    }
    return ctr;
}
