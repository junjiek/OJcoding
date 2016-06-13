#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxEndingHere = nums[0], maxSoFar = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            maxEndingHere = max(maxEndingHere + nums[i], nums[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    }
};

int main() {
    Solution s;
    return 0;
}