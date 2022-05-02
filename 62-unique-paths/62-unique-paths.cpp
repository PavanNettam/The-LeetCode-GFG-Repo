class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 && n==1) return 1;
        int arr[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i== 0) arr[i][j] = 1;
                else if(j == 0) arr[i][j] = 1;
                else arr[i][j] = 0;
            }
        }
        arr[0][0] = 0;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                arr[i][j] = arr[i-1][j] + arr[i][j-1];
            }
        }
        return arr[m-1][n-1];
    }
};