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
    int pairSum(ListNode* head) {
        ListNode *list = NULL, *cur, *it = head;
        while(it) {
            ListNode *temp = new ListNode(it->val);
            if(list == NULL) list = temp, cur = temp;
            else {
                cur -> next = temp;
                cur = cur -> next;
            }
            it = it -> next;
        }
        ListNode *rev = reverse(list);
        int sum = 0;
        while(head) {
            sum = max(sum, head->val+rev->val);
            head = head -> next;
            rev = rev ->next;
        }
        return sum;
    }
    ListNode* reverse(ListNode *head) {
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