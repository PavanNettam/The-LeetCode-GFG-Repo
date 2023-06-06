//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n,0);
        for(int i=1;i<n;i++){
            int prev = abs(height[i-1]-height[i])+dp[i-1];
            int prev_ = (i-2<0)?INT_MAX:(abs(height[i-2]-height[i])+dp[i-2]);
            dp[i] = min(prev,prev_);
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends