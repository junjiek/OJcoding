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
public:
    bool isBalanced(TreeNode* root) {
        return maxDepth(root) != -1;
    }
    int maxDepth(TreeNode* p) {
        if (p == NULL) return 0;
        int L = maxDepth(p->left);
        if (L == -1)
            return -1;
        int R = maxDepth(p->right);
        if (R == -1)
            return -1;
        if (L - R <= 1 && L - R >= -1)
            return max(L, R) + 1;
        return -1;
    }
};

int main() {
    Solution s;
    return 0;
}