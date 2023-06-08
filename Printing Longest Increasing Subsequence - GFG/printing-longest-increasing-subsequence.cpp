//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> dp(n,1);
        vector<int> hash(n);
        for(int i=0;i<n;i++) hash[i] = i;
        int maxIdx = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j] && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                }
            }
            if(dp[i] > dp[maxIdx]){
                maxIdx = i;
            }
        }
        int ele = maxIdx;
        vector<int> ans;
        while(ele!=hash[ele]){
            ans.push_back(arr[ele]);
            ele = hash[ele];
        }
        ans.push_back(arr[ele]);
        reverse(ans.begin(),ans.end());
        return ans;
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
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends