class Solution {
public:
    int trap(vector<int>& height) {
        //DP approach
        int n = height.size();
        int ans = 0;
        vector<int> left(n),right(n);
        left[0] = height[0];
        for(int i=1;i<n;i++){
            left[i] = (left[i-1]>height[i])?left[i-1]:height[i];
        }
        right[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i] = (right[i+1]>height[i])?right[i+1]:height[i];
        }
        for(int i=0;i<n;i++){
            int mini = (right[i]<left[i])?right[i]:left[i];
            ans += mini-height[i];
        }
        return ans;
    }
};