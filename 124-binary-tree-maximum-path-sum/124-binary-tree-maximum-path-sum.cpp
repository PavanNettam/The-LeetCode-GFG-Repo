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
        //If u get a zero from left or right path then dont consider it.
        int l = max(0,findPath(root->left,maxi));
        int r = max(0,findPath(root->right,maxi));
        //Maximum 'U' shaped path
        maxi = max(maxi,l + r + root->val);
        //Return the max branch.
        return max(l,r) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findPath(root,maxi);
        return maxi;
    }
};