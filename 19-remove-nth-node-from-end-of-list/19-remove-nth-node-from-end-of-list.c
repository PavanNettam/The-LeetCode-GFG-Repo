/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* p = head;
    if(head == NULL){
        return;
    }
    int count = 0;
    while(p!=NULL){
        count++;
        p = p->next;
    }
    //printf("%d",count);
    if(n>count){
        return head;
    }
    int des = count - n;
    p = head;
    struct ListNode* q = NULL;
    for(int i=1;i<=des;i++){
        q = p;
        p = p->next;
    }
    if(q == NULL){
        head = p->next;
        free(p);
        return head;
    }else{
        q->next = p->next;
        free(p);
    }
    return head;
}