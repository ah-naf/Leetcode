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
    ListNode* mergeNodes(ListNode* head) {
        head = head -> next;
        ListNode *ans = new ListNode; int sum = 0;
        ListNode *cur = ans;
        while(head) {
            if(head->val == 0) {
                ListNode *temp = new ListNode(sum);
                if(ans == NULL) ans = temp, cur = temp;
                else {
                    cur -> next = temp;
                    cur = temp;
                }
                sum = 0;
            } else {
                sum += head->val;
            }
            head = head -> next;
        }
        return ans -> next;
    }
};