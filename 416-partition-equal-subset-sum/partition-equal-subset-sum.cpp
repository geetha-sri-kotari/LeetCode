class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum % 2 != 0) return false;
        int targetSum = totalSum / 2;
        vector<bool> dp(targetSum+1, false);
        dp[0] = true;
        for(int num : nums) {
            for(int cSum = targetSum; cSum >= num; cSum--) {
                dp[cSum] = dp[cSum] || dp[cSum - num];
                if(dp[targetSum]) return true;
            }
        }
        return dp[targetSum];
    }
};