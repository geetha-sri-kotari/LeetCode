class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        long long n = spells.size();
        long long m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for(long long i=0; i<n; i++) {
            long long low = 0, high = m-1;
            long long mid, poss_mid = m;
            while(low <= high) {
                mid = (low + high) / 2;
                //cout << mid << " ";
                if((long long)potions[mid] * (long long)spells[i] >= success) {
                    poss_mid = min(poss_mid, mid);
                    high = mid - 1;
                }
                else if((long long)potions[mid] * (long long)spells[i] < success) low = mid + 1;
                //cout << low << " " << high << " | ";
            }
            cout << poss_mid << " ";
            ans.push_back(m - poss_mid);
        }
        return ans;
    }
};