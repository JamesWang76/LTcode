#include <iostream>
#include <vector>
using namespace std;

int candy(vector<int> &ratings);

/**
 * The newest way:
 *  - Go through the array from left to right and right to left.
 *  - We can just consider the UP SLOPE case(ignore the down slope).
 *  - From L ==> R:
 *      - Store the (previous count++) if A[i] < A[i+1]
 *  - From L <== R:
 *      - ans+=max(LR[i], count) 
 * 
 * The original way:
 * - From L ==> R:
 *      - Store the (previous count++) if A[i] < A[i+1]
 * - But it would neglect some specific situation.
 * 
 * TODO:
 * - Fast but it takes too much memory usage.
 */

int main() {
    // [29,51,87,87,72,12] = 12
    // [1,3,2,2,1] = 7
    // [1,3,4,5,2] = 11
    vector<int> x = {29,51,87,87,72,12};
    cout<<candy(x);
}

int candy(vector<int> &ratings) {
    vector<int>LR;
    LR.push_back(1);
    int RLvalue = 1, ans=0;
    for(int i=1;i<ratings.size();i++){
        if(ratings[i] > ratings[i-1]){
            LR.push_back(LR[i-1]+1);
        }else{
            LR.push_back(1);
        }
    }
    ans += max(RLvalue, LR[LR.size()-1]);
    for(int i=ratings.size()-2;i>=0;i--){
        if(ratings[i] > ratings[i+1]){
            RLvalue++;
        }else{
            RLvalue = 1;
        }
        ans += max(LR[i], RLvalue);
    }
    return ans;
}
