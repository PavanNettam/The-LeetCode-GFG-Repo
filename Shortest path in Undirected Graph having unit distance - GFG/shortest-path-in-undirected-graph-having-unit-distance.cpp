//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> g[N];
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> dist(N,100000);
        vector<int> vis(N,0);
        queue<pair<int,int>> q;
        q.push({src,0});
        vis[src] = 1;
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            int x = ele.first;
            int d = ele.second;
            dist[x] = d;
            for(auto i:g[x]){
                if(!vis[i]){
                    q.push({i,d+1});
                    vis[i] = 1;
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends