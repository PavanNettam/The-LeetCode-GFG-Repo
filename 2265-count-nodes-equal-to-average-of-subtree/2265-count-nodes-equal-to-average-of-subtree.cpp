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
    void avgSub(TreeNode* root,int &sum,int &count){
        if(root == NULL) return;
        avgSub(root->left,sum,count);
        count++;
        sum += root->val;
        avgSub(root->right,sum,count);
    }
    void inorder(TreeNode* root,int &ans){
        if(root == NULL) return;
        inorder(root->left,ans);
        int sum = 0;
        int count = 0;
        avgSub(root,sum,count);
        if(root->val == sum/count) ans++;
        inorder(root->right,ans);
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        inorder(root,ans);
        return ans;
    }
};