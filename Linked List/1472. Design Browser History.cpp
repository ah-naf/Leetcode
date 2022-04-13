class Node {
  public:
    Node *next;
    Node *prev;
    string url;
    Node(string s = "") {
        url = s;
        next = NULL;
        prev = NULL;
    }
};

Node *browser = new Node(), *cur = NULL;

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        browser = new Node(homepage);
        cur = browser;
    }
    
    void visit(string url) {
        Node *newLink = new Node(url);
        cur -> next = newLink;
        newLink -> prev = cur;
        cur = newLink;
    }
    
    string back(int steps) {
        string ans = cur -> url;
        while(steps-- && cur -> prev != NULL) {
            cur = cur -> prev;
            ans = cur -> url;
        }
        return ans;
    }
    
    string forward(int steps) {
        string ans = cur -> url;
        while(steps-- && cur->next != NULL) {
            cur = cur -> next;
            ans = cur -> url;
        }
        return ans;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */