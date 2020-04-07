#include <iostream>
int reachNumber(int target);
/**
 * Find the maximum combination of numbers to reach the target.
 * - ex: target: 7
 *      => start from 1 and sum up the numbers until bigger than target
 *      => 1+2+3+4 = 10
 *      => 10 - 7 = 3, and 3 isn't even, so keep increasing until (sum-target) is even.
 *      => 1+2+3+4+5 = 15, 15-7=8, so answer is '5'
 * - [ Correctness ]
 *      => the diff. between target and sum must be an even num
 *          => 1+2+3+4 = 10 (sum)
 *          => 1+2-3+4 = 4 (target)
 *          => sum - target = 2 * num, where 1 <= num <= 4
 */

using namespace std;
int main() {
    int target = 7;
    int res = reachNumber(target);
}

int reachNumber(int target) {
    long long ctr = 0, sum = 0, t, r;
    if (target < 0)
        target *= -1;
    while (true) {
        sum += ctr;
        if (((sum - target) % 2 == 0) && (sum >= target)) {
            break;
        }
        ctr++;
    }
    return ctr;
}