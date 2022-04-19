class MyHashSet {
public:
    ListNode *head;
    MyHashSet() {
        head = NULL;
    }
    
    void add(int key) {
        ListNode *list = head;
        while(list) {
            if(list -> val == key) return;
            list = list -> next;
        }
        ListNode *temp = new ListNode(key);
        temp -> next = head;
        head = temp;
    }
    
    void remove(int key) {
        if(head && head -> val == key) {
            ListNode *temp = head;
            head = head -> next;
            delete temp;
            return;
        } 
        ListNode *prev = NULL, *cur = head;
        while(cur) {
            if(cur -> val == key) {
                prev -> next = cur -> next;
                ListNode *temp = cur;
                cur = cur -> next;
                delete temp;
                return;
            }
            prev = cur; 
            cur = cur -> next;
        }
    }
    
    bool contains(int key) {
        ListNode *cur = head;
        while(cur) {
            if(cur -> val == key) return true;
            cur = cur -> next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
