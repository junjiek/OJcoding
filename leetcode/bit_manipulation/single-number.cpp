#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        for (int i = 0; i < nums.size(); i++) {
            num ^= nums[i];
        }
        return num;
        
    }
};

int main() {
    Solution s;
    return 0;
}