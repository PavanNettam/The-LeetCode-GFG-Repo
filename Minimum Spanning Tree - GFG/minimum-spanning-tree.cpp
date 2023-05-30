//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet
{
    vector<int> parent,rank;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++){
            parent[i] = i;
        }
    }
    int findUParent(int x){
        if(parent[x] == x) return x;
        return parent[x] = findUParent(parent[x]);
    }
    void unionRank(int u,int v){
        int pu = findUParent(u);
        int pv = findUParent(v);
        if(pu == pv) return;
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }else if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    void print(){
        cout<<"Parent: ";
        for(auto i: parent) cout<<i<<" ";
        cout<<endl;
        cout<<"rank: ";
        for(auto i: rank) cout<<i<<" ";
        cout<<endl;
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<vector<int>> edges;
        for(int i=0;i<V;i++){
            for(auto j:adj[i]){
                int node = i;
                int nextNode = j[0];
                int wt = j[1];
                edges.push_back({wt,node,nextNode});
            }
        }
        sort(edges.begin(),edges.end());
        int ans = 0;
        DisjointSet ds(V);
        for(auto i:edges){
            int u = i[1];
            int v = i[2];
            int wt = i[0];
            if(ds.findUParent(u)!=ds.findUParent(v)){
                ds.unionRank(u,v);
                ans += wt;
            }
        }
        //ds.print();
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends