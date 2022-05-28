class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int arr[n+1];
        for(int i=0;i<n+1;i++){
            arr[i] = 0;
        }
        //cout<<n<<endl;
        for(int i=0;i<n;i++){
            //cout<<nums[i]<<endl;
            arr[nums[i]]++;
        }
        for(int i=0;i<n+1;i++){
            if(arr[i] == 0) return i;
        }
        return -1;
    }
};