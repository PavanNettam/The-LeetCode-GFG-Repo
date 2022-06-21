class Solution {
public:
    int xorOperation(int n, int start) {
        vector <int> nums(n);
      
        for(int i=0;i<n;i++){
            nums[i]=start+(2*i);
            
        }
        int ans = nums[0];
        for(int j=1;j<n;j++){
            ans = ans ^ nums[j];
        }
        return ans;
    }
};