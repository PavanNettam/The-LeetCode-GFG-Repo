//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	/*
	Extension of LIS:
    	-Find LIS DP
    	-Reverse the array ans find LIS dp and then reverse the dp2 array
    	-Add up both DP arrays element wise and substract 1
	*/
	void findLIS(vector<int>nums, vector<int> &dp){
	    int n = nums.size();
	    for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
	}
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n = nums.size();
	    vector<int> dp1(n,1),dp2(n,1);
	    findLIS(nums,dp1);
	    reverse(nums.begin(),nums.end());
	    findLIS(nums,dp2);
	    reverse(dp2.begin(),dp2.end());
	    int maxi = 1;
	    for(int i=0;i<n;i++){
	        maxi = max(maxi,dp1[i]+dp2[i]-1);
	    }
	    return maxi;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends