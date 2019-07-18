#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool canTransform(string start, string end);
int main() {
    string start, end;
    start = "XLXRRXXRXX";
    end = "LXXXXXXRRR";

    // RXXLRXRXL
    // XRLXXRRLX
    cout << canTransform(start, end);
}
bool canTransform(string start, string end) {
    int i;
    char propagationChar = '\0';
    bool propagating = false;
    for (i = 0; i < start.size(); i++) {
        if ((start[i] == 'R' && end[i] == 'X') || (start[i] == 'X' && end[i] == 'L')) {
            if (propagating) return false;
            propagating = true;
            if (start[i] == 'R' && end[i] == 'X') {
                propagationChar = 'R';
            } else {
                propagationChar = 'L';
            }
        } else if ((start[i] == 'R' && end[i] == 'L') || (start[i] == 'L' && end[i] == 'R')) {
            return false;
        } else if (start[i] == end[i]) {
            if (start[i] == 'X') continue;
            if (propagating && propagationChar != start[i]) {
                return false;
            }
        } else {
            if ((start[i] == 'X' && end[i] == 'R' && propagating)) {
                propagating = false;
                if (propagationChar != 'R') return false;
            } else if ((start[i] == 'L' && end[i] == 'X' && propagating)) {
                propagating = false;
                if (propagationChar != 'L') return false;
            } else {
                return false;
            }
        }
    }
    if (propagating) return false;
    return true;
}