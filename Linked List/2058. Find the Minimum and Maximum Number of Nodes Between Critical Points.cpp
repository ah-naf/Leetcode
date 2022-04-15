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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ind; int len = 2;
        ListNode *prev = head, *cur = head -> next;
        while(cur) {
            if(cur -> next) {
                ListNode *next = cur -> next;
                int l = prev -> val, r = next -> val, m = cur -> val;
                if(l < m && r < m) ind.push_back(len);
                if(l > m && r > m)  ind.push_back(len);
            }
            len++; prev = cur; cur = cur -> next;
        }
        if(ind.size() < 2) return {-1, -1};
        int mn = INT_MAX, mx = ind.back() - ind[0];
        for(int i=1; i<ind.size(); i++) {
            mn = min(mn, ind[i] - ind[i-1]);
        }
        return {mn, mx};
    }
};
