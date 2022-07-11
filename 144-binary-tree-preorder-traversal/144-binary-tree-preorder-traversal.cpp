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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode* p = curr->left;
                while(p->right != NULL && p->right != curr){
                    p = p->right;
                }
                if(p->right == NULL){
                    p->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                }else{
                    p->right = NULL;
                    curr = curr->right;
                }
                
            }
        }
        return ans;
    }
};

/*
Same as inorder traversal but think,
it makes more sense to put line 32 to 28.
clearly:
if curr's left is NULL
    then print curr,
    go to right.
else
    then find inorder predicisor,
    if inorder predicisor's right is curr 
        set inorder predicisor's right to curr,
        and move right
    else
        then print curr,
        make inorder predicisor's right NULL again //to ensure we are not changing the tree.
        go to right.
        
*/