class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int temp = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            temp += nums[i];
            if(temp>ans){
                ans = temp;
            }
            if(temp < 0){
                temp =0 ;
            }
        }
        return ans;
    }
};