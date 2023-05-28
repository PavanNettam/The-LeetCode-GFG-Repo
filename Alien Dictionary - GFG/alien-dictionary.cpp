//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<char> adj[K];
        for(int i=0;i<N-1;i++){
            int f = 0;
            int s = 0;
            while(f<dict[i].size() && s<dict[i+1].size() && dict[i][f]==dict[i+1][s]){
                f++;
                s++;
            }
            if(f<dict[i].size() && s<dict[i+1].size()){
                //cout<<i<<" "<<dict[i][f]<<" "<<dict[i+1][s]<<endl;
                adj[dict[i][f]-'a'].push_back(dict[i+1][s]);
            }
        }
        // for(int i=0;i<K;i++){
        //     for(auto j:adj[i]){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        string s = "";
        vector<int> in(K,0);
        for(int i=0;i<K;i++){
            for(auto j:adj[i]){
                in[j-'a']++;
            }
        }
        queue<char> q;
        for(int i=0;i<K;i++){
            if(in[i] == 0){
                q.push(char(97+i));
            }
        }
        while(!q.empty()){
            char ele = q.front();
            q.pop();
            s += ele;
            for(auto i:adj[ele-'a']){
                in[i-'a']--;
                if(in[i-'a']==0){
                    q.push(i);
                }
            }
        }
        //cout<<s;
        return s;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends