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
        struct TreeNode* p = ans;
        struct TreeNode* temp = new TreeNode();
        temp->val = ele;
        temp->left = NULL;
        temp->right = NULL;
        if(p == NULL){
            ans = temp;
            return;
        } 
        while(p->right != NULL){
            p = p->right;
        }
        p->right = temp;
    }
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        insert(root->val);
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return ans;
    }
};