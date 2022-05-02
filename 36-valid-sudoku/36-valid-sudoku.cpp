class Solution {
public:
    int arr[10];
    void reset(){
        for(int i=0;i<10;i++){
            arr[i] = 0;
        }
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            reset();
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') {
                    continue;
                }
                if(arr[board[i][j]-'1'] != 0){
                    return 0;
                }
                else{
                    arr[board[i][j]-'1'] = 1;
                }
            }
        }
                       
        for(int i=0;i<9;i++){
            reset();
            for(int j=0;j<9;j++){
                if(board[j][i] == '.'){
                       continue;
                }
                if(arr[board[j][i]-'1'] != 0) {
                    return 0;
                }
                else {
                    arr[board[j][i]-'1'] = 1;
                }
            }
        }
        for(int k=0;k<9;k++){
            reset();
            int m,n;
            if(k==0){
                m=0;
                n=0;
            }else if(k==1){
                m=0;
                n=3;
            }else if(k==2){
                m=0;
                n=6;
            }else if(k==3){
                m=3;
                n=0;
            }else if(k==4){
                m=3;
                n=3;
            }else if(k==5){
                m=3;
                n=6;
            }else if(k==6){
                m=6;
                n=0;
            }else if(k==7){
                m=6;
                n=3;
            }else if(k==8){
                m=6;
                n=6;
            }
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    //if(m== 6 && n==6) cout<<board[i+m][j+n];
                    if(board[i+m][j+n] == '.') continue;
                    if(arr[board[i+m][j+n]-'1'] != 0) return 0;
                    else arr[board[i+m][j+n]-'1'] = 1;
                }
            }
                           
        }
    return 1;
    }
};