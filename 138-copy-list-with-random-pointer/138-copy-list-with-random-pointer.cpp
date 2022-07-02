/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        unordered_map<Node*,int> temp;
        Node* p = head;
        int i=0;
        
        while(p!=NULL){
            temp[p] = i;
            i++;
            p = p->next;
        }
        
        temp[NULL] = i;
        
        vector<Node*> x;
        p = head;
        while(p != NULL){
            Node* q = new Node(p->val);
            x.push_back(q);
            p = p->next;
        }
        
        x.push_back(NULL);
        for(int j=0;j<i;j++){
            x[j]->next = x[j+1];
        }

        p = head;
        int j=0;
        while(p!=NULL){
            x[j]->random = x[temp[p->random]];
            p = p->next;
            j++;
        }
        return x[0];
    }
};