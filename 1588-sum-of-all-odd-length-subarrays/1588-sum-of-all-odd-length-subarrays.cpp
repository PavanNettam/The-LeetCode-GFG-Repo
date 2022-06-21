class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j+=2){
                int sum = 0;
                for(int k=i;k<=j;k++){
                    sum += arr[k];
                }
                ans+=sum;
            }
        }
        return ans;
    }
};