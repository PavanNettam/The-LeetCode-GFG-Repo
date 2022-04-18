/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* l3 = NULL;
    struct ListNode* p = l1;
    struct ListNode* q = l2;
    int carry = 0;
    struct ListNode* temp= (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val = (p->val + q->val + carry)%10;
    carry = (p->val + q->val + carry)/10;
    temp->next = NULL;
    l3 = temp;
    p = p->next;
    q = q->next;
    struct ListNode* r = l3;
    while(p!=NULL && q!=NULL){
        struct ListNode* temp= (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = (p->val + q->val + carry)%10;
        carry = (p->val + q->val + carry)/10;
        temp->next = NULL;
        r->next = temp;
        r = r->next;
        p = p->next;
        q = q->next;
    }
    if(p == NULL && q!=NULL){
        while(q!=NULL){
            struct ListNode* temp= (struct ListNode*)malloc(sizeof(struct ListNode));
            temp->val = (q->val + carry)%10;
            carry = (q->val + carry)/10;
            temp->next = NULL;
            r->next = temp;
            r = r->next;
            q = q->next;
        }
    }else if(q==NULL && p!=NULL){
        while(p!=NULL){
            struct ListNode* temp= (struct ListNode*)malloc(sizeof(struct ListNode));
            temp->val = (p->val + carry)%10;
            carry = (p->val + carry)/10;
            temp->next = NULL;
            r->next = temp;
            r = r->next;
            p = p->next;
        }
    }
    if(p == NULL && q == NULL){
        if(carry!=0){
            struct ListNode* temp= (struct ListNode*)malloc(sizeof(struct ListNode));
            temp->val = carry;
            temp->next = NULL;
            r->next = temp;
        }
    }
    return l3;
}