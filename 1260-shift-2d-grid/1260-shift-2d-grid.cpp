class Solution {
public:
    void swift(vector<int>& v){
        int n = v.size();
        int store = v[n-1];
        for(int i=v.size()-1;i>0;i--){
            v[i] = v[i-1];
        }
        v[0] = store;
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> v;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                v.push_back(grid[i][j]);
            }
        }
        for(int i=0;i<k;i++){
            swift(v);
        }
        int c=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                grid[i][j] = v[c];
                c++;
            }
        }
        return grid;
    }
};