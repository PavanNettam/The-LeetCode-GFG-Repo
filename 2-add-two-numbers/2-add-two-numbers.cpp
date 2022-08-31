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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode* ans = new ListNode(-1);
        ListNode* r = ans;
        ListNode* p = l1;
        ListNode* q = l2;
        while(p!=NULL && q!=NULL){
            int sum = p->val + q->val + c;
            r->next = new ListNode(sum%10);
            c = sum/10;
            p = p->next;
            q = q->next;
            r = r->next;
        }
        while(p!=NULL){
            int sum = p->val + c;
            r->next = new ListNode(sum%10);
            c = sum/10;
            p = p->next;
            r = r->next;
        }
        while(q!=NULL){
            int sum = q->val + c;
            r->next = new ListNode(sum%10);
            c = sum/10;
            q = q->next;
            r = r->next;
        }
        if(c>0){
            r->next = new ListNode(c);
        }
        return ans->next;
    }
};