class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') 
        return true;
        return false;
    }
    int maxFreqSum(string s) {
        unordered_map<char, int> frq;
        for(int i=0; i<s.size(); i++) {
            frq[s[i]]++;
        }
        int max_vowel = 0;
        int max_conso = 0;
        for(int i=0; i<s.size(); i++) {
            if(isVowel(s[i])) max_vowel = max(max_vowel, frq[s[i]]);
            else max_conso = max(max_conso, frq[s[i]]);
        }
        return max_vowel + max_conso;
    }
};