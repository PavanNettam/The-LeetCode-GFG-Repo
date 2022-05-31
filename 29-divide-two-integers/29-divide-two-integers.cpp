class Solution {
public:
    int divide(int a, int b) {
        if(a == INT_MIN and b == -1) return INT_MAX;
        long num = labs(a), div = labs(b), ans = 0;
        long temp = div, m=1;
        int sign = a > 0 ^ b > 0 ? -1 : 1;

        while(num >= div){
            if(temp <= num){
                temp <<= 1;
                m <<= 1;
            }
            else{
                ans += m >> 1;
                num -= temp >> 1;
                temp = div;
                m = 1;
            }
        }
        
        return sign*ans;
    }
};