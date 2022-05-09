class Solution {
public:
    string s[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    int n;
    vector<string> letterCombinations(string digits) {
        n = digits.length();
        if(n==0) return ans;
        solve(0, digits,"");
        return ans;
    }
    
    void solve(int i, string digits, string res){        
        if(i==n){
            ans.push_back(res);
            return;
        }
        
        for(int j=0;j<s[ digits[i] - '0' ].length();j++){
            solve(i+1, digits, res + s[ digits[i] - '0' ][j]);
        }
    }
};