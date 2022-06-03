// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         sort(intervals.begin(), intervals.end());
         int n = intervals.size();
         vector<vector<int>> ans;
         for(int i=0;i<n;i++){
             int first = intervals[i][0];
             int second = intervals[i][1];
             while(i+1<n && intervals[i+1][0] <= second){
                i++;
                second = (second>intervals[i][1])?second:intervals[i][1];
             }
             vector<int> v;
             v.push_back(first);
             v.push_back(second);
             ans.push_back(v);
         }
         return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends