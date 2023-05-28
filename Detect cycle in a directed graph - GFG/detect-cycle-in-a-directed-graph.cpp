//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public://here we are using topo sort based bfs for cycle detection
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> in(V,0);
        for(int i=0;i<V;i++){
            for(auto j:adj[i]){
                in[j]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            topo.push_back(ele);
            for(auto i:adj[ele]){
                in[i]--;
                if(in[i]==0){
                    q.push(i);
                }
            }
        }
        if(topo.size()==V){
            return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends