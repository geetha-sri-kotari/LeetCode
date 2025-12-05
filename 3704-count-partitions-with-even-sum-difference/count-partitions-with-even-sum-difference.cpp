class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int cnt = 0;
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        int first_sum = 0;
        for(int i=0; i<nums.size()-1; i++) {
            total_sum -= nums[i];
            first_sum += nums[i];
            //cout << first_sum << " " << total_sum << endl;
            if((total_sum - first_sum) % 2 == 0) cnt++;
        }
        return cnt;
    }
};