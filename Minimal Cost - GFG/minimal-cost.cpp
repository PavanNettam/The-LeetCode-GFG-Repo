//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n,0);
        dp[0] = 0;
        for(int i=1;i<n;i++){
            int j = i-1;
            int mini = INT_MAX;
            while(j>=0 && i-j<=k){
                mini = min(mini,dp[j]+abs(height[i]-height[j]));
                j--;
            }
            dp[i] = mini;
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends