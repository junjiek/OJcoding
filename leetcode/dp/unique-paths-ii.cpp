#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m = (int)obstacleGrid.size();
        if (m == 0)
            return 0;
        int n = (int)obstacleGrid[0].size();
        int* d = new int[m * n + 1];
        // init
        int init = 1;
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 1)
                init = 0;
            d[i] = init;
        }
        init = 1;
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1)
                init = 0;
            d[n * i] = init;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                d[n * i + j] = obstacleGrid[i][j] ? 0 : d[n * (i - 1) + j] + d[n * i + (j - 1)];
            }
        }
        int res = d[n * (m-1) + n-1];
        delete [] d;
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}