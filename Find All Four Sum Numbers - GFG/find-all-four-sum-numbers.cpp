// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>> ans;
        int n = arr.size();
        if(n<4) return ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int l = j+1;
                int r = n-1;
                int t = k-arr[i]-arr[j];
                while(l<r){
                    if(arr[l]+arr[r]<t){
                        l++;
                    }else if(arr[l]+arr[r]>t){
                        r--;
                    }else{
                        vector<int> temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[l]);
                        temp.push_back(arr[r]);
                        ans.push_back(temp);
                        
                        while(l<r && arr[l]==arr[l+1]) l++;
                        while(l<r && arr[r-1]==arr[r]) r--;
                        
                        l++;
                        r--;
                    }
                   
                }
    
                while(j < n-2 && arr[j]==arr[j+1]) j++;

            }
            while(i < n-3 && arr[i]==arr[i+1]) i++;
            
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends