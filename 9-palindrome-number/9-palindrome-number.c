

bool isPalindrome(int x){
    if(x<0){
        return 0;
    }
    long int copy = x;
    long int new = 0;
    while(copy>0){
        new = (new*10) + (copy%10);
        copy /= 10;
    }
    if(x == new) return 1;
    else return 0;
}