//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>& adj, int x, vector<int>& vis,int n){
        vis[x] = 1;
        for(int j=0;j<n;j++){
            if(adj[x][j] == 1 && vis[j]==0){
                dfs(adj,j,vis,n);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> vis(V,0);
        int count = 0;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                count++;
                dfs(adj,i,vis,V);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends