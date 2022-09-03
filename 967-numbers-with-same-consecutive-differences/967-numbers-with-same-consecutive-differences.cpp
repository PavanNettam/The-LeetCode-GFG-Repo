class Solution {
public:
    void dfs(int n,int k,vector<int>& ans, int temp,int cur){
        if(n==0){
            ans.push_back(temp);
            return;
        }
        if(cur-k >= 0){
            int next = cur-k;
            dfs(n-1,k,ans,(temp*10) + next,next);
        }
        if(cur+k < 10 && k!=0){
            int next = cur+k;
            dfs(n-1,k,ans,(temp*10) + next,next);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        
        for(int i=1;i<10;i++){
            dfs(n-1,k,ans,i,i);
        }
        
        return ans;
    }
};