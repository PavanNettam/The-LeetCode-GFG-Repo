class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==1) return 0;
        int l = 0;
        int r = n-1;
        int leftMax = height[l];
        int rightMax = height[r];
        int water = 0;
        while(l<r){
            if(height[l]<height[r]){
                if(height[l]>leftMax){
                    leftMax = height[l];
                }else{
                    water += (leftMax-height[l]);
                }
                l++;
            }else{
                if(height[r]>rightMax){
                    rightMax = height[r];
                }else{
                    water += (rightMax-height[r]);
                }
                r--;
            }
        }
        return water;
    }
};
