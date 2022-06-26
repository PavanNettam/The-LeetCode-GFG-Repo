class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(1);
        ans.push_back(temp);
        if(numRows == 1) return ans;
        for(int i=2;i<=numRows;i++){
            vector<int> temp;
           
            temp.push_back(1);
            for(int j=2;j<i;j++){
                
                temp.push_back(ans[i-1-1][j-1]+ans[i-1-1][j-1-1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};