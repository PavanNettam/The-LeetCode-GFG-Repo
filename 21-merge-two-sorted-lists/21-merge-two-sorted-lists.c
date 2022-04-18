/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* l3 = NULL;
    struct ListNode* p = list1;
    struct ListNode* q = list2;
    struct ListNode* r = NULL;
    if(list1 == NULL){
        l3 = list2;
        return l3;
    }else if(list2 == NULL){
        l3 = list1;
        return l3;
    }
    if(list1->val < list2->val){
        l3 = list1;
        p = p->next;
    }else{
        l3 = list2;
        q = q->next;
    }
    r = l3;
    while(p!=NULL && q!=NULL){
        if(p->val < q->val){
            r->next = p;
            r = r->next;
            p = p->next;
        }else{
            r->next = q;
            r = r->next;
            q = q->next;
        }
    }
    if(p == NULL){
        r->next = q;
    }else if(q == NULL){
        r->next = p;
    }
    return l3;
}