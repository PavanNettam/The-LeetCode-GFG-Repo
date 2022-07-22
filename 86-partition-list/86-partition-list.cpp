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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* dummy = new ListNode(-1);
        dummy -> next = NULL;
        ListNode* ans = dummy;
        ListNode* current = head;
        
        while(current){  
            if(current->val < x){
                int value = current->val;
                ListNode* temp = new ListNode(value);
                dummy->next = temp;
                dummy = dummy -> next;
            }
            current = current -> next;
        }
        
        
        current = head;
        while(current){  
            if(current->val >= x){
                int value = current->val;
                ListNode* temp = new ListNode(value);
                dummy->next = temp;
                dummy = dummy -> next;
            }
            current = current -> next;
        }
        
        return ans->next;
    }
};