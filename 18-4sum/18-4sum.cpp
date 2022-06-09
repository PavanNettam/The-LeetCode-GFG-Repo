class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n<4) return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int l = j+1;
                int r = n-1;
                int t = target-nums[i]-nums[j];
                //cout<<"loop entry"<<i<<j<<endl;
                while(l<r){
                    if(nums[l]+nums[r]<t){
                        l++;
                    }else if(nums[l]+nums[r]>t){
                        r--;
                    }else{
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
                        ans.push_back(temp);
                        
                        while(l<r && nums[l]==nums[l+1]) l++;
                        //if(l<r && nums[l-1]==nums[l]) l++;
                        while(l<r && nums[r-1]==nums[r]) r--;
                        //if(l<r && nums[r+1]==nums[r]) r--;
                        l++;
                        r--;
                    }
                    //cout<<i<<j<<l<<r<<endl;
                    
                }
                //cout<<i<<j<<endl;
                while(j<n-2 && nums[j]==nums[j+1]) j++;
                //cout<<i<<j<<endl;
                //if(j<n-2 && nums[j]==nums[j-1]) j++;
                //cout<<i<<j<<endl;
                //cout<<"n-2 is "<<n-2<<endl;
            }
            //cout<<i<<endl;
            while(i<n-3 && nums[i]==nums[i+1]) i++;
            //cout<<i<<endl;
            //if(i<n-3 && i>0 &&nums[i]==nums[i-1]) i++;
            //cout<<i<<endl;
        }
        return ans;
    }
};