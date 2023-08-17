class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m,0));
        vector<vector<int>> temp(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    temp[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            int i = ele.first.first;
            int j = ele.first.second;
            int d = ele.second;
            ans[i][j] = d;
            if(i+1 < n && temp[i+1][j] == 0){
                q.push({{i+1,j},d+1});
                temp[i+1][j] = 1;
            }
            if(j+1 < m && temp[i][j+1] == 0){
                q.push({{i,j+1},d+1});
                temp[i][j+1] = 1;
            }
            if(i-1 >= 0 && temp[i-1][j] == 0){
                q.push({{i-1,j},d+1});
                temp[i-1][j] = 1;

            }
            if(j-1 >= 0 && temp[i][j-1] == 0){
                q.push({{i,j-1},d+1});
                temp[i][j-1] = 1;
            }
        }
        return ans;
    }
};