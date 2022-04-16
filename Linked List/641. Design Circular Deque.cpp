class Deque {
public:
    int val;
    Deque *next, *prev;  
    Deque(int value = 0) {
        val = value;
        next = NULL;
        prev = NULL;
    }
};

Deque *head, *tail;

class MyCircularDeque {
public:
    int totalLen, len;
    MyCircularDeque(int k) {
        totalLen = k;
        len = 0;
    }
    
    bool insertFront(int value) {
        if(len >= totalLen) return false;
        Deque *temp = new Deque(value);
        if(len == 0) head = temp, tail = temp;
        else {
            head -> prev = temp;
            temp -> next = head;
            head = temp;
        }
        len++;
        return true;
    }
    
    bool insertLast(int value) {
        if(len >= totalLen) return false;
        Deque *temp = new Deque(value);
        if(len == 0) head = temp, tail = temp;
        else {
            temp -> prev = tail;
            tail -> next = temp;
            tail = temp;
        }
        len++;
        return true;
    }
    
    bool deleteFront() {
        if(len == 0) return false;
        head = head -> next; len--;
        if(head) head -> prev = NULL;
        return true;
    }
    
    bool deleteLast() {
        if(len == 0) return false;
        tail = tail -> prev; len--;
        if(tail) tail -> next = NULL;
        return true;
    }
    
    int getFront() {
        if(len == 0) return -1;
        return head -> val;
    }
    
    int getRear() {
        if(len == 0) return -1;
        return tail -> val;
    }
    
    bool isEmpty() {
        return len == 0;
    }
    
    bool isFull() {
        return len >= totalLen;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
