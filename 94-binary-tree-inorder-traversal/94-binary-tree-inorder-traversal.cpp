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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode* p = curr->left;
                while(p->right != NULL){
                    p = p->right;
                }
                p->right = curr;
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }
        }
        return ans;
    }
};

/*
Morris algorithum,
if(cur->left is NULL) print curr and go to right;
else then find the inorder predicisor of cur and assign its right to cur, and make cur->left NULL move left;

eg:
    1
   / \
  2   3
 / \  /
4  5  6

-> 2
  / \
 4   5
      \
       1
        \
         3
        /
        6
        
-> 4
    \
     2
      \
       5
        \ 
         1
          \
           3
          /
         6
*/