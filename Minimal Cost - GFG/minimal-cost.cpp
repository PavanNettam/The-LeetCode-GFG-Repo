//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n,0);
        for(int i=1;i<n;i++){
            int temp = i-1;
            int mini = INT_MAX;
            while(temp >= 0 && i-temp <= k){
                mini = min(mini,abs(height[temp]-height[i])+dp[temp]);
                temp--;
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