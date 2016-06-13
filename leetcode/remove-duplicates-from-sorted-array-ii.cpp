#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int head = 0, cnt = 1;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[head] != nums[i]) {
                nums[++head] = nums[i];
                cnt = 1;
            } else if (cnt <= 1) {
                nums[++head] = nums[i];
                cnt ++;
            }
        }
        return head + 1;
    }
};

int main() {
    Solution s;
    return 0;
}