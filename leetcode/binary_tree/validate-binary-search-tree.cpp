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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         return valid(root, NULL, NULL);
//     }
//     bool valid(TreeNode* p, TreeNode* low, TreeNode* high) {
//         if (p == NULL)
//             return true;
//         return (!low || p->val > low->val) &&
//                (!high || p->val < high->val) &&
//                valid(p->left, low, p) &&
//                valid(p->right, p, high);
//     }
// };

class Solution {
public:
    TreeNode* prev;
    bool isValidBST(TreeNode* root) {
        prev = NULL;
        return isMonoIncreasing(root);
    }
    bool isMonoIncreasing(TreeNode* p) {
        if (p == NULL) return true;
        if (isMonoIncreasing(p->left)) {
            if (prev != NULL && prev->val >= p->val) return false;
            prev = p;
            return isMonoIncreasing(p->right);
        }
        return false;
    }
    
};



int main() {
    Solution s;
    TreeNode* root = new TreeNode(0);
    root->left = NULL;
    root->right = new TreeNode(-1);
    cout << s.isValidBST(root) << endl;
    return 0;
}