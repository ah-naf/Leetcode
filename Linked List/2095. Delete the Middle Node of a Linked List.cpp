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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *list = head; int len = 0;
        while(list) {
            list = list -> next; len++;
        }
        if(len == 1) return NULL;
        len /= 2;
        ListNode *prev, *cur = head;
        for(int i=0; i<len; i++) prev = cur, cur = cur -> next;
        prev -> next = cur -> next;
        return head;
    }
};
