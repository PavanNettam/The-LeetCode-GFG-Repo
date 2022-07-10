class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> p;
        for(int i=1;i<=m;i++){
            p.push_back(i);
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int j;
            for(j=0;j<m;j++){
                if(p[j]==queries[i]){
                    ans.push_back(j);
                    break;
                }
            }
            while(j>0){
                p[j] = p[j-1];
                j--;
            }
            p[j] = queries[i];
        }
        return ans;
    }
};