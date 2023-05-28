//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>& grid,vector<pair<int,int>>& temp, int x,int y,vector<vector<int>>& vis,int srcx,int srcy,int n,int m){
        vis[x][y] = 1;
        temp.push_back({srcx-x,srcy-y});
        if(x+1<n && vis[x+1][y] == 0 && grid[x+1][y] == 1){
            dfs(grid,temp,x+1,y,vis,srcx,srcy,n,m);
        }
        if(y+1<m && vis[x][y+1] == 0 && grid[x][y+1] == 1){
            dfs(grid,temp,x,y+1,vis,srcx,srcy,n,m);
        }
        if(x-1>=0 && vis[x-1][y] == 0 && grid[x-1][y] == 1){
            dfs(grid,temp,x-1,y,vis,srcx,srcy,n,m);
        }
        if(y-1>=0 && vis[x][y-1] == 0 && grid[x][y-1] == 1){
            dfs(grid,temp,x,y-1,vis,srcx,srcy,n,m);
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int,int>>> s;
        vector<pair<int,int>> temp;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    dfs(grid,temp,i,j,vis,i,j,n,m);
                    s.insert(temp);
                    temp.clear();
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends