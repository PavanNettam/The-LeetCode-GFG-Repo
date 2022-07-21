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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL)
            return NULL;
        ListNode* temp=head;
        vector<int> arr;
        
        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }
        
        while(left<right)
        {
            int t=arr[left-1];
            arr[left-1]=arr[right-1];
            arr[right-1]=t;
            left++;
            right--;
        }
        temp=head;
        int i=0;
        
        while(temp!=NULL)
        {
            temp->val=arr[i];
            temp=temp->next;
            i++;
        }
        return head;        
    }
};