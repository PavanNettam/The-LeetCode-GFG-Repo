class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> f(100001,0);
        int l = 0;int r=0;
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        while(r<n){
            if(f[nums[r]]==0){
                f[nums[r]]++;
                sum += nums[r];
                ans = max(ans,sum);
                r++;
            }else{
                sum -= nums[l];
                f[nums[l]]--;
                l++;
            }
        }
        return ans;
    }
};