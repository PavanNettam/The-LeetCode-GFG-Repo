class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int maxi;
        vector<int> row(r);
        vector<int> col(c);
        
        for(int i=0;i<r;i++){
            maxi = grid[i][0];
            for(int j=1;j<c;j++){
                maxi = max(maxi,grid[i][j]);
            }
            row[i] = maxi;
        }
        
        for(int i=0;i<c;i++){
            maxi = grid[0][i];
            for(int j=1;j<r;j++){
                maxi = max(maxi,grid[j][i]);
            }
            col[i] = maxi;
        }
        
        int ans = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(col[j]!=grid[i][j] && row[i]!=grid[i][j]){
                    ans += min(col[j],row[i])-grid[i][j];
                }
            }
        }
        
        return ans;
    }
};