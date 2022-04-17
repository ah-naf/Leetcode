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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode *list = head;
        while(list) {
            len++; list = list -> next;
        }
        cout<<len<<endl;
        int total = len / k, extra = len % k;
        vector<ListNode*> ans;
        for(int i=0; i<k; i++) {
            ListNode *newList = NULL, *cur = NULL;
            for(int j=0; j<total+(extra ? 1 : 0) && head; j++) {
                ListNode *temp = new ListNode(head->val);
                if(newList == NULL) {
                    newList = temp; cur = temp;
                } else {
                    cur -> next = temp;
                    cur = temp;
                }
                head = head -> next;
            }
            if(extra) extra--;
            ans.push_back(newList);
        }
        return ans;
    }
};
