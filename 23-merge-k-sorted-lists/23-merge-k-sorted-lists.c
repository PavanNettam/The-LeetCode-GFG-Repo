/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode* l = NULL;
    int done = 0;
    int min,val=0;
    if(listsSize == 0) return l;
    if(lists == NULL) return l;
    if(listsSize == 1) return lists[0];
    for(int i=0;i<listsSize;i++){
        if(lists[i] == NULL)
            val++;
    }
    if(val == listsSize){
        done = 1;
    }
    if(done == 1) return l;
    for(int i=0;i<listsSize;i++){
        if(lists[i] != NULL)
            min = i;
    }
    for(int i=0;i<listsSize;i++){
        if(lists[i] != NULL){
            if(lists[i]->val < lists[min]->val){
                min = i;
            }
        }
    }
    l = lists[min];
    lists[min] = lists[min]->next; 
    struct ListNode* r = l;
    val = 0;
    for(int i=0;i<listsSize;i++){
        if(lists[i] == NULL)
            val++;
    }
    if(val == listsSize){
        done = 1;
    }
    //printf("%d ",listsSize);
    while(!done){
        for(int i=0;i<listsSize;i++){
            if(lists[i] != NULL)
                min = i;
        }
        for(int i=0;i<listsSize;i++){
            if(lists[i] != NULL){
                if(lists[i]->val < lists[min]->val){
                    min = i;
                }
            }
        }
        r->next = lists[min];
        r = r->next;
        lists[min] = lists[min]->next; 
        val = 0;
        for(int i=0;i<listsSize;i++){
            if(lists[i] == NULL)
                val++;
        }
        if(val == listsSize){
            done = 1;
        }
    }
    return l;
}