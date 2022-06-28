class Solution {
public:
    int count = 0;
    void merge(vector<int>& nums, int l, int mid, int r){
        int i=l;
        int j=mid+1;
        int n=mid+1;
        int m=r+1;
        while(i<n && j<m){
            if(long(nums[i]) > 2*long(nums[j])){
                count += (n-i);
                j++;
            }else{
                i++;
            }
        }
        sort(nums.begin()+l,nums.begin()+r+1);
    }
    void mergeSort(vector<int>& nums, int l, int r){
        if(l<r){
            int mid = (l+r)/2;
            mergeSort(nums,l,mid);
            mergeSort(nums,mid+1,r);
            merge(nums,l,mid,r);
        }
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return count;
    }
};