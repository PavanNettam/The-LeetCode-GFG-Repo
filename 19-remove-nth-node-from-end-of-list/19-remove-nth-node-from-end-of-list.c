/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* p = head;
    struct ListNode* q = head;
    if(head->next == NULL) return head->next;
    while(n>0){
        p = p->next;
        n--;
    }
    if(p == NULL){
        return head->next;
    }
    while(p->next != NULL){
        q = q->next;
        p = p->next;
    }
    q->next = q->next->next;
    return head;
}