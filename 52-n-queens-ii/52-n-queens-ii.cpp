class Solution {
public:
    int isValid(vector<vector<int>>& b,int& row,int& col,int& n){
        for(int i=0;i<row;i++){
            if(b[i][col] == 1) return 0;
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(b[i][j] == 1) return 0;
        }
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(b[i][j] == 1) return 0;
        }
        return 1;
    }
    void total(vector<vector<int>>& b,int row,int& n,int& count){
        if(row == n){
            count++;
            return;
        }
        for(int col=0;col<n;col++){
            if(isValid(b,row,col,n)){
                b[row][col] = 1;
                total(b,row+1,n,count);
                b[row][col] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        if(n==1) return 1;
        int count = 0;
        total(board,0,n,count);
        return count;
    }
};