//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n+1,vector<int>(3,0));
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = 0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++){
                int maxi = 0;
                for(int k=0;k<3;k++){
                    if(k!=j){
                        maxi = max(points[i-1][k]+dp[i-1][k],maxi);
                    }
                }
                dp[i][j] = maxi;
            }
        }
        return max(dp[n][0],max(dp[n][1],dp[n][2]));
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends