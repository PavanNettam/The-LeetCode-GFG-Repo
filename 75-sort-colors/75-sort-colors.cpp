class Solution {
public:
    //Duch national flag
    void swap(int& a,int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void sortColors(vector<int>& nums) {
        int mid = 0;
        int l = 0;
        int h=nums.size()-1;
        while(mid<=h){
            if(nums[mid] == 0){
                swap(nums[mid],nums[l]);
                l++;mid++;
            }else if(nums[mid] == 1){
                mid++;
            }else{
                swap(nums[mid],nums[h]);
                h--;
            }
        }
    }
};