class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;
        int ans=0;
        int l=0;
        int r=0;
        vector<int> f(256,0);
        while(r<s.length()){
            if(f[s[r]] == 0){
                f[s[r]]++;
                len++;
                ans = max(ans,len);
                r++;
            }else{
                f[s[l]]--;
                len--;
                l++;
            }
        }
        return ans;
    }
};