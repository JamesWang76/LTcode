#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MountainArray {
   public:
    int get(int index) {
        return nums[index];
    };
    int length() {
        return nums.size();
    };
    vector<int> nums;
    MountainArray() {
        int data[] = {2, 3, 4, 7, 5, 1};
        for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
            nums.push_back(data[i]);
        }
    }
};

int binarySearch(MountainArray &mountainArr, int l, int r, int x);
int findInMountainArray(int target, MountainArray &mountainArr);

int main() {
    //TransferFromArrayToVector
    MountainArray m = MountainArray();
    findInMountainArray(7, m);
}

int binarySearch(MountainArray &mountainArr, int l, int r, int x) {
    // cout<<"r "<<r<<"\n";
    // cout<<"l "<<l<<"\n";
    if (r >= l) {
        int mid = l + (r - l) / 2;
        // cout << "mid: " << mountainArr.get(mid) << "\n";
        if (mountainArr.get(mid) == x)
            return mid;
        if (mountainArr.get(mid) < x)
            return binarySearch(mountainArr, l, mid - 1, x);
        return binarySearch(mountainArr, mid + 1, r, x);
    }
    return -1;
}
int findInMountainArray(int target, MountainArray &mountainArr) {
    int peakIdx;
    for (int i = 0; i <= mountainArr.length() - 2; i++) {
        if (target == mountainArr.get(i)) {
            // cout<<i;
            return i;
        }
        if (mountainArr.get(i) > mountainArr.get(i + 1)) {
            peakIdx = i;
            break;
        }
    }
    // cout<<binarySearch(mountainArr, peakIdx+1, mountainArr.length(), target);
    return binarySearch(mountainArr, peakIdx + 1, mountainArr.length(), target);
}