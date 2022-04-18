/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    struct TreeNode* ans = NULL;
    void insert(int ele){
        struct TreeNode* q = NULL;
        struct TreeNode* p = ans;
        struct TreeNode* temp = new TreeNode();
        temp->val = ele;
        temp->left = NULL;
        temp->right = NULL;
        if(ans == NULL){
            ans = temp;
            return;
        }
        while(p != NULL){
            if(p->val > ele){
                q = p;
                p = p->left;
            }else{
                q = p;
                p = p->right;
            }
        }
        
        if(ele < q->val){
            q->left = temp;
        }else{
            q->right = temp;
        }
    }
    void printLevelOrder(TreeNode* root,int low, int high)
    {
    if (root == NULL)
        return;
 
    queue<struct TreeNode*> q;
 
    q.push(root);
 
    while (q.empty() == false) {
        struct TreeNode* node = q.front();
        if(node->val <= high && node->val >= low){
            insert(node->val);
        }
        q.pop();
 
        if (node->left != NULL)
            q.push(node->left);
 
        if (node->right != NULL)
            q.push(node->right);
    }
}
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        printLevelOrder(root,low,high);
        return ans;
    }
};