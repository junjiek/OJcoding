#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int head = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i])
                swap(nums[head ++], nums[i]);
        }
    }
};

int main() {
    Solution s;
    return 0;
}