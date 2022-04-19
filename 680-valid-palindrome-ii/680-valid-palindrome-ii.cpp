#include <cstring>
class Solution {
public:
    bool isPalan(int l,int r, string s){
        while(l<=r){
            if(s[l] == s[r]){
                l++;
                r--;
            }else{
                return 0;
            }
        }
        return 1;
    }
    bool validPalindrome(string s) {
        int l = 0;
        int r = 0;
        while(s[r] != '\0'){
            r++;
        }
        r--;
        while(l<=r){
            if(s[l] == s[r]){
                l++;
                r--;
            }else{
                return isPalan(l+1,r,s) || isPalan(l,r-1,s);
            }
        }
        return 1;
    }
};