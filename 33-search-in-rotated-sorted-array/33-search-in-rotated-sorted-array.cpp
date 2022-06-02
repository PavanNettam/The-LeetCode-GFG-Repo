class Solution {
public:
    int binSer(vector<int>& nums, int target,int l,int r){
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int ifn = -1;
        int n = nums.size();
        if(n==1){
            if(target == nums[0]){
                return 0;
            }
            return -1;
        }
        int l = 0;
        int r = n-1;
        if(nums[0]<nums[r]){
            return binSer(nums,target,l,r);
        }
        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[mid+1] < nums[mid]){
                ifn = mid+1;
                if(target >= nums[0]){
                    return binSer(nums,target,0,ifn-1);
                }
                return binSer(nums,target,ifn,n-1);
            }
            if(nums[mid] < nums[mid-1]){
                ifn = mid;
                if(target >= nums[0]){
                    return binSer(nums,target,0,ifn-1);
                }
                return binSer(nums,target,ifn,n-1);
            }
            
            
            if(nums[mid]>nums[0]){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return -1;
    }
};