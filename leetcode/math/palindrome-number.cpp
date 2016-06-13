#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int xx = x;
        int maskHi = 1;
        while (xx >= 10) {
            xx /= 10;
            maskHi *= 10;
        }
        for (long masklo = 10; maskHi > 0; maskHi /= 10, masklo *= 10) {
            int hi = (x /maskHi) % 10;
            int lo = (x % masklo) / (masklo / 10);
            if (lo != hi)
                return false;
        }
        // while (x != 0) {
        //     int lo = x / maskHi;
        //     int hi = x % 10;
        //     if (lo != hi) return false;
        //     x = (x % maskHi) / 10;
        //     maskHi /= 100;
        // }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(1000000001) << endl;
    return 0;
}