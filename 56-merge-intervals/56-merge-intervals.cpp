class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
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