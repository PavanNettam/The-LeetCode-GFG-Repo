//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int price[], int i, int leftout_len, vector<vector<int>> &dp){
        if(leftout_len == 0 || i<0){
            return 0;
        }
        if(dp[i][leftout_len] != -1) return dp[i][leftout_len];
        int cut = 0;
        int dont_cut = 0;
        if(leftout_len >= i+1){
            cut = price[i] + solve(price,i,leftout_len-(i+1),dp);
        }
        dont_cut = 0 + solve(price,i-1,leftout_len,dp);
        return dp[i][leftout_len] = max(cut,dont_cut);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(price,n-1,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends