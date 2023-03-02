//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    int abs(int a,int b){
        if(a>=b){
            return a-b;
        }else{
            return b-a;
        }
    }
	int minDifference(int arr[], int n)  { 
	    int k = 0;
	    for(int i=0;i<n;i++){
	        k += arr[i];
	    }
	    vector<vector<int>> dp(n, vector<int>(k+1, 0));
	    for(int i=0;i<n;i++){
	        dp[i][0] = 1;
	    }
	    if(arr[0] <= k) dp[0][arr[0]] = 1;
	    for(int i=1;i<n;i++){
	        for(int j=0;j<=k;j++){
	            int not_take = dp[i-1][j];
	            int take = 0;
	            if(arr[i] <= j) take = dp[i-1][j-arr[i]];
	            dp[i][j] = take | not_take;
	        }
	    }
	    int ans = INT_MAX;
	    for(int i=0;i<=k;i++){
	        if(dp[n-1][i] == 1){
	            int comp = k - i;
	            ans = min(ans,abs(comp,i));
	        }
	    }
	    return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends