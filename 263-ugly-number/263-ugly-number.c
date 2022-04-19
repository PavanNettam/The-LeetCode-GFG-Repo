

bool isUgly(int n){
    if(n==1) return 1;
    if(n<=0) return 0;
    int d = 2;
    int success = 1;
    while(n!=1 && n!=-1){
        while(n%d == 0){
            n/=d;
        }
        if(d>5){
            success = 0;
            break;
        }
        d++;
    }
    return success;
}