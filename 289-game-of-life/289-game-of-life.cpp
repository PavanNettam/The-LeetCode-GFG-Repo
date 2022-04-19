class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> v(m,vector<int>(n));
        int a1,a2,a3,a4,a5,a6,a7,a8;
        cout<<m<<" "<<n<<endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i-1 >= 0 && j-1 >= 0 && i+1 < m && j+1 < n){
                    a1 = board[i-1][j-1];
                    a2 = board[i-1][j];
                    a3 = board[i-1][j+1];
                    a4 = board[i][j-1];
                    a5 = board[i][j+1];
                    a6 = board[i+1][j-1];
                    a7 = board[i+1][j];
                    a8 = board[i+1][j+1];
                }else if(i-1 >= 0 && j-1 >= 0 && i+1 >= m && j+1 >= n){
                    a1 = board[i-1][j-1];
                    a2 = board[i-1][j];
                    a3 = 0;
                    a4 = board[i][j-1];
                    a5 = 0;
                    a6 = 0;
                    a7 = 0;
                    a8 = 0;
                }else if(i-1 >= 0 && j-1 >= 0 && i+1 >= m && j+1 < n){
                    a1 = board[i-1][j-1];
                    a2 = board[i-1][j];
                    a3 = board[i-1][j+1];
                    a4 = board[i][j-1];
                    a5 = board[i][j+1];
                    a6 = 0;
                    a7 = 0;
                    a8 = 0;
                }else if(i-1 >= 0 && j-1 >= 0 && i+1 < m && j+1 >= n){
                    a1 = board[i-1][j-1];
                    a2 = board[i-1][j];
                    a3 = 0;
                    a4 = board[i][j-1];
                    a5 = 0;
                    a6 = board[i+1][j-1];
                    a7 = board[i+1][j];
                    a8 = 0;
                }else if(i-1 < 0 && j-1 >= 0 && i+1 < m && j+1 < n){
                    a1 = 0;
                    a2 = 0;
                    a3 = 0;
                    a4 = board[i][j-1];
                    a5 = board[i][j+1];
                    a6 = board[i+1][j-1];
                    a7 = board[i+1][j];
                    a8 = board[i+1][j+1];
                }else if(i-1 >= 0 && j-1 < 0 && i+1 < m && j+1 < n){
                    a1 = 0;
                    a2 = board[i-1][j];
                    a3 = board[i-1][j+1];
                    a4 = 0;
                    a5 = board[i][j+1];
                    a6 = 0;
                    a7 = board[i+1][j];
                    a8 = board[i+1][j+1];
                }else if(i-1 < 0 && j-1 >= 0 && i+1 < m && j+1 >= n){
                    a1 = 0;
                    a2 = 0;
                    a3 = 0;
                    a4 = board[i][j-1];
                    a5 = 0;
                    a6 = board[i+1][j-1];
                    a7 = board[i+1][j];
                    a8 = 0;
                }else if(i-1 >= 0 && j-1 < 0 && i+1 >= m && j+1 < n){
                    a1 = 0;
                    a2 = board[i-1][j];
                    a3 = board[i-1][j+1];
                    a4 = 0;
                    a5 = board[i][j+1];
                    a6 = 0;
                    a7 = 0;
                    a8 = 0;
                }else if(i-1 < 0 && j-1 < 0 && i+1 < m && j+1 < n){
                    a1 = 0;
                    a2 = 0;
                    a3 = 0;
                    a4 = 0;
                    a5 = board[i][j+1];
                    a6 = 0;
                    a7 = board[i+1][j];
                    a8 = board[i+1][j+1];
                }
                int sum = a1+a2+a3+a4+a5+a6+a7+a8;
                cout<<a1<<a2<<a3<<a4<<a5<<a6<<a7<<a8<<endl;
                if(board[i][j] == 1){
                    if(sum<2) v[i][j] = 0;
                    else if(sum == 2 || sum == 3) v[i][j] = 1;
                    else v[i][j] = 0;
                }else if(board[i][j] == 0){
                    if(sum == 3) v[i][j] = 1;
                    else v[i][j] = 0;
                }
                cout<<i<<" "<<j<<endl;
            }
        }
        cout<<m<<" "<<n<<endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<i<<" "<<j<<" "<<"before"<<endl;
                board[i][j] = v[i][j];
                cout<<i<<" "<<j<<" "<<"after"<<endl;
            }
        }
    }
};