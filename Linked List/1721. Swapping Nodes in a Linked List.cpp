/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *first = head, *last = head;
        int len = 0;
        while(first) len++, first = first -> next;
        first = head;
        for(int i=0; i<k-1; i++) {
            first = first -> next;
        }
        for(int i=0; i<len-k; i++) last = last -> next;
        int temp = last -> val;
        last -> val = first -> val;
        first -> val = temp;
        return head;
    }
};