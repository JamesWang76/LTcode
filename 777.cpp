#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * Return two string is the same or not
 *      - The sub-string "XL" could be replaced to "LX", "XR" -> "RX"
 * 
 * The better way:
 *      - Using the stack concept to solve it.
 *      - Left stack and Right stack
 *          1. XX  => means I create the 2 space for left stack
 *             LL
 *          2. LL  => means there are two "left elements" ready to push into the "left stack"
 *             XX
 *                   EX: 
 *                      XXX(LL)XX(RR)X
 *                      (LL)XXXXXX(RR)
 *          3. L   => means there is a wall blocking the "right elements" ready to insert into the stack
 *             L
 *                   EX:
 *                      RRLXX
 *                      XXLRR
 * 
 *      - Return false if the stack size isn't enough
 * 
 * The bad way:
 *      - Handle the all possible cases
 */ 

bool canTransform(string start, string end);
int main() {
    string start, end;
    start = "LLR";
    end =   "RRL";
    cout << canTransform(start, end);
}
bool canTransform(string start, string end) {
    int i;
    int right=0, left=0;
    for (i = 0; i < start.size(); i++) {
        if(right < 0 || left < 0)return false;
        if(start[i] == 'X' && end[i]=='L')left++;
        else if(start[i] == 'L' && end[i]=='X') left--;
        else if(start[i] == 'R' && end[i]=='X') right++;
        else if(start[i] == 'X' && end[i]=='R') right--;
        else if(start[i] == end[i]){
            if(start[i] == 'X')continue;
            if(start[i] == 'R' && left > 0)return false;
            if(start[i] == 'L' && right > 0)return false;
        }else{
            return false;
        }
    }
    return ((right==0)&&(left==0));
}