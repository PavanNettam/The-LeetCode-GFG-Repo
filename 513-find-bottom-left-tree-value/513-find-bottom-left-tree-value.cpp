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
    void preorder(TreeNode* root,pair<int,int>& temp, int level){
        if(root == NULL) return;
        if(temp.second == level){
            temp.first = root->val;
            temp.second++;
        }
        preorder(root->left,temp,level+1);
        preorder(root->right,temp,level+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        pair<int,int> temp;
        temp = make_pair(0,0);
        preorder(root,temp,0);
        return temp.first;
    }
};