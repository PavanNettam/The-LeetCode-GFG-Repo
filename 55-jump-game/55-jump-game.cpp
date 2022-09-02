class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i>reach){
                return 0;
            }
            if(reach < nums[i]+i){
                reach = nums[i]+i;
            }
        }
        return 1;
    }
};