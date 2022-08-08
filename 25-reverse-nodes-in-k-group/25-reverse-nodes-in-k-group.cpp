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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;
        int count=0;
        while(curr!=NULL && count!=k){
            curr=curr->next;
            count++;
        }
        if(count != k){
            return head;
        }
        count=0;
        curr=head;
        while(curr!=NULL && count!=k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }

        ListNode* prev_head=head;
        prev_head->next=reverseKGroup(curr,k);
        head=prev;
        return head;
    }
};