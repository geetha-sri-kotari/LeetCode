class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_pro = 1;
        int f_max_pro = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            max_pro *= nums[i];
            f_max_pro = max(f_max_pro, max_pro);
            if(max_pro == 0) max_pro = 1;
        }
        max_pro = 1;
        for(int i=nums.size()-1; i>=0; i--) {
            max_pro *= nums[i];
            f_max_pro = max(f_max_pro, max_pro);
            if(max_pro == 0) max_pro = 1;
        }
        return f_max_pro;
    }
};