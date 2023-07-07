//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int N, vector<int>& arr) {
        stack<int> s;
        vector<int> ans(N,INT_MAX);
        for(int i=0;i<2*N-1;i++){
            while(!s.empty() && arr[s.top()] < arr[i%N]){
                ans[s.top()] = arr[i%N];
                s.pop();
            }
            s.push(i%N);
        }
        while(!s.empty()){
            if(ans[s.top()] == INT_MAX) ans[s.top()] = -1;
            s.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends