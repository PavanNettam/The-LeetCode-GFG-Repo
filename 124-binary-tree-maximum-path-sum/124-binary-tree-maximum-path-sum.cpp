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
    int findPath(TreeNode* root, int& maxi){
        if(root == NULL) return 0;
        
        int l = max(0,findPath(root->left,maxi));
        int r = max(0,findPath(root->right,maxi));
        
        maxi = max(maxi,l + r + root->val);
        
        return max(l,r) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findPath(root,maxi);
        return maxi;
    }
};