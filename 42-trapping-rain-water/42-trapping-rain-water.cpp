class Solution {
public:
    int trap(vector<int>& height) {
        //Two pointer approach
        int n = height.size();
        int left = 0;
        int right = n-1;
        int ans = 0;
        int leftMax = INT_MIN;
        int rightMax = INT_MIN;
        while(left<right){
            if(height[left]<height[right]){
                if(leftMax<height[left]) leftMax = height[left];
                else ans += leftMax-height[left];
                left++;
            }else{
                if(rightMax<height[right]) rightMax = height[right];
                else ans += rightMax-height[right];
                right--;
            }
        }
        return ans;
    }
};