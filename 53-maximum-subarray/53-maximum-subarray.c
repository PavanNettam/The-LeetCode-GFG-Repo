

int maxSubArray(int* nums, int numsSize){
    int sum = nums[0];
    int temp = 0;
    for(int i=0;i<numsSize;i++){
        temp += nums[i];
        if(temp>sum){
            sum = temp;
        }
        //temp += nums[i];
        if(temp<0){
            temp = 0;
        }
    }
    return sum;
}