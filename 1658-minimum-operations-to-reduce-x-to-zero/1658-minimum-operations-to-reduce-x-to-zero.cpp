class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // int ans = recur(nums,0,nums.size()-1,x);
        // return (ans>=1e8?-1:ans);
        int n = nums.size();
        int pref[n];
        int suff[n];
        pref[0] = nums[0];
        suff[n-1] = nums[n-1];
        for(int i = 1; i<n; i++){
            pref[i] = nums[i]+pref[i-1];
        }
        for(int i = 1; i<n; i++){
            suff[n-i-1] = nums[n-i-1]+suff[n-i];
        }
        int minn = 1e8;
        for(int i = 0; i<n; i++){
            int low = 0;
            int high = n-(n-i+1);
            int target = (x-suff[i]);
            while(low<=high){
                int mid = low+(high-low)/2;
                if(pref[mid]==target){
                    minn = min(minn,n-i+mid+1);
                    break;
                }
                else  if(pref[mid]>target){
                    high = mid-1;
                }
                else low = mid+1;
            }
        }
        for(int i = 0; i<n; i++){
            if(pref[i]==x)minn = min(minn,i+1);
        }
        for(int i = 0; i<n; i++){
            if(suff[i]==x)minn = min(minn,n-i);
        }
        return (minn>=1e8?-1:minn);
    }
};