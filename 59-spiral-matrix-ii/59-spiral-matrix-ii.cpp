class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j] = 0;
            }
        }
        int i=0;
        int j=0;
        int k = 1;
        while(k < n*n){
            cout<<k<<endl;
            while(j+1<n && arr[i][j+1]==0){
                arr[i][j] = k;
                k++;
                j++;
            }
            while(i+1<n && arr[i+1][j]==0){
                arr[i][j] = k;
                k++;
                i++;
            }
            while(j-1>=0 && arr[i][j-1]==0){
                arr[i][j] = k;
                k++;
                j--;
            }
            while(i-1>=0 && arr[i-1][j]==0){
                arr[i][j] = k;
                k++;
                i--;
            }
        }
        arr[i][j] = k;
        return arr;
    }
};