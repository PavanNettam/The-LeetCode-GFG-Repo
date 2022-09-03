class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int mini = prices[0];
        for(int i=0;i<prices.size();i++){
            if(prices[i]-mini > maxProfit){
                maxProfit = prices[i]-mini;
            }
            if(mini>prices[i]) mini = prices[i];
        }
        return maxProfit;
    }
};