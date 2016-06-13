#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
// d[m][n] = d[m-1][n] + d[m][n-1];
// d[i][j] = d[n * i + j];
class Solution {
public:
    int uniquePaths(int m, int n) {
        int* d = new int[m * n + 1];
        // init
        for (int i = 0; i < n; i++)
            d[i] = 1;
        for (int i = 0; i < m; i++)
            d[n * i] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                d[n * i + j] = d[n * (i - 1) + j] + d[n * i + (j - 1)];
            }
        }
        int res = d[n * (m-1) + n-1];
        delete [] d;
        return res;
    }
};
int main() {
    Solution s;
    cout << s.uniquePaths(3, 7);
    return 0;
}