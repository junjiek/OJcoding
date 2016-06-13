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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* prev = dummyHead;
        ListNode* p = head;
        while (p && p->next) {
            ListNode* q = p->next;
            ListNode* n = p->next->next;
            prev->next = q;
            q->next = p;
            p->next = n;
            prev = p;
            p = n;
        }
        return dummyHead->next;
    }
};

int main() {
    Solution s;
    return 0;
}