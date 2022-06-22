class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==1) return 0;
        
        vector<int> l(n,height[0]);
        vector<int> r(n,height[n-1]);
        for(int i=1;i<n;i++){
            l[i] = max(height[i],l[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            r[i] = max(height[i],r[i+1]);
        }
        int water = 0;
        for(int i=0;i<n;i++){
            int h = min(l[i],r[i]);
            int neth = h-height[i];
            water += neth;
        }
        return water;
    }
};