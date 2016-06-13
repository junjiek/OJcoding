#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode* list;
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* p = head;
        int n = 0;
        while (p) {
            n ++ ;
            p = p->next;
        }
        list = head;
        return sortedListToBST(0, n-1);
    }
    TreeNode* sortedListToBST(int start, int end) {
        if (start > end) return NULL;
        int mi = (end + start) / 2;
        TreeNode* left = sortedListToBST(start, mi - 1);
        TreeNode* p = new TreeNode(list->val);
        p->left = left;
        list = list->next;
        p->right = sortedListToBST(mi + 1, end);
        return p;
    }
};

int main() {
    Solution s;
    return 0;
}