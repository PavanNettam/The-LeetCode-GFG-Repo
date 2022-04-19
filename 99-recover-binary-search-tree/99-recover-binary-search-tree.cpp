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
    TreeNode* p = NULL;
    TreeNode* q = NULL;
    TreeNode* prev;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        if(p == NULL && prev->val > root->val){
            p = prev;
        }
        if(p != NULL && prev->val > root->val){
            q = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        prev = new TreeNode();
        prev->val = INT_MIN;
        inorder(root);
        int temp = p->val;
        p->val = q->val;
        q->val = temp;
    }
};