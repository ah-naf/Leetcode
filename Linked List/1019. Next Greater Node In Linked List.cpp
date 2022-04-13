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
    vector<int> nextLargerNodes(ListNode* head) {
        head = reverse(head);
        stack<int> s;
        vector<int> ans; 
        while(head) {
            if(s.empty()) {
                ans.push_back(0);
                s.push(head->val);
            } else {
                while(!s.empty() && s.top() <= head -> val) s.pop();
                if(s.empty()) {
                    ans.push_back(0);
                } else {
                    ans.push_back(s.top());
                }
                s.push(head -> val);
            }
            head = head -> next;
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
    
    ListNode *reverse(ListNode* head) {
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