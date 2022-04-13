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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *head = list1;
        ListNode *curL = NULL, *curR = list1, *temp = list1;
        
        for(int i=0; i<a; i++) {
            curL = temp;
            temp = temp -> next;
        }
        for(int i=0; i<=b; i++) {
            curR = curR -> next;
        }
        
        ListNode *endList = list2;
        while(endList->next != NULL) endList = endList -> next;
        
        curL -> next = list2; endList -> next = curR;
        return head;
    }
};