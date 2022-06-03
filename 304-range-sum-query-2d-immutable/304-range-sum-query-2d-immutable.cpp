class NumMatrix {
public:
    vector<vector<int>> ans;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        ans.resize(n+1, vector<int>(m+1, 0));
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                //cout<<i<<j<<endl;
                ans[i][j] = ans[i-1][j]+ans[i][j-1]+matrix[i-1][j-1]-ans[i-1][j-1];
            }
        }
        //cout<<ans[2][2]<<endl;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int a = row1+1;
        int b = col1+1;
        int c = row2+1;
        int d = col2+1;
        return ans[c][d]-ans[c][b-1]-ans[a-1][d]+ans[a-1][b-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */