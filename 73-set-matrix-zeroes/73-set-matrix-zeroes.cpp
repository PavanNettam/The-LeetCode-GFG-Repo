class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int row0 = 1;
        int col0 = 1;
        if(matrix[0][0] == 0){
            row0=0;
            col0=0;
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0){
                    if(matrix[i][j] == 0) {
                        row0=0;
                    }
                }
                else if(j==0){
                    if(matrix[i][j] == 0) {
                        col0=0;
                    }
                }
                else if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<row0<<col0<<endl;
        if(row0 == 0 || col0 == 0){
           matrix[0][0] = 0;
        }
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                if(i == 0){
                    if(row0 == 0) matrix[i][j] = 0;
                }else if(j==0){
                    if(col0==0) matrix[i][j] = 0;
                }
                else if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
       
    }
};