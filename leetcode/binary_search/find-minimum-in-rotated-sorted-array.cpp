#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = (int)nums.size() - 1;
        while (lo < hi && nums[lo] >= nums[hi]) {
            int mi = (lo + hi) / 2;
            if (nums[mi] > nums[hi]) {
                lo = mi + 1;
            } else if (nums[mi] < nums[lo]){
                hi = mi;
            } else {
                lo ++;
                hi --;
            }
        }
        return nums[lo];
    }
};

int main() {
    Solution s;
    return 0;
}