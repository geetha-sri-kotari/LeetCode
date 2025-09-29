class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> prev_dp = grid[0];
        vector<int> curr_dp = grid[0];
        for(int i=1; i<n; i++) {
            for(int j=0; j<n; j++) {
                int min_prev = INT_MAX;
                for(int k=0; k<prev_dp.size(); k++) {
                    if(k == j) continue;
                    else min_prev = min(min_prev, prev_dp[k]);
                }
                //cout << min_prev << " ";
                curr_dp[j] = min_prev + grid[i][j];
                //cout << curr_dp[j] << " ";
            }
            //cout << endl;
            prev_dp = curr_dp;
            //curr_dp = {100};
        }
        return *min_element(curr_dp.begin(), curr_dp.end());
    }
};