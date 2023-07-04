//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* head) {
        if(head == NULL) return head;
        Node* p = NULL;
        Node* q = head;
        Node* r = q->next;
        while(q!=NULL){
            q->next = p;
            p = q;
            q = r;
            if(r!=NULL) r = r->next;
        }
        return p;
    }
    public:
    Node* addOne(Node *head) 
    {
        Node* temp = reverse(head);
        int sum,carry;
        Node* p = temp;
        sum = p->data + 1;
        carry = sum/10;
        sum %= 10;
        p->data = sum;
        Node* q = p;
        p = p->next;
        while(p != NULL){
            sum = p->data + carry;
            carry = sum/10;
            sum %= 10;
            p->data = sum;
            q = p;
            p = p->next;
        }
        if(carry != 0){
            q->next = new Node(carry);
        }
        head = reverse(temp);
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends