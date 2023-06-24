//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        int i = 0;
        int ans = 0;
        set<pair<int,int>> s; //{time,ele}
        for(int i=0;i<N;i++){
            auto it = s.begin();
            for(;it!=s.end();it++){
                auto ele = *it;
                if(ele.second == pages[i]){
                    break;
                }
            }
            if(it == s.end()){
                if(s.size() == C){
                    s.erase(s.begin());
                }
                s.insert({i,pages[i]});
                ans++;
            }else{
                s.erase(it);
                s.insert({i,pages[i]});
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends