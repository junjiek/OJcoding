#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = (int)digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i] ++;
                return digits;
            }
            digits[i] = 0;
        }
        vector<int> newdigits;
        newdigits.push_back(1);
        for (int i = 0; i < (int)digits.size(); i++) {
            newdigits.push_back(digits[i]);
        }
        return newdigits;
    }
};

int main() {
    Solution s;
    return 0;
}