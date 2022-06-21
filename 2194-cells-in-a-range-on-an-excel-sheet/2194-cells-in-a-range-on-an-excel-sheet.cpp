class Solution {
public:
    vector<string> cellsInRange(string s) {
        int row1 = s[1];
        int col1 = s[0];
        int row2 = s[4];
        int col2 = s[3];
        vector<string> ans;
        for(int i=col1;i<=col2;i++){
            for(int j=row1;j<=row2;j++){
                //cout<<row1<<" "<<row2<<endl;
                char n = (char)i;
                char m = (char)j;
                string k = "";
                k = k+n+m;
                cout<<char(i)<<" "<<char(j)<<endl;
                ans.push_back(k);
            }
        } 
        return ans;
    }
};