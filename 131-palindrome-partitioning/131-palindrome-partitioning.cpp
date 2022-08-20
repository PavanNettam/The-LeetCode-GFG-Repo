class Solution {
public:
    bool isPalindrome(string str, int s, int e){
        while(s<=e){
            if(str[s++] != str[e--]) return 0;
        }
        return 1;
    }
    void subpart(string s, vector<vector<string>>& ans, vector<string>& temp, int idx){
        if(idx == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(isPalindrome(s,idx,i)){
                temp.push_back(s.substr(idx,i-idx+1));
                subpart(s,ans,temp,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        subpart(s,ans,temp,0);
        return ans;
    }
};