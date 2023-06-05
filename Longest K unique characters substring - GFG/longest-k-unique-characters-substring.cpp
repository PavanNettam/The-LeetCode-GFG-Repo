//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int maxi = -1;
        map<char,int> m;
        int l = 0;
        int n = s.size();
        for(int r=0;r<n;r++){
            m[s[r]]++;
            while(m.size()>k && l<=r){
                m[s[l]]--;
                if(m[s[l]] == 0){
                    m.erase(s[l]);
                }
                l++;
            }
            if(m.size()==k)
            maxi = max(maxi,r-l+1);
        }
        if(maxi == 0 || maxi==-1) return -1;
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends