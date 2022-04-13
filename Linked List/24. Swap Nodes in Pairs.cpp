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
    ListNode* swapPairs(ListNode* head) {
        ListNode *list = head;
        while(list && list->next != NULL) {
            int temp = list -> val;
            list -> val = list -> next -> val;
            list -> next -> val = temp;
            list = list -> next -> next;
        }
        return head;
    }
};