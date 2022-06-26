class Solution {
public://Moores voting algorithum
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int ele = -1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(count == 0) ele = nums[i];
            if(nums[i] == ele){
                count++;
            }else{
                count--;
            }
        }
        return ele;
    }
};