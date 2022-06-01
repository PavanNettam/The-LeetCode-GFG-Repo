class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = INT_MAX;
        int maxPr = 0;
        for(int i=0;i<prices.size();i++){
            if(minVal > prices[i]){
                minVal = prices[i];
            }
            if(prices[i]-minVal > maxPr){
                maxPr = prices[i]-minVal;
            }
        }
        return maxPr;
    }
};