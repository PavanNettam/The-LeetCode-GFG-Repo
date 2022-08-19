class Solution {
public:
    void help(vector<int> candidates,int t,vector<vector<int>>& ans,vector<int>& temp,int i){
        if(i == candidates.size()){
            if(t == 0){
                ans.push_back(temp);
            }
            return;
        }
        if(t>0 && candidates[i]<=t){
            temp.push_back(candidates[i]);
            help(candidates,t-candidates[i],ans,temp,i);
            temp.pop_back();
        }
        help(candidates,t,ans,temp,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        help(candidates,target,ans,temp,0);
        return ans;
    }
};

/*
-Pick a number any number of times.
so no updation of index for left sub-tree.
go to right sub-tree if we hv to advance the index
this happens when target cannot be further reduced.
*/