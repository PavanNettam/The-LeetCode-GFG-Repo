class Solution {
public:
    void inex(vector<int> nums,vector<vector<int>>& ans,vector<int>& temp, int i){
        ans.push_back(temp);
        //go one level at a time, each level indicates the size of the subset.
        for(int it = i;it<nums.size(); it++){
            if(it != i && nums[it] == nums[it-1]){
                continue;
            }
            temp.push_back(nums[it]);
            inex(nums,ans,temp,it+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        inex(nums,ans,temp,0);
        return ans;
    }
};