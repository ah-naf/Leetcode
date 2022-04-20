class Node {
public:
    int val;
    Node *next, *prev;
    Node(int value = 0) {
        val = value;
        next = NULL; prev = NULL;
    }
};

class MyCircularQueue {
public:
    int size, limit;
    Node *head, *tail;
    MyCircularQueue(int k) {
        size = 0;
        limit = k;
        head = tail = NULL;
    }
    
    bool enQueue(int value) {
        if(size >= limit) return false;
        Node *temp = new Node(value);
        if(!head) {
            head = tail = temp;
        } else {
            tail -> next = temp;
            temp -> prev = tail;
            tail = temp;
        }
        size++;
        return true;
    }
    
    bool deQueue() {
        if(size == 0) {
            return false;
        }
        if(!head -> next) {
            head = tail = NULL;
        } else {
            Node *temp = head;
            head = head -> next;
            delete temp;
        }
        size--;
        return true;
    }
    
    int Front() {
        return size > 0 ? head -> val : -1;
    }
    
    int Rear() {
        return size > 0 ? tail -> val : -1;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == limit;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
