class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') return true;
        return false;
    }
    string sortVowels(string s) {
        string ans_s = "";
        vector<char> vowels;
        for(char ch : s) {
            if(isVowel(ch)) vowels.push_back(ch);
        }
        sort(vowels.begin(), vowels.end());
        int s_idx = 0, v_idx = 0;
        
        while(s_idx < s.size()) {
            if(isVowel(s[s_idx])) {
                ans_s += vowels[v_idx++];
                s_idx++;
            }
            else {
                ans_s += s[s_idx++];
            }
        }
        return ans_s;
    }
};