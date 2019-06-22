#include <iostream>
#include <vector>
using namespace std;
bool canMeasureWater(int x, int y, int z);
int gcd(int a, int b);

/**
 * Q: Whether the third-jug can be measure by the other two jugs?
 * 
 * - Using GCD 
*/


int main() {
    cout << canMeasureWater(0, 0, 1);
}

int gcd(int a, int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    return gcd(b % a, a);
}

bool canMeasureWater(int x, int y, int z) {
    if (z == 0) {
        return true;
    } else if (x == 0 && y == 0) {
        return false;
    } else {
        int maxGcd = gcd(x, y);
        if ((z % maxGcd == 0) && x + y >= z) {
            return true;
        } else {
            return false;
        }
    }
}