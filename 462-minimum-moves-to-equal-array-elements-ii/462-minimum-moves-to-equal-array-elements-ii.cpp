class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int mid=nums[(nums.size())/2];
        for(int i=0;i<nums.size();i++)
        {
            ans+=abs(mid-nums[i]);
        }
        return ans;
    }
};