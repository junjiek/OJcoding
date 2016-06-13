#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:

    // O(n) time, O(n) space;
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> map;
        RandomListNode* dummyHead = new RandomListNode(0);
        RandomListNode* p = head;
        RandomListNode* q = dummyHead;
        while (p) {
            q->next = new RandomListNode(p->label);
            map[p] = q->next;
            q = q->next;
            p = p->next;
        }
        p = head;
        q = dummyHead->next;
        while (p) {
            q->random = map[p->random];
            p = p->next;
            q = q->next;
        }
        return dummyHead->next;

    }
    // O(n) time, O(1) space;
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* p = head;
        while (p) {
            RandomListNode* q = p->next;
            RandomListNode* m = new RandomListNode(p->label);
            p->next = m;
            m->next = q;
            p = q;
        }
        p = head;
        while (p) {
            p->next->random = p->random ? p->random->next : NULL;
            p = p->next->next;
        }
        p = head;
        RandomListNode* headCopy = head ? head->next : NULL;
        while (p) {
            RandomListNode* copy = p->next;
            p->next = copy->next;
            p = p->next;
            copy->next = p ? p->next : NULL; 

        }
        return headCopy;
    }
};

int main() {
    Solution s;
    return 0;
}