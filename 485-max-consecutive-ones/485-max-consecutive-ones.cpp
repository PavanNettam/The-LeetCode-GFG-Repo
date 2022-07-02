class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int r = 0;
        int ans = 0;
        int temp = 0;
        while(r<n){
            while(r<n && nums[r] == 1){
                temp++;
                r++;
            }
            if(r<n){
                ans = max(ans,temp);
                temp = 0;
                l = r;
                r++;
            }
        }
        return max(ans,temp);
    }
};