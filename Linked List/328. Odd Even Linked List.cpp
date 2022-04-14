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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        ListNode *even = NULL, *odd = NULL, *list = head, *curEven = NULL, *curOdd = NULL;
        int len = 0;
        while(list) {
            ListNode *temp = new ListNode(list->val);
            if(len % 2 == 0) {
                if(even == NULL) {
                    even = temp; curEven = temp;
                }
                else {
                    curEven -> next = temp;
                    curEven = curEven -> next;
                }
            } else {
                if(odd == NULL) odd = curOdd = temp;
                else {
                    curOdd -> next = temp;
                    curOdd = temp;
                }
            }
            len++; list = list -> next;
        }
        ListNode *temp = even;
        while(temp -> next != NULL) temp = temp -> next;
        temp -> next = odd;
        return even;
    }
};
