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
    void inorder(TreeNode* root,int &ans){
        if(root == NULL) return;
        inorder(root->left,ans);
        if(root->val%2 == 0){
            TreeNode* p = root;
            if(p->left != NULL){
                p = p->left;
                TreeNode* q = p;
                if(p->left != NULL){
                    p = p->left;
                    ans += p->val;
                }
                if(q->right != NULL){
                    q = q->right;
                    ans += q->val;
                }
            }
            p = root;
            if(p->right != NULL){
                p = p->right;
                TreeNode* q = p;
                if(p->left != NULL){
                    p = p->left;
                    ans += p->val;
                }
                if(q->right != NULL){
                    q = q->right;
                    ans += q->val;
                }
            }
        }
        inorder(root->right,ans);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        inorder(root,ans);
        return ans;
    }
};