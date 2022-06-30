/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    struct ListNode* p = list1;
    struct ListNode* q = list2;
    struct ListNode* r = NULL;
    struct ListNode* ans = NULL;
    if(p->val < q->val){
            r = p;
            p = p->next;
    }else{
            r = q;
            q = q->next;
    }
    ans = r;
    while(p!=NULL && q!=NULL){
        if(p->val < q->val){
            r->next = p;
            r = p;
            p = p->next;
        }else{
            r->next = q;
            r = q;
            q = q->next;
        }
    }
    if(p == NULL) r->next = q;
    else if(q == NULL) r->next = p;
    return ans;
}