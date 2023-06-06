//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,0));
        for(int i=0;i<n;i++) dp[i][0] = 1;
        if(sum>=arr[0]) dp[0][arr[0]] = 1;
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                int not_take = dp[i-1][j];
                int take = 0;
                if(arr[i] <= j){
                    take = dp[i-1][j-arr[i]];
                }
                dp[i][j] = take | not_take;
            }
        }
        return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends