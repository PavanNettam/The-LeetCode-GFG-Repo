//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool compute(vector<int>& arr,int sum,int x,vector<vector<int>> &mem){
        if(sum == 0) return 1;
        if(x == arr.size()) return 0;
        if(mem[x][sum] != -1) return mem[x][sum];
        int take = 0;
        int not_take = 0;
        if(sum >= arr[x]){
            take = compute(arr,sum-arr[x],x+1,mem);
        }
        not_take = compute(arr,sum,x+1,mem);
        return mem[x][sum] = take || not_take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> mem(n+1,vector<int>(sum+1,-1));
        return compute(arr,sum,0,mem);
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