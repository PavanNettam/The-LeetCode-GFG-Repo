class Solution {
public:
    int isValid(vector<string>& temp, int& row, int& col, int &n){
        for(int i=0;i<row;i++){
            if(temp[i][col] == 'Q') return 0;
        }
        for(int i=row-1,j=col-1;j>=0 && i>=0;i--,j--){
            if(temp[i][j] == 'Q') return 0;
        }
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(temp[i][j] == 'Q') return 0;
        }
        return 1;
    }
    void solve(vector<vector<string>>&ans, vector<string>& temp, int row, int& n){
        if(row == n){
            ans.push_back(temp);
            return;
        }
        for(int col = 0;col<n;col++){
            if(isValid(temp,row,col,n)){
                temp[row][col] = 'Q';
                solve(ans,temp,row+1,n);
                temp[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n, string(n, '.'));
        solve(ans,temp,0,n);
        return ans;
    }
};