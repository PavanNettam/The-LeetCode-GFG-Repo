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
    void preorder(TreeNode* root,int level,vector<vector<int>>& ans){
        if(root==NULL) return;
        
        if(ans.size() == level) ans.push_back(vector<int>());
        
        ans[level].push_back(root->val);
        
        preorder(root->left,level+1,ans);
        preorder(root->right,level+1,ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        preorder(root,0,ans);
        return ans;
    }
};
/* 
Perform pre-order traversal,
if insert into the vector into a particular level.
Line 17 is important
*/