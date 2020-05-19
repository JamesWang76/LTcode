#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int minSteps(int n);


/**
 * Find the minimum steps to create the target string.
 * 
 * - How to solve it with DP?
 * - Using the factorization. Start at index=3 and build the table, factorizing each number and store the min step.
 * 
 *  i = new index, j = i's factor.
 *  if(table[j] + table[i/j] < minSteps)
        minSteps = table[j] + table[i/j];
 *
 *  speed 31.8% / mem 100%
 */ 

int main(){
    minSteps(1000);
}

int minSteps(int n) {
    int minSteps;
    int table [1001] = {0};
    table[1] = 0;
    table[2] = 2;

    for(int i=3;i<=n;i++){
        for(int j=1;j <= i/2;j++){
            if(j == 1){
                minSteps = i;
                continue;
            }
            if((i % j) == 0){
                if(table[j] + table[i/j] < minSteps)
                    minSteps = table[j] + table[i/j];
            }
        }
        table[i] = minSteps;
    }
    return table[n];
}
