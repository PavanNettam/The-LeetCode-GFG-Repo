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
    int sum = 0;
    int curr = 0;
    int height(TreeNode* root){
        if(root==NULL) return -1;
        return max(height(root->left),height(root->right))+1;
    }
    void getsum(TreeNode* root,int h){
        if(root==NULL){
            curr--;
            return;
        }
        curr++;
        getsum(root->left,h);
        if(curr == h) sum += root->val;
        curr++;
        getsum(root->right,h);
        curr--;
    }
    int deepestLeavesSum(TreeNode* root) {
        int h = height(root);
        //cout<<h<<endl;
        getsum(root,h);
        return sum;
    }
};