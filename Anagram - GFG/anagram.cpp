//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        map<int,int> ma,mb;
        if(a.size()!=b.size()) return 0;
        for(int i=0;i<a.size();i++){
            ma[a[i]]++;
        }
        for(int i=0;i<b.size();i++){
            mb[b[i]]++;
        }
        for(auto i:ma){
            if(mb[i.first] != i.second){
                return 0;
            }
        }
        return 1;
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends