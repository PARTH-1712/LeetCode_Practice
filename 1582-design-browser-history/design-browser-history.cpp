class Node {
public:
    string val;
    Node* next;
    Node* back;
    Node(string url) {
        this->val = url;
        this->next = NULL;
        this->back = NULL;
    }
};

class BrowserHistory {
public:
    Node* curr = NULL;
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }

    void visit(string url) {
        Node* temp = new Node(url);
        temp->back = curr;
        curr->next = temp;
        curr = curr->next;
    }

    string back(int steps) {
        while(steps>0 && curr->back) {
            curr=curr->back;
            steps-=1;
        }
        return curr->val;
    }

    string forward(int steps) { 
        while(steps>0 && curr->next) {
            curr=curr->next;
            steps-=1;
        }
        return curr->val;
     }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

