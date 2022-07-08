class Solution {
public:
    void get(vector<int>& nums,int n, int i, vector<int>& temp,vector<vector<int>>& ans){
        if(i == n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        get(nums,n,i+1,temp,ans);
        temp.pop_back();
        get(nums,n,i+1,temp,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        get(nums,nums.size(),0,temp,ans);
        return ans;
    }
};