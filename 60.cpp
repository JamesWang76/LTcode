#include <iostream>
#include <vector>
using namespace std;
string getPermutation(int n, int k);

/**
 * Get the assinged index value of the permutation list (lexicographical order)
 * 
 * - Record the factorial value (for decomposition)
 * - k devides factorial value (from the biggest to the smallest) and get the quotient
 * - Swap the (index=quotient) value 
 * 
 *      Ex: string=1234 , find index=9
 *          1. 9-1=8 (aliasing)
 *          2. 8 / 3! = 1, means move string[1] into ans(So string = 134, ans=2) 
 *          3. 2 / 2! = 1, means move string[1] into ans(string = 14, ans=23) don't forget to add the remain char
 *             => 8 = (1,1,0) respect to (3!, 2!, 1!)
 *      
 *      Ex: string=1234 , find index=14
 *          1. 14-1=13 (aliasing)
 *          2. 13 / 3! = 2, means move string[2] into ans(So string = 124, ans=3) 
 *          3. 1 / 2! = 0, means move string[0] into ans(string = 24, ans=31)
 *          4. 1 / 1! = 1, means move string[1] into ans(string = 2, ans=314) don't forget to add the remain char
 *             => 14 = (2,0,1) respect to (3!, 2!, 1!)
 * 
 * Faster than 100%!
 */         

int main(){
    int n=4, k=14;
    cout<<getPermutation(n, k);
}

string getPermutation(int n, int k) {
    int factorial = 1, factorialCtr=1, i;
    string origin, ans;
    int factorArr [n];
    for(i=1;i<=n;i++){
        origin += (i+'0');
        factorial *= factorialCtr;
        factorArr[i-1] = factorial;
        factorialCtr++;
    }
    k--;
    if(k==0)return origin;
    for(i=n-2;i>=0;i--){
        int getIdx;
        getIdx = k/factorArr[i];
        k = k%factorArr[i];
        ans += origin[getIdx];
        origin.erase(getIdx,1);
        cout<<getIdx<<"~~\n";
    }
    ans += origin;
    return ans;
}