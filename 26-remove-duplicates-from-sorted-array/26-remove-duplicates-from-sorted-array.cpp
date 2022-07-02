class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        int i=0;
        while(i<nums.size()-1){
            if(nums[i]==nums[i+1]){
                nums.erase(nums.begin()+i+1);
            }else{
                count++;
                i++;
            }
        }
        return i+1;
    }
};