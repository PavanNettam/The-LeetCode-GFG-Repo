class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> arr;
        vector<int> pos;
        vector<int> neg;
        
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i] < 0){
                neg.push_back(nums[i]);
            }else{
                pos.push_back(nums[i]);
            }
        }
        cout<<"here"<<endl;
        int i=0;
        n = pos.size();
        while(i<n){
            arr.push_back(pos[i]);
            arr.push_back(neg[i]);
            i++;
        }
        return arr;
    }
};