#include <iostream>
#include <vector>
#include <string>
using namespace std;
int reverse(int x);

/**
 * Q: Reverse the number
 * 
 * 1. Store each digit into a vector
 * 2. Check if the sum is overflow
 * 
 * - How to check the overflow case?
 *      1. sign bit is different after summation
 *          -> Counter example: 1534236469
 *             It is overflow but the sign bit of the reverse number is same as the orignal number's.
 */ 

int main(){
    int res = reverse(1534236469);
    cout<<res;
}

int reverse(int x) {
    vector<int>digit;
    int orig_sign = ((unsigned int)x) >> 31;
    int length = 0;

    while(x != 0){
        digit.push_back(x%10);
        x /= 10;
        length++;
    }

    int sum = 0;
    long pos = 1;


    unsigned int sign_bit;

    // // I think it must has another better way to check the overflow.
    // if(length==10 && ((digit[0]>2) || (digit[0]<-2))){
    //     return 0;
    // }

    for(int i=digit.size()-1;i>=0;i--){
        cout<<sum + pos*digit[i]<<endl;
        sign_bit = (sum + (unsigned int)pos*digit[i]) >> 31;
        if (sign_bit != orig_sign)
            return 0;
        
        // 2147483647
        sum += pos*digit[i];
        pos *= 10;
    }
    return sum;

        
}