class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int i=0;
        int j=0;
        int m = matrix.size();
        int n = matrix[0].size();
        int count = m*n;
        while(count!=1){
            
            while(j<n-1 && matrix[i][j+1] != 101){
                ans.push_back(matrix[i][j]);
                matrix[i][j] = 101;
                j++;count--;
            }
            while(i<m-1 && matrix[i+1][j] != 101){
                ans.push_back(matrix[i][j]);
                matrix[i][j] = 101;
                i++;count--;
            }
            while(j>0 && matrix[i][j-1] != 101){
                ans.push_back(matrix[i][j]);
                matrix[i][j] = 101;
                j--;count--;
            }
            while(i>0 && matrix[i-1][j] != 101){
                ans.push_back(matrix[i][j]);
                matrix[i][j] = 101;
                i--;count--;
            }
        }
        ans.push_back(matrix[i][j]);
        return ans;
    }
};