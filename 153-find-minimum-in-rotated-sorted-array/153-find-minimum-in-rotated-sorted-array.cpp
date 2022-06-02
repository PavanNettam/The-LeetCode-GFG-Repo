class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        if(r+1==1) return nums[0];
        if(nums[l]<nums[r]){
            return nums[l];
        }
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid+1] < nums[mid]){
                return nums[mid+1];
            }
            if(nums[mid] < nums[mid-1]){
                return nums[mid];
            }
            
            if(nums[mid] > nums[0]){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return -1;
    }
};