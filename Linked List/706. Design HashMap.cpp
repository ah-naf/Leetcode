class Node {
public:
    int key, value;
    Node *next;
    Node(int k, int v) {
        key = k; value = v;
    }
};

class MyHashMap {
public:
    Node *head;
    MyHashMap() {
        head = NULL;
    }
    
    void put(int key, int value) {
        Node *list = head;
        while(list) {
            if(list -> key == key) {
                list -> value = value;
                return;
            }
            list = list -> next;
        }
        Node *temp = new Node(key, value);
        temp -> next = head;
        head = temp;
    }
    
    int get(int key) {
        Node *cur = head;
        while(cur) {
            if(cur -> key == key) return cur -> value;
            cur = cur -> next;
        }
        return -1;
    }
    
    void remove(int key) {
        if(head && head -> key == key) {
            Node *temp = head;
            head = head -> next;
            delete temp;
            return;
        } 
        Node *prev = NULL, *cur = head;
        while(cur) {
            if(cur -> key == key) {
                prev -> next = cur -> next;
                Node *temp = cur;
                cur = cur -> next;
                delete temp;
                return;
            }
            prev = cur; 
            cur = cur -> next;
        }
    }
};

