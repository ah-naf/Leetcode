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
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode *next = head -> next;
        while(next) {
            if(next -> val == INT_MIN) return true;
            next -> val = INT_MIN;
            head = head -> next;
            next = next -> next;
        }
        return false;
    }
};