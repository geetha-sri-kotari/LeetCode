class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp;
        for(int i=0; i<triangle.size(); i++) {
            vector<int> temp;
            for(int j=0; j<triangle[i].size(); j++) temp.push_back(100001);
            dp.push_back(temp);
        }
        dp[0][0] = triangle[0][0];
        for(int i=0; i<triangle.size(); i++) {
            for(int j=0; j<triangle[i].size(); j++) {
                long long possible1 = 100001, possible2 = 100001;
                if(i == 0 && j == 0) continue;
                else if(i > 0 && j == 0) {
                    possible1 = dp[i-1][j] + triangle[i][j];
                }
                else if(i > 0 && j == i) {
                    possible2 = dp[i-1][j-1] + triangle[i][j];
                }
                else if(j > 0 && i > 0) {
                    possible1 = dp[i-1][j] + triangle[i][j];
                    possible2 = dp[i-1][j-1] + triangle[i][j];
                }
                dp[i][j] = min(possible1, possible2);
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};