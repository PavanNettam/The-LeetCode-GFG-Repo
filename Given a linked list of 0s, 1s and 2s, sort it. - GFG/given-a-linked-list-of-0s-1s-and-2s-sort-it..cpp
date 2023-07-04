//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
public:
    Node* segregate(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        Node* zerosHead = nullptr;
        Node* onesHead = nullptr;
        Node* twosHead = nullptr;
        
        Node* zerosTail = nullptr;
        Node* onesTail = nullptr;
        Node* twosTail = nullptr;
        
        while (head != nullptr) {
            if (head->data == 0) {
                if (zerosHead == nullptr) {
                    zerosHead = zerosTail = head;
                } else {
                    zerosTail->next = head;
                    zerosTail = zerosTail->next;
                }
            } else if (head->data == 1) {
                if (onesHead == nullptr) {
                    onesHead = onesTail = head;
                } else {
                    onesTail->next = head;
                    onesTail = onesTail->next;
                }
            } else { // head->data == 2
                if (twosHead == nullptr) {
                    twosHead = twosTail = head;
                } else {
                    twosTail->next = head;
                    twosTail = twosTail->next;
                }
            }
            
            head = head->next;
        }
        
        // Link the three lists together
        if (zerosTail != nullptr) {
            zerosTail->next = (onesHead != nullptr) ? onesHead : twosHead;
        }
        
        if (onesTail != nullptr) {
            onesTail->next = twosHead;
        }
        
        if (twosTail != nullptr) {
            twosTail->next = nullptr;
        }
        
        // Return the head of the sorted list
        return (zerosHead != nullptr) ? zerosHead : ((onesHead != nullptr) ? onesHead : twosHead);
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends