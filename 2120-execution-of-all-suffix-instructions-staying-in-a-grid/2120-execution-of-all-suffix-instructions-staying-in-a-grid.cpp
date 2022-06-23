class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.size();
        vector<int> ans(m,0);
        for(int i=0;i<m;i++){
            int r = startPos[0];
            int c = startPos[1];
            int count = 0;
            for(int j=i;j<m;j++){
                if(s[j] == 'U'){
                    if(r-1 >= 0) r--;
                    else break;
                }else if(s[j] == 'D'){
                    if(r+1 < n) r++;
                    else break;
                }else if(s[j] == 'R'){
                    if(c+1 < n) c++;
                    else break;
                }else{
                    if(c-1 >= 0) c--;
                    else break;
                }
                count++;
            }
            ans[i] = count;
        }
        return ans;
    }
};