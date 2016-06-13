#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    // DFS
    // int minDepth(TreeNode* root) {
    //     if (root == NULL) return 0;
    //     if (root->left == NULL) return 1 + minDepth(root->right);
    //     if (root->right == NULL) return 1 + minDepth(root->left);
    //     return min(minDepth(root->right), minDepth(root->left)) + 1;
    // }
    // BFS
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<TreeNode*> pq;
        int depth = 1;
        pq.push(root);
        TreeNode* rightMost = root;
        while (!pq.empty()) {
            TreeNode* p = pq.front();
            pq.pop();
            if (p->left == NULL && p->right == NULL) break;
            if (p->left)
                pq.push(p->left);
            if (p->right)
                pq.push(p->right);
            if (p == rightMost) {
                depth ++ ;
                rightMost = (p->right) ? p->right : p->left;
            }
        }
        return depth;
    }
};
int main() {
    Solution s;
    return 0;
}