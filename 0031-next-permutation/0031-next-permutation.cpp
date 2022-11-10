class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return;
        int flag = 1;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int i = n-2;
        while(i>=0){
            if(nums[i]<nums[i+1]) break;
            i--;
        }
        int j = n-1;
        while(j>=i){
            if(nums[j]>nums[i]) break;
            j--;
        }
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
        reverse(nums.begin()+i+1,nums.end());
    }
};