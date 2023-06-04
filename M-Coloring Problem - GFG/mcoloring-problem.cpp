//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    int canColor(int cur, int thisColor, bool graph[101][101],vector<int> col,int n){
        for(int j=0;j<n;j++){
            if(graph[cur][j] == 1){
                if(col[j] == thisColor) return 0;
            }
        }
        return 1;
    }
    int solve(bool graph[101][101], int m, int n, vector<int> &col,int cur){
        if(cur == n) return 1;
            for(int i=1;i<=m;i++){
                if(canColor(cur,i,graph,col,n)){
                    col[cur] = i;
                    if(solve(graph,m,n,col,cur+1)) return 1;
                    col[cur] = 0;
                }
            }
        return 0;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> col(n);
        return solve(graph,m,n,col,0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends