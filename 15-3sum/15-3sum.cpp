class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        if(n<3) return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int t = -nums[i];
            int l = i+1;
            int r = n-1;
            while(l<r){
                //cout<<"hi"<<endl;
                if(nums[l]+nums[r] < t){
                    l++;
                }else if(nums[l]+nums[r] > t){
                    r--;
                }else{
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    ans.push_back(temp);
                    while(l<r && nums[l]==nums[l+1]){
                        l++;
                    }
                    while(l<r && nums[r-1]==nums[r]){
                        r--;
                    }
                    l++;r--;
                }
            }
            while(i+1<n && nums[i]==nums[i+1]){
                i++;
            }
        }
        return ans;
    }
};