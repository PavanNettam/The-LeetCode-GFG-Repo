//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0;i<N;i++){
            sum += arr[i];
        }
        if(sum%2 != 0) return 0;
        sum /= 2;
        vector<vector<int>> dp(N, vector<int>(sum+1,0));
        for(int i=0;i<N;i++){
            dp[i][0] = 1;
        }
        if(arr[0] <= sum) dp[0][arr[0]] = 1;
        for(int i=1;i<N;i++){
            for(int j=1;j<=sum;j++){
                int not_take = dp[i-1][j];
                int take = 0;
                if(arr[i] <= j){
                    take = dp[i-1][j-arr[i]];
                }
                dp[i][j] = take | not_take;
            }
        }
        return dp[N-1][sum];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends