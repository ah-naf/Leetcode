/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *node = head;
        while(node) {
            if(node -> child) {
                Node *child = node -> child;
                Node *nextNode = node -> next;
                node->child = nullptr;
                
                node -> next = child;
                child -> prev = node;
                
                while(child->next) child = child->next;
                
                if(nextNode) {
                    child -> next = nextNode;
                    nextNode -> prev = child;
                }
            }
            node = node -> next;
        }
        return head;
    }
};
