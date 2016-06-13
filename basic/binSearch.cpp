#include <iostream>

using namespace std;

template <typename T>
static int binSearch(T* A, T const& e, int lo, int hi) {
    while(lo < hi) {
        int mi = (lo + hi) / 2;
        (A[mi] > e) ? hi = mi : lo = mi + 1;
    }
    return lo - 1;

int main() {

    return 0;
}

// 找到插入后的index
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = (int)nums.size();
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            if (nums[mi] < target)
                lo = mi + 1;
            else
                hi = mi;
        }
        return lo;
    }
};