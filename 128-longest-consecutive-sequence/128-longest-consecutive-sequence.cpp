class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        if(nums.size()==0) return 0;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = 1;
            }else{
                m[nums[i]]++;
            }
        }
        int ans = 1;
        for(int i=0;i<nums.size();i++){
            int temp = 1;
            long curr = nums[i];
        
            if(m.find(curr+1) == m.end()){
                
                curr--;
                while(m.find(curr) != m.end()){
                    temp++;
                    curr--;
                }
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};