class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1 = -1;
        int num2 = -1;
        int c1 = 0;
        int c2 = 0;
        for(int i=0;i<n;i++){
            if(num1 == nums[i]){
                c1++;
            }else if(num2 == nums[i]){
                c2++;
            }else if(c1 == 0){
                num1 = nums[i];
                c1++;
            }else if(c2 == 0){
                num2 = nums[i];
                c2++;
            }else{
                c1--;
                c2--;
            }
        }
        c1 = 0;
        c2 = 0;
        for(int i=0;i<n;i++){
            if(num1 == nums[i]) c1++;
            else if(num2 == nums[i]) c2++;
        }
        vector<int> ans;
        if(c1>n/3){
            ans.push_back(num1);
        }
        if(c2>n/3){
            ans.push_back(num2);
        }
        return ans;
    }
};