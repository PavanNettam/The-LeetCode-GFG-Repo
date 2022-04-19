/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* l3 = NULL;
    if(head == NULL){
        return l3;
    }else if(head->next == NULL){
        l3 = head;
        return l3;
    }
    struct ListNode* q = head;
    struct ListNode* p = q->next;
    struct ListNode* r = NULL;
    q->next = p->next;
    p->next = q;
    head = p;
    r = q;
    q = q->next;
    if(q!=NULL)
        p = q->next;
    while(p!=NULL && q!=NULL){
        q->next = p->next;
        p->next = q;
        r->next = p;
        r = q;
        q = q->next;
        if(q!=NULL)
            p = q->next;
    }
    l3 = head;
    return l3;
}