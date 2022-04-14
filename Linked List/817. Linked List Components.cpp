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
    int numComponents(ListNode* head, vector<int>& nums) {
        map<int, int> m;
        for(auto it: nums) m[it]++;
        int ans = 0;
        while(head) {
            if(m[head->val]) {
                while(head && m[head->val]) {
                    head = head -> next;
                }
                ans++;
            } else {
                head = head -> next;
            }
        }
        return ans;
    }
};
