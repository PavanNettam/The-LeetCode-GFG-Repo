class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> temp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            temp.insert(nums[i]);
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            int ele = nums[i];
            if(temp.find(ele-1) == temp.end()){
                int count = 0;
                while(temp.find(ele) != temp.end()){
                    count++;
                    ele++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};