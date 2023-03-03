//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        for(int i=0;i<n+1;i++){
            dp[0][i] = price[0]*i;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int not_take = dp[i-1][j];
                int take = 0;
                int len = i+1;
                if(len <= j) take = price[i] + dp[i][j-len];
                dp[i][j] = max(take,not_take);
            }
        }
        return dp[n-1][n];
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