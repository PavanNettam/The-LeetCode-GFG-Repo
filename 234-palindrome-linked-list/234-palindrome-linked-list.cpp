/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL) return 1;
        ListNode* p = head;
        ListNode* q = head;
        ListNode* r = NULL;
        do{
            if(p->next!= NULL) p = p->next->next;
            r = q;
            q = q->next;
        }while(p!=NULL && p->next != NULL);
        
        if(p!=NULL){
            r->next = q->next;
            q = r->next;
        }
        ListNode* note = r;
        r = NULL;
        p = q->next;
        while(q!=NULL){
            q->next = r;
            r = q;
            q = p;
            if(p!=NULL) p = p->next;
        }
        note->next = r;
        p = head;
    
        while(r!=NULL){
            if(p->val != r->val) return 0;
            p = p->next;
            r = r->next;
        }
        return 1;
    }
};