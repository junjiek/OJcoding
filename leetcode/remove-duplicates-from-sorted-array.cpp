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
        int head = 0;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[head] != nums[i])
                nums[++head] = nums[i];
        }
        // cout << head + 1 << endl;
        return head + 1;
    }
};
int main() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);

    v.push_back(3);
    Solution s;
    s.removeDuplicates(v);
    return 0;
}