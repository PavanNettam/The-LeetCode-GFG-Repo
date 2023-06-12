//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(vector<pair<int,int>> adj[],vector<int>& vis,int x,stack<int>& s){
        vis[x] = 1;
        for(auto i:adj[x]){
            int ele = i.first;
            if(!vis[ele]){
                dfs(adj,vis,ele,s);
            }
        }
        s.push(x);
    }
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        stack<int> s;
        vector<pair<int,int>> adj[N];
        vector<int> vis(N,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        for(int i=0;i<N;i++){
            if(!vis[i]){
                dfs(adj,vis,i,s);
            }
        }
        vector<int> dist(N,100000);
        dist[0] = 0;
        while(!s.empty()){
            int cur = s.top();
            s.pop();
            for(auto i:adj[cur]){
                int next = i.first;
                int nextEdge = i.second;
                if(dist[next] > dist[cur]+nextEdge){
                    dist[next] = dist[cur]+nextEdge;
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i]>=100000){
                dist[i] = -1;
            }
        }
        return dist;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends