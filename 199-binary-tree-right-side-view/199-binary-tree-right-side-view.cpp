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
    void revPre(TreeNode* root,vector<int>& ans,int level){
        if(root==NULL) return;
        if(ans.size()==level) ans.push_back(root->val);
        revPre(root->right,ans,level+1);
        revPre(root->left,ans,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        revPre(root,ans,0);
        return ans;
    }
};

/*
traverse the tree in reverse preorder traversal,
for the first time you go to a particular element then note down that element.
(well how are u gonna do that? refer to line 16)
*/