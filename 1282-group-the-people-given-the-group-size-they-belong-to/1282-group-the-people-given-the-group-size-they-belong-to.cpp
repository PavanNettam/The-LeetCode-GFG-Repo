class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<int> valid(n,1);
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            int count = groupSizes[i];
            vector<int> temp;
            for(int j=i;j<n;j++){
                if(groupSizes[i] == groupSizes[j] && count>0 && valid[j]==1){
                    valid[j] = 0;
                    temp.push_back(j);
                    count--;
                }
                if(count<=0) break;
            }
            if(temp.size()!=0) ans.push_back(temp);
        }
        return ans;
    }
};