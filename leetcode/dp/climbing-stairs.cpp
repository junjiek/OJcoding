#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
// d[n] = d[n-1] + d[n-2];
// d[1] = 1; d[2] = 2;

class Solution {
public:
    int climbStairs(int n) {
        int* d = new int[n+1];
        d[1] = 1;
        d[2] = 2;
        for (int i = 3; i <= n; i ++) {
            d[i] = d[i-1] + d[i-2];
        }
        int res = d[n];
        delete [] d;
        return res;
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(6) << endl;
    return 0;
}