class Solution {
public:
    int help(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& h)
    {
        if(h[i][j] != -1) return h[i][j];
        int x[] = {0,0,1,-1};
        int y[] = {1,-1,0,0};
        int tmp_ans = 0;
        for(int n = 0; n < 4; n++)
        {
            int new_i = x[n] + i;
            int new_j = y[n] + j;
            if(new_i >= 0 && new_j >= 0 && new_i < matrix.size() && new_j < matrix[i].size()) 
            {
                if(matrix[new_i][new_j] > matrix[i][j])
                tmp_ans = max(tmp_ans,1+help(matrix,new_i,new_j,h));
            }
        }
        h[i][j] = tmp_ans;
        return h[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> h (matrix.size(),vector<int>(matrix[0].size(),-1));
        
        
        
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
               ans = max(ans,1+help(matrix,i,j,h));
            }
        }
        return ans;
    }
};