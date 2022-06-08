class Solution {
public:
    void countSort(vector<int>& nums,int n,int exp){
        vector<int> count(10,0);
        vector<int> temp(n,0);
        for(int i=0;i<n;i++){
            count[(nums[i]/exp)%10]++;
        }
        for(int i=1;i<10;i++){
            count[i] += count[i-1];
        }
        
        for(int i=n-1;i>=0;i--){
            temp[count[(nums[i]/exp)%10]-1] = nums[i];
            count[(nums[i]/exp)%10]--;
        }
        for(int i=0;i<n;i++){
            nums[i] = temp[i];
        }
    }
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return 0;
        int maxi = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>maxi) maxi = nums[i];
        }
        for(int exp=1;maxi/exp > 0;exp*=10){
            countSort(nums,n,exp);
        }
        int maxDiff = 0;
        for(int i=1;i<n;i++){
            int temp = nums[i]-nums[i-1];
            if(temp > maxDiff){
                maxDiff = temp;
            }
        }
        return maxDiff;
    }
    
};