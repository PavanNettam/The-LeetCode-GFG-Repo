//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>> q;
        int mod = 100000;
        q.push({start,0});
        vector<int> dist(100000,1000000);
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int node = temp.first;
            int nodeDist = temp.second;
            for(int i=0;i<arr.size();i++){
                int nextNode = (arr[i]*node)%mod;
                int edgeDist = 1;
                if(nodeDist+edgeDist < dist[nextNode]){
                    dist[nextNode] = nodeDist+edgeDist;
                    q.push({nextNode,dist[nextNode]});
                }
            }
        }
        if(dist[end] >= 1000000) return -1;
        return dist[end];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends