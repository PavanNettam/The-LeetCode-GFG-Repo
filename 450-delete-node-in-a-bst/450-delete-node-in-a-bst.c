/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* deleteNode(struct TreeNode* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(key > root->val){
        root->right = deleteNode(root->right,key);
    }else if(key < root->val){
        root->left = deleteNode(root->left,key);
    }else{
        struct TreeNode* temp;
        if(root->left == NULL){
            temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            temp = root->left;
            free(root);
            return temp;
        }else{
            struct TreeNode* p = root->right;
            while(p->left != NULL){
                p = p->left;
            }
            root->val = p->val;
            root->right = deleteNode(root->right,p->val);
        }
    }
    return root;
}