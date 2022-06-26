class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int n = prices.size();
        if(n==0) return 0;
        int maxPro = 0;
        for(int i=1;i<n;i++){
            if(prices[i]-mini > maxPro){
                maxPro = prices[i]-mini;
            }
            if(prices[i]<mini){
                mini = prices[i];
            }
        }
        return maxPro;
    }
};