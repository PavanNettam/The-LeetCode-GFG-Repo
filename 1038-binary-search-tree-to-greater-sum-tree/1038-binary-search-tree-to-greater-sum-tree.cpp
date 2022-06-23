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
    void cal(TreeNode* root,int& sum){
        if(root==NULL) return;
        cal(root->right,sum);
        sum += root->val;
        root->val = sum;
        cal(root->left,sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        cal(root,sum);
        return root;
    }
};