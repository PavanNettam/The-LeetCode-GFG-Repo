//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void dfs(int x,int y,vector<vector<int>>& matrix,vector<vector<int>>& vis,int &c, int n,int m){
        vis[x][y] = 1;
        vector<int> dr = {0,1,0,-1};
        vector<int> dc = {1,0,-1,0};
        for(int i=0;i<dr.size();i++){
            int row = x+dr[i];
            int col = y+dc[i];
            if(row>=0 && row<n && col>=0 && col<m){
                if(matrix[row][col] == 1 && vis[row][col]==0){
                    dfs(row,col,matrix,vis,c,n,m);
                }
            }else{
                c = 0;
            }
        }
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        vector<vector<int>> vis(N, vector<int> (M,0));
        int count = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(matrix[i][j] == 1 && vis[i][j]==0){
                    int shouldCount = 1;
                    dfs(i,j,matrix,vis,shouldCount,N,M);
                    if(shouldCount==1){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends