class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int maxi = INT_MIN;
        while(l<r){
            int minh = (height[l]<height[r])?height[l]:height[r];
            int temp = minh*(r-l);
            maxi = (maxi>temp)?maxi:temp;
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxi;
    }
};