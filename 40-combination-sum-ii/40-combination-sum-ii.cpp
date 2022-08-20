class Solution {
public:
    void inex(vector<int> nums,int t, vector<int>& temp, vector<vector<int>>& ans, int curr){
        if(t == 0){
            ans.push_back(temp);
            return;
        }
        for(int i=curr;i<nums.size();i++){
            if(i != curr && nums[i] == nums[i-1]) continue;
            if(nums[i] <= t){
                temp.push_back(nums[i]);
                inex(nums,t-nums[i],temp,ans,i+1);
                temp.pop_back();
            }else{
                return;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        inex(candidates,target,temp,ans,0);
        return ans;
    }
};