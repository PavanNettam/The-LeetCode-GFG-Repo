class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> temp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(temp.find(nums[i]) == temp.end()){
                temp[target - nums[i]] = i;
            }else{
                return {temp[nums[i]],i};
            }
        }
        return {-1,-1};
    }
};