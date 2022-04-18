/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head){
    struct ListNode* i = head->next;
    struct ListNode* prev_i = head;
    struct ListNode* j = NULL;
    struct ListNode* prev_j = NULL;
    while(i!=NULL){
        j = head;
        prev_j = NULL;
        while(j!=i && j->val<i->val){
            prev_j = j;
            j = j->next;
        }
        if(prev_j == NULL){
            prev_i->next = i->next;
            i->next = j;
            head = i;
        }else{
            prev_i->next = i->next;
            i->next = prev_j->next;
            prev_j->next = i;
        }
        if(j == i){
            prev_i = i;
            i = i->next;
        }else{
            i = prev_i->next;
        }
        
    }
    
    return head;
    
}