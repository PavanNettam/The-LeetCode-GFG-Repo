class Solution {
public:
    static int sortBy(vector<int> a, vector<int> b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        if(n==1) return intervals;
        sort(intervals.begin(),intervals.end(),sortBy);
        int l = 0;
        int r = l;
        while(l<n){
            vector<int> temp;
            temp.push_back(intervals[l][0]);
            int maxi = intervals[l][1];
            while(r<n && intervals[r][0]<=maxi){
                maxi = (maxi>intervals[r][1])?maxi:intervals[r][1];
                r++;
            }
            temp.push_back(maxi);
            ans.push_back(temp);
            l = r;
        }
        return ans;
    }
};