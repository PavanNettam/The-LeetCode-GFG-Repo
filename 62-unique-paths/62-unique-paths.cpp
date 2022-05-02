class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 && n==1) return 1; //If only one cell then only one path.
        
        int arr[m][n]; //dp table
        
        //Making 0th row and column elements as 1 as there is only one path
        //from 0,0 to any of these cells
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i== 0) arr[i][j] = 1;
                else if(j == 0) arr[i][j] = 1;
                else arr[i][j] = 0;
            }
        }
        
        //A particular cell can be reached in only two possible ways 
        //1. From the cell just above it
        //or 
        //2. From the cell just left to it
        // so each of these ways can be considered as different pahts: 
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                arr[i][j] = arr[i-1][j] + arr[i][j-1];
            }
        }
        
        return arr[m-1][n-1];
    }
};