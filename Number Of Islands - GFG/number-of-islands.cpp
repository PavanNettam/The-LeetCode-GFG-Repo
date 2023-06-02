//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    vector<int> parent,size;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findParent(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = findParent(parent[parent[x]]);
    }
    void findUnion(int u,int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return;
        if(size[pu]<size[pv]){
            parent[pu] = parent[pv];
            size[pv] += size[pu];
        }else{
            parent[pv] = parent[pu];
            size[pu] += size[pv];
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<vector<int>> vis(n,vector<int>(m,0));
        DisjointSet ds(n*m);
        vector<int> ans;
        int count = 0;
        for(auto i:operators){
            int x = i[0];
            int y = i[1];
            if(vis[x][y] == 1){
                ans.push_back(count);
            }else{
                vis[x][y] = 1;
                count++;
                vector<int> dr = {0,1,0,-1};
                vector<int> dc = {1,0,-1,0};
                for(int i=0;i<dr.size();i++){
                    int row = x+dr[i];
                    int col = y+dc[i];
                    if(row>=0 && row<n && col>=0 && col<m && vis[row][col]==1){
                        int cur = x*m+y;
                        int next = row*m+col;
                        if(ds.findParent(cur) != ds.findParent(next)){
                            count--;
                            ds.findUnion(cur,next);
                        }
                    }
                }
                ans.push_back(count);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends