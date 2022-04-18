class Solution {
public:
    int reverse(int x) {
        if(x==0) return 0;
        int n = (x<0)?1:0;
        x = abs(x);
        long int ans = x%10;
        x /= 10;
        while(x>0){
            ans *= 10;
            ans += (x%10);
            x /= 10;
        }
        if(n == 1) ans = ans - 2*ans;
        if(ans < -2147483648 || ans > 2147483647) ans = 0;
        return ans;
       
    }
};