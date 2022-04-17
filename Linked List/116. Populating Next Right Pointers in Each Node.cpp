/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root == NULL) return root;
        if(root -> left == NULL) return root;
        q.push(root -> left); q.push(root -> right);
        while(!q.empty()) {
            queue<Node*> tempQ; Node *first = NULL;
            while(!q.empty()) {
                Node *front = q.front(); q.pop();
                if(front -> left) {
                    tempQ.push(front -> left);
                    tempQ.push(front -> right);
                }
                if(first == NULL) first = front;
                else {
                    first -> next = front;
                    first = front;
                }
            }
            q = tempQ;
        }
        return root;
    }
};
