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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* p = head->next;
        ListNode* q;
        ListNode* ret;
        ListNode* temp = new ListNode();
        temp->val = -1;
        temp->next = NULL;
        q = temp;
        ret = q;
        while(p!= NULL){
            int sum = 0;
            while(p->val != 0){
                sum+= p->val;
                p = p->next;
            }
            ListNode* temp = new ListNode();
            temp->val = sum;
            q->next = temp;
            q = q->next;
            p=p->next;
        }
        return ret->next;
    }
};