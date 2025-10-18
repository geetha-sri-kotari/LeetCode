class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        dp[0][0] = grid[0][0];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i == 0 && j == 0) continue;
                int left = INT_MAX, top = INT_MAX;
                if(j >= 1) top = dp[i][j-1];
                if(i >= 1) left = dp[i-1][j];
                dp[i][j] = grid[i][j] + min(top, left);
            }
        }
        return dp[n-1][m-1];
    }
};