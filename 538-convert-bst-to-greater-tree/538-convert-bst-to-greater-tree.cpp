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
    int n;
    int arr[10001];
    int ans[10001];
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        arr[n] = root->val;
        n++;
        inorder(root->right);
    }
    int i=0;
    void inorder2(TreeNode* root){
        if(root == NULL) return;
        inorder2(root->left);
        root->val = ans[i];
        i++;
        inorder2(root->right);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL) return root;
        if(root->left == NULL && root->right == NULL) return root;
        inorder(root);
        ans[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            ans[i] = ans[i+1] + arr[i]; 
        }
        inorder2(root);
        return root;
    }
};