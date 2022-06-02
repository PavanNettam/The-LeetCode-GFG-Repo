class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int r = nums[0];
        int maxi = r;
        int mini = r;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                int temp = maxi;
                maxi = mini;
                mini = temp;
            }
            if(nums[i] > maxi*nums[i]){
                maxi = nums[i];
            }else{
                maxi = maxi*nums[i];
            }
            if(nums[i] < mini*nums[i]){
                mini = nums[i];
            }else{
                mini = mini*nums[i];
            }
            r = (r>maxi)?r:maxi;
        }
        return r;
    }
};