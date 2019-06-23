#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

/**
 * The newest way:
 *  - Find the peak of the array (Binary search tree)
 *      - Return the value which equals to the target and in the ascent part (SLOPE = UP).
 *  - Find the target in the first part of the array( Ascent part)
 *  - Find the target in the second part of the array( Descent part)
 * 
 * 
 * The original way: 
 *  - Search from the head to the peak O(n)
 *  - Return it if find the target, otherwise, using binary search to find the remain array (Descent array)
 *      - ERROR: access the mountain array too much time.
 *
*/

class MountainArray {
   public:
    int get(int index) {
        if (!(0 <= index && index < nums.size())) {
            cout << "index" << index << "\n"; // For asserting the out of index error
        }
        return nums[index];
    };
    int length() {
        return nums.size();
    };
    vector<int> nums;
    MountainArray() {
        int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82};
        for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
            nums.push_back(data[i]);
        }
    }
};

enum SLOPE {
    UP,
    DOWN
};
map<int, int> table;
int binarySearch(MountainArray &mountainArr, int l, int r, int x, SLOPE S);
int peakBinarySearch(MountainArray &mountainArr, int l, int r, int target);
int findInMountainArray(int target, MountainArray &mountainArr);

int main() {
    //TransferFromArrayToVector
    MountainArray m = MountainArray();
    cout << "\nans: " << findInMountainArray(81, m);
}

int binarySearch(MountainArray &mountainArr, int l, int r, int x, SLOPE S) {
    // cout<<"r "<<r<<"\n";
    // cout<<"l "<<l<<"\n";
    if (r >= l) {
        int mid = l + (r - l) / 2;
        int value = mountainArr.get(mid);
        // cout << "mid: " << mid << "\n";
        if (value == x)
            return mid;
        if (S == UP) {
            if (value > x)
                return binarySearch(mountainArr, l, mid - 1, x, S);
            return binarySearch(mountainArr, mid + 1, r, x, S);
        } else {
            if (value < x)
                return binarySearch(mountainArr, l, mid - 1, x, S);
            return binarySearch(mountainArr, mid + 1, r, x, S);
        }
    }
    return -1;
}

int peakBinarySearch(MountainArray &mountainArr, int l, int r, int target) {
    // cout<<"r "<<mountainArr.get(r)<<"\n";
    // cout<<"l "<<mountainArr.get(l)<<"\n";
    if (r >= l) {
        int mid = l + (r - l) / 2;
        int left = mountainArr.get(mid - 1);
        int center = mountainArr.get(mid);
        int right = mountainArr.get(mid + 1);
        // cout<<"mid ~~~"<<mountainArr.get(mid)<<"\n";
        if (center == target && center > left) {
            return mid;
        }
        // cout << "mid: " << mid << "\n";
        if (center > left && center > right)
            return mid;
        if (center > left)
            return peakBinarySearch(mountainArr, mid, r, target);
        else
            return peakBinarySearch(mountainArr, l, mid, target);
    }
    return -1;
}

int findInMountainArray(int target, MountainArray &mountainArr) {
    int peakIdx, findInRight = -1, findInLeft = -1;
    peakIdx = peakBinarySearch(mountainArr, 0, mountainArr.length() - 1, target);
    // cout<<"peak"<<peakIdx<<"\n";
    if (mountainArr.get(peakIdx) == target) {
        return peakIdx;
    }

    findInLeft = binarySearch(mountainArr, 0, peakIdx - 1, target, UP);
    if (findInLeft == -1)
        return binarySearch(mountainArr, peakIdx, mountainArr.length() - 1, target, DOWN);
    else
        return findInLeft;
    return 0;
}