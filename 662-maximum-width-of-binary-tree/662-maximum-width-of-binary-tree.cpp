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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*,long long>> q;
        int ans = 0;
        q.push({root,0});
        while(!q.empty()){
            long long minidx = q.front().second;
            int size = q.size();
            long long l,r;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front().first;
                long long curidx = (q.front().second)-minidx;
                q.pop();
                if(i == 0) l = curidx;
                if(i == size-1) r = curidx;
                if(node->left != NULL) q.push({node->left,2*curidx+1});
                if(node->right != NULL) q.push({node->right,2*curidx+2});
            }
            ans = max(ans,int(r-l+1));
        }
        return ans;
    }
};
/*
1. Keep track of the indices of the elements in a particular level.(Do level order traversal)
2. maintain the global maximin of the difference between them.

how:
- Every time u go to a level, make note of the first index minidx and substract it like (2*curidx+1-minidx) for the left child and (2*curidx+2-minidx) for the right child.
*/