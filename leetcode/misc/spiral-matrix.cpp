#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> v;
        int m = matrix.size();
        if (m == 0)
            return v;
        int n = matrix[0].size();
        int row = 0, col = -1;
        while (true) {
            for (int i = 0; i < n; ++i) {
                v.push_back(matrix[row][++col]);
            }
            if (--m == 0) break;
            for (int i = 0; i < m; ++i) {
                v.push_back(matrix[++row][col]);
            }
            if (--n == 0) break;
            for (int i = 0; i < n; ++i) {
                v.push_back(matrix[row][--col]);
            }
            if (--m == 0) break;
            for (int i = 0; i < m; ++i) {
                v.push_back(matrix[--row][col]);
            }
            if (--n == 0) break;
        }
        return v;
    }
};

int main() {
    vector<int> v;
    v.push_back(6);

    v.push_back(7);

    v.push_back(9);
    vector<vector<int> > m;
    m.push_back(v);
    Solution s;
    vector<int> res = s.spiralOrder(m);
    for (int i = 0; i <res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}