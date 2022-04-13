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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = list1;
        while(list2) {
            ListNode *cur = head, *prev, *temp = new ListNode(list2 -> val);
            if(head == NULL) {
                head = temp;
            list2 = list2 -> next;
                continue;
            }
            while(cur && (cur -> val < list2 -> val)) {
                prev = cur; cur = cur -> next;
            }
            if(cur == head) {
                temp -> next = cur;
                head = temp;
            } else {
                temp -> next = prev -> next;
                prev -> next = temp;
            }
            list2 = list2 -> next;
        }
        return head;
    }
};