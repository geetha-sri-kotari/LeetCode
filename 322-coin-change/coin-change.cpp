class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        for(int i=1; i<=amount; i++) {
            int min_coins = INT_MAX;
            int left = 1, right = i-1;
            while(left <= right) {
                if(dp[left] > 0 && dp[right] > 0)
                min_coins = min(min_coins, dp[left] + dp[right]); 
                left++;
                right--;
            }
            for(int j=0; j<coins.size(); j++) {
                if(i % coins[j] == 0) 
                min_coins = min(min_coins, i/coins[j]);
            }
            if(min_coins != INT_MAX) dp[i] = min_coins;
        }
        //for(int i=0; i<dp.size(); i++) cout << dp[i] << " ";
        return dp[amount];
    }
};