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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* r = NULL;
        ListNode* q = head;
        ListNode* p = q->next;
        while(q != NULL){
            q->next = r;
            r = q;
            q = p;
            if(p!=NULL) p = p->next;
        }
        head = r;
        return head;
    }
};