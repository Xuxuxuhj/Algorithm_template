#include <vector>
using namespace std;

int search(const vector<int>& nums, int num) {
    int l = 0, r = nums.size();
    while (l < r) {
        int mid = l + r >> 1;
        if (nums[mid] < num) {
            l = mid + 1;
        } else if (nums[mid] > num) {
            r = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}