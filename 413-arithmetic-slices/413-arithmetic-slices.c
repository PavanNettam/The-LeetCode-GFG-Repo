

int numberOfArithmeticSlices(int* nums, int numsSize){
    if(numsSize<3) return 0;
    int count = 0;
    for(int i=0;i<numsSize-1;i++){
        int diff = nums[i+1] - nums[i];
        int len = 1;
        for(int j=i+1;j<numsSize;j++){
            if(diff == nums[j]-nums[j-1]){
                len++;
                if(len >= 3){
                    count++;
                }
            }else{
                break;
            }
        }
    }
    return count;
}