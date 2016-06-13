#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int maxSum;
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        findMax(root);
        return maxSum;
    }
    int findMax(TreeNode* p) {
        if (p == NULL) return 0;
        int L = findMax(p->left);
        int R = findMax(p->right);
        maxSum = max(L + R + p->val, maxSum);
        int ret = p->val + max(L, R);
        return ret > 0 ? ret : 0;
    }
};

int main() {
    Solution s;
    return 0;
}