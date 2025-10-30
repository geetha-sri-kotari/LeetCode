class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int max_cnt = target[0];
        int maxi = target[0];
        for(int i=1; i<target.size(); i++) {
            if(target[i] > target[i-1]) {
                //cout << target[i] - target[i-1] << " ";
                max_cnt += ( target[i] - target[i-1]);
                //cout << max_cnt << " ";
            }
        }
        return max_cnt;
    }
};