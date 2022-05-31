class Solution {
public:
    
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return;
        int flag = 0;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                flag = 1;
            }
        }
        for(int i=0;i<n;i++){
            cout<<"c1"<<endl;
            cout<<nums[i]<<endl;
        }
        if(flag == 0){
            reverse(nums.begin(),nums.end());
            return;
        }
        int i=n-2;
        while(nums[i+1]<=nums[i]){
            i--;
        }
        for(int i=0;i<n;i++){
            cout<<"c2"<<endl;
            cout<<nums[i]<<endl;
        }
        int j = n-1;
        while(nums[j]<=nums[i]){
            j--;
        }
        for(int i=0;i<n;i++){
            cout<<"c3"<<endl;
            cout<<nums[i]<<" "<<j<<endl;
        }
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        reverse(nums.begin()+i+1,nums.end());
        for(int i=0;i<n;i++){
            cout<<"c4"<<endl;
            cout<<nums[i]<<endl;
        }
    }
};