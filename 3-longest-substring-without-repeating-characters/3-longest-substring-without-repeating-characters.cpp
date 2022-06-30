class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> temp;
        int l = 0;
        int r = 0;
        int count = 0;
        int ans = 0;
        while(r<s.size()){
            if(temp.find(s[r]) == temp.end() || temp[s[r]] == 0){
                count++;
                temp[s[r]] = 1;
                ans = max(ans,count);
                r++;
            }else{
                temp[s[l]]--;
                l++;
                count--;
            }
        }
        return ans;
    }
};