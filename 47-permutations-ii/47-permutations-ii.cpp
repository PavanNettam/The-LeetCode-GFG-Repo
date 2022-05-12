class Solution {
    int n;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans; 
        ans.push_back(nums);
        while(next_permu(nums))
            ans.push_back(nums);
        return ans;
    }
    
    bool next_permu(vector<int> &nums){
        int i;
        for(i = n - 2; i >= 0 and nums[i] >= nums[i+1]; i--);
        if(i < 0) return false;
        int j;
        for(j = n - 1; j >= 0 and nums[j] <= nums[i]; j--);
        
        swap(nums[j],nums[i]);        
        reverse(nums.begin() + i + 1, nums.end());
        return true;
    }
};