

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize){
    int len=0;
    int* ptr = (int*)malloc(10000*sizeof(int));
    for(int i=left;i<=right;i++){
        int copy = i;
        int found = 1;
        while(copy>0){
            int num = copy%10;
            copy /= 10;
            if(num ==0 || i%num != 0){
                found = 0;
                break;
            }
        }
        if(found == 1){
            printf("%d ",i);
            ptr[len]=i;
            len++;
        }
    }
    *returnSize = len;
    return ptr;
}