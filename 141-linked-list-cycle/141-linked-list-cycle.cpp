/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return 0;
        ListNode* p = head;
        ListNode* q = head;
        do{
            if(p->next != NULL) p = p->next->next;
            q = q->next;
        }while(p!=NULL && p->next!=NULL && q!=NULL && p!=q);
        if(p==q) return 1;
        return 0;
    }
};