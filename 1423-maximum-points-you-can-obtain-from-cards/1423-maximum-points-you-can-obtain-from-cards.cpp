class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int curr,n = cardPoints.size();
        //if(n==1) cardPoints[0];
        vector<int> sum(n);
        sum[0] = cardPoints[0];
        for(int i=1;i<n;i++){
            sum[i] = sum[i-1]+cardPoints[i];
        }
        if(n==k) return sum[n-1];
        int l=0;
        int r=(n-k)-1;
        int mini = INT_MAX;
        while(r<n){
            if(l==0) curr = sum[r];
            else curr = sum[r]-sum[l-1];
            mini = (mini<curr)?mini:curr;
            r++;l++;
        }
        return sum[n-1]-mini;
    }
};