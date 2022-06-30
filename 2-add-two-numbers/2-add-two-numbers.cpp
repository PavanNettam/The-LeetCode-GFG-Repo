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
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* dummy = new ListNode();
        ListNode* r = dummy;
        int c = 0;
        while(p != NULL || q != NULL){
            int x = (p==NULL)?0:p->val;
            int y = (q==NULL)?0:q->val;
            int num = x+y+c;
            c = num/10;
            r->next = new ListNode(num%10);
            r = r->next;
            if(p!=NULL) p=p->next;
            if(q!=NULL) q=q->next;
        }
        if(c>0){
            r->next = new ListNode(c);
        }
        return dummy->next;
    }
};