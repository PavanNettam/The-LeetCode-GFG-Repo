class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        while( i >= 0 && nums[i] >= nums[i+1]){
            i--;
        }
        if(i >= 0){
            int j = nums.size()-1;
            while(nums[j]  <= nums[i]){
                j--;
            }
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
        }
        int l = i+1;
        int r = nums.size()-1;
        //cout<<l<<" "<<r<<endl;
        while(l<r){
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++;
            r--;
        }
    }
};