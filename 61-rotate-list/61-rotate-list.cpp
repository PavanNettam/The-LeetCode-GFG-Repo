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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int len = 0;
        ListNode* p = head;
        while(p!=NULL){
            p = p->next;
            len++;
        }
        k %= len;
        if(k == 0) return head;
    
        int count = len-k-1;
        p = head;
        while(count--){
            p = p->next;
        }
        ListNode* q = p;
        p = p->next;
        q->next = NULL;
        q = p;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = head;
        head = q;
        return head;
    }
};