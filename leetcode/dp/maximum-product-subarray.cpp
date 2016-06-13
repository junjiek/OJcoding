#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
    inline int max3(int x, int y, int z) {
        return max(x, max(y, z));
    }
    inline int min3(int x, int y, int z) {
        return min(x, min(y, z));
    }
public:
    int maxProduct(vector<int>& nums) {
        int maxEndingHere = nums[0], minEndingHere = nums[0], maxSoFar = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            int tmp = maxEndingHere;
            maxEndingHere = max3(maxEndingHere * nums[i], nums[i], minEndingHere * nums[i]);
            minEndingHere = min3(tmp * nums[i], nums[i], minEndingHere * nums[i]);
            maxSoFar = max(maxEndingHere, maxSoFar);
        }
        return maxSoFar;
    }
};

int main() {
    Solution s;
    return 0;
}