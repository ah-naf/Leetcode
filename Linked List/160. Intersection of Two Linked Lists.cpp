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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *first = headA, *second = headB;
        int len1 = size(headA), len2 = size(headB);
        if(len1 > len2) {
            for(int i=0; i<(len1-len2); i++) first = first -> next;
        } else {
            for(int i=0; i<(len2-len1); i++) second = second -> next;
        }
        while(first && second) {
            if(first == second) return first;
            first = first -> next;
            second = second -> next;
        }
        return NULL;
    }
    int size(ListNode *list) {
        int len = 0;
        while(list) {
            list = list -> next; len++;
        }
        return len;
    }
};