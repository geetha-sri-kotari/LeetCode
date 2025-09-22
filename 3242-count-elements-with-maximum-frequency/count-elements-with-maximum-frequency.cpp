class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> frq;
        for(int i=0; i<nums.size(); i++) {
            frq[nums[i]]++;
        }
        int max_frq = 0;
        for(int i=0; i<nums.size(); i++) {
            max_frq = max(max_frq, frq[nums[i]]);
        }
        int cnt = 0;
        for(int i=0; i<nums.size(); i++) {
            if(frq[nums[i]] == max_frq) cnt++;
        }
        return cnt;
    }
};