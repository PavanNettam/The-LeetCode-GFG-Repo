class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        ans.push_back(nums);
        if(n==1) return ans;
        if(n==2){
            int temp = nums[0];
            nums[0] = nums[1];
            nums[1] = temp;
            ans.push_back(nums);
            return ans;
        }
        while(1){
            int i = n-2;
            while(i>=0 && nums[i]>nums[i+1]){
                i--;
            }
            if(i<0) break;
            int j=n-1;
            while(j>=i+1 && nums[j]<nums[i]){
                j--;
            }
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            reverse(nums.begin()+i+1,nums.end());
            ans.push_back(nums);
            //cout<<nums[0]<<nums[1]<<nums[2]<<endl;
        }
        return ans;
    }
};