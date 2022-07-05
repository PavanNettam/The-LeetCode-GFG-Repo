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
    int pairSum(ListNode* head) {
        ListNode* r = NULL;
        ListNode* q = head;
        ListNode* p = head;
        do{
            r = q;
            q = q->next;
            if(p->next != NULL) p = p->next->next;
        }while(p!=NULL);
        ListNode* note = r;
        p = q->next;
        r = NULL;
        while(q!=NULL){
            q->next = r;
            r = q;
            q = p;
            if(p!=NULL) p = p->next;
        }
        note->next = r;
        p = head;
        int ans = INT_MIN;
        while(r!=NULL){
            ans = max((p->val+r->val),ans);
            r = r->next;
            p = p->next;
        }
        return ans;
    }
};