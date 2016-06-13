#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int sign = (x > 0) ? 1: -1;
        x = x * sign;
        int r = 0;
        while (x > 0) {
            if (r > INT_MAX / 10) {
                return 0;
            }
            r = r * 10 + x % 10;
            x /= 10;
        }
        return sign * r;

    }
};

int main() {
    Solution s;
    cout << s.reverse(-100) << endl;
}