class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int ele = nums[i];
            int found = 1e9 + 1;
            for(int j=i+1;j<n;j++){
                if(nums[j] > nums[i]){
                    found = nums[j];
                    break;
                }
            }
            if(found == 1e9 + 1){
                for(int j=0;j<i;j++){
                    if(nums[j] > nums[i]){
                        found = nums[j];
                        break;
                    }
                }
            }
            if(found == 1e9 + 1){
                ans[i] = -1;
            }else{
                ans[i] = found;
            }
        }
        return ans;
    }
};