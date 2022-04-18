/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode* l = NULL;
    struct ListNode* p = head;
    int n = 0;
    if(head == NULL){
        return head;
    }
    while(p!=NULL){
        p = p->next;
        n++;
    }
    if(k!=0)
     k = k % n;
    int dst = n-k;
    if(dst == n){
        l = head;
        return l;
    }
    struct ListNode* q = NULL;
    p = head;
    for(int i=0;i<dst;i++){
        q = p;
        p = p->next;
    }
    q->next = NULL;
    q = head;
    head = p;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = q;
    l = head;
    return l;
}