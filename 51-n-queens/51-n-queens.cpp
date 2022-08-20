class Solution {
public:
    void solve(vector<vector<string>>& ans, vector<string>& board, vector<int>& leftRow, vector<int>& upperDgl, vector<int>& lowerDgl,int col,int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftRow[row] == 0 && upperDgl[n-1+col-row] == 0 && lowerDgl[col+row] == 0){
                leftRow[row] = 1;
                upperDgl[n-1+col-row] = 1;
                lowerDgl[col+row] = 1;
                board[row][col] = 'Q';
                solve(ans,board,leftRow,upperDgl,lowerDgl,col+1,n);
                leftRow[row] = 0;
                upperDgl[n-1+col-row] = 0;
                lowerDgl[col+row] = 0;
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> board;
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        vector<int> leftRow(n,0);
        vector<int> upperDgl(2*n-1,0);
        vector<int> lowerDgl(2*n-1,0);
        solve(ans,board,leftRow,upperDgl,lowerDgl,0,n);
        return ans;
    }
};
/*
upper diagonal can simply be represented as (n-1+col-row)
lower diagonal as (col+row)
left row as row itself
*/