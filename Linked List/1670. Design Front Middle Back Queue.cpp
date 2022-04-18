class Node {
public:
    int val;
    Node *next, *prev;
    Node(int value = 0) {
        val = value;
        next = NULL; prev = NULL;
    }
};

Node *head = NULL, *tail = NULL;

class FrontMiddleBackQueue {
public:
    int len;
    FrontMiddleBackQueue() {
        head = NULL;
        tail = NULL;
        len = 0;
    }
    
    void pushFront(int val) {
        Node *temp = new Node(val);
        if(head == NULL) {
            head = temp; tail = temp;
        } else {
            temp -> next = head;
            head -> prev = temp;
            head = temp;
        }
        len++;
    }
    
    void pushMiddle(int val) {
        int tempLen = (len) / 2;
        Node *temp = new Node(val);
        if(head == NULL) {
            head = tail = temp; len++;
            return;
        }
        if(tempLen == 0) {
            temp -> next = head;
            head -> prev = temp;
            head = temp; len++;
            return;
        }
        Node *prev = NULL, *cur = head;
        for(int i=0; i<tempLen; i++) {
            prev = cur;
            cur = cur -> next;
        }

        prev -> next = temp;
        temp -> prev = prev;
        temp -> next = cur;
        if(cur) cur -> prev = temp;
        len++;
    }
    
    void pushBack(int val) {
        Node *temp = new Node(val);
        if(head == NULL) {
            head = temp; tail = temp;
        } else {
            if(tail) tail -> next = temp;
            temp -> prev = tail;
            tail = temp;
        }
        len++;
    }
    
    int popFront() {
        if(len == 0) return -1;
        len--;
        int val = head -> val;
        if(len == 0) {
            // delete head; delete tail;
            head = tail = NULL;
            return val;
        }
        Node *temp = head;
        head = head -> next; 
        if(head) head -> prev = NULL;
        delete temp;
        return val;
    }
    
    int popMiddle() {
        if(len == 0) return -1;
        int tempLen = (len + 1) / 2;
        len--;
        if(tempLen == 0) {
            int val = head -> val;
            // delete head; delete tail;
            head = tail = NULL;
            return val;
        }
        if(tempLen == 1) {
            int val = head -> val;
            head = head -> next;
            return val;
        }
        Node *prev = NULL, *cur = head;
        for(int i=0; i<tempLen; i++) {
            prev = cur;
            cur = cur -> next;
        }
        prev -> prev -> next = cur;
        cur -> prev = prev -> prev;
        int val = prev -> val;
        delete prev;
        return val;
    }
    
    int popBack() {
        if(len == 0) return -1;
        len--;
        int val = tail -> val;
        if(len == 0) {
            // delete head; delete tail;
            head = tail = NULL;
            return val;
        }
        Node *temp = tail;
        tail = tail -> prev; 
        if(tail) tail -> next = NULL;
        delete temp;
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
