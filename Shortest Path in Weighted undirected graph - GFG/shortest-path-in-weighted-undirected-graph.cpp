//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> g[n+1];
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            g[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        set<pair<int,int>> s;
        vector<int> path(n+1);
        vector<int> dist(n+1,1000000);
        for(int i=0;i<n+1;i++){
            path[i] = i;
        }
        s.insert({0,1});
        dist[1] = 0;
        while(!s.empty()){
            int node = (*s.begin()).second;
            int nodeDis = (*s.begin()).first;
            s.erase({nodeDis,node});
            for(auto i:g[node]){
                int nextNode = i.first;
                int edgeDis = i.second;
                if(nodeDis+edgeDis < dist[nextNode]){
                    dist[nextNode] = nodeDis+edgeDis;
                    path[nextNode] = node;
                    s.insert({dist[nextNode],nextNode});
                }
            }
        }
        if(dist[n]>=1000000) return {-1};
        vector<int> ans;
        int ele = n;
        while(ele != 1){
            ans.insert(ans.begin(),ele);
            ele = path[ele];
        }
        ans.insert(ans.begin(),1);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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