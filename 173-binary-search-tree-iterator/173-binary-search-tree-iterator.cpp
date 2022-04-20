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
class BSTIterator {
public:
    stack <TreeNode*> st;
    void moveLeft(TreeNode* root){
        TreeNode* p = root;
        while(p!=NULL){
            st.push(p);
            p = p->left;
        }
    }
    BSTIterator(TreeNode* root) {
        moveLeft(root);
    }
    
    int next() {
        TreeNode* ans = st.top();
        st.pop();
        if(ans->right != NULL){
            moveLeft(ans->right);
        }
        return ans->val;
    }
    
    bool hasNext() {
        if(st.empty()) return 0;
        return 1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */