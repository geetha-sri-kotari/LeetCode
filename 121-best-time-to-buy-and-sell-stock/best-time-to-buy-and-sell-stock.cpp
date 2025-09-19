class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cheapest = prices[0];
        int max_profit = 0;
        for(int i=1; i<prices.size(); i++) {
            if(prices[i] < cheapest) {
                cheapest = prices[i];
            }
            max_profit = max(max_profit, prices[i]-cheapest);
        }
        return max_profit;
    }
};