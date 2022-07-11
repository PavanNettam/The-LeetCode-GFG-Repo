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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> temp; 
        queue<pair<TreeNode*,pair<int,int>>> q; 
        q.push({root,{0,0}}); 
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            TreeNode* node = ele.first;
            int x = ele.second.first;
            int y = ele.second.second;
            temp[x][y].insert(node->val);
            if(node->left != NULL) q.push({node->left,{x-1,y+1}});
            if(node->right != NULL) q.push({node->right,{x+1,y+1}});
        }
        vector<vector<int>> ans;
        for(auto i:temp){
            vector<int> col;
            for(auto j:i.second){
                col.insert(col.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

/*
perform level order traversal of the tree keeping in track the vertical line and horizontal line.
insert the values of the node to corresponding vertical line indices in the map.
make sure for overlaping co-ordinates ans must be sorted
*/