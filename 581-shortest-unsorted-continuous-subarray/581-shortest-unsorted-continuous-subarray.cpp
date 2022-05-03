class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            temp.push_back(nums[i]);
        }
        
        sort(temp.begin(),temp.end());
        
        int count;
        int l=0;
        int r=n;
        for(int i=0;i<n;i++){
            if(nums[i] != temp[i]){
                l = i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i] != temp[i]){
                r = i;
                break;
            }
        }
    
        count = r-l+1;
        if(l==0 && r==n) count = 0;
        return count;
    }
};