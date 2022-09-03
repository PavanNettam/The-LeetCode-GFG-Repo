class Solution {
public:
    void solve(vector<vector<char>>& grid,vector<vector<int>>& visited,int color, int i,int j,int n,int m){
        visited[i][j] = color;
        if(i-1>=0 && grid[i-1][j]=='1' && visited[i-1][j]==0){
            solve(grid,visited,color,i-1,j,n,m);
        }
        if(j+1<m && grid[i][j+1]=='1' && visited[i][j+1]==0){
            solve(grid,visited,color,i,j+1,n,m);
        }
        if(i+1<n && grid[i+1][j]=='1' && visited[i+1][j]==0){
            solve(grid,visited,color,i+1,j,n,m);
        }
        if(j-1>=0 && grid[i][j-1]=='1' && visited[i][j-1]==0){
            solve(grid,visited,color,i,j-1,n,m);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    ans++;
                    solve(grid,visited,ans,i,j,n,m);
                }
            }
        }
        return ans;
    }
};