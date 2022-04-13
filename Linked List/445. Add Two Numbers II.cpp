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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1); l2 = reverseList(l2); int c = 0;
        ListNode *ans = NULL;
        while(l1 && l2) {
            int sum = (l1 -> val + l2 -> val + c) % 10;
            c = (l1 -> val + l2 -> val + c) / 10;
            ListNode *temp = new ListNode(sum);
            if(ans == NULL) ans = temp;
            else {
                temp -> next = ans;
                ans = temp;
            }
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1) {
            int sum = (l1 -> val + c) % 10;
            c = (l1 -> val + c) / 10;
            ListNode *temp = new ListNode(sum);
            if(ans == NULL) ans = temp;
            else {
                temp -> next = ans;
                ans = temp;
            }
            l1 = l1 -> next;
        }
        while(l2) {
            int sum = (l2 -> val + c) % 10;
            c = (l2 -> val + c) / 10;
            ListNode *temp = new ListNode(sum);
            if(ans == NULL) ans = temp;
            else {
                temp -> next = ans;
                ans = temp;
            }
            l2 = l2 -> next;
        }
        if(c) {
            ListNode *temp = new ListNode(c);
            if(ans == NULL) ans = temp;
            else {
                temp -> next = ans;
                ans = temp;
            }
        }
        return ans;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode *prev = NULL, *cur = head, *next = head -> next;
        while(next) {
            cur -> next = prev;
            prev = cur;
            cur = next;
            next = next -> next;
        }
        cur -> next = prev;
            prev = cur;
        return prev;
    }
};