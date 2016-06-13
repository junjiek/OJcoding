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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, (int)nums.size());
    }
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
        if (end == start)
            return NULL;
        int mi = (start + end) / 2;
        TreeNode* p = new TreeNode(nums[mi]);
        p->left = sortedArrayToBST(nums, start, mi);
        p->right = sortedArrayToBST(nums, mi + 1, end);
        return p;
    }
};

int main() {
    Solution s;
    return 0;
}