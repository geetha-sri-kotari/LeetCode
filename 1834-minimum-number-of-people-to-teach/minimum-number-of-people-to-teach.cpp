class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> usersToTeach;
        for(int i=0; i<friendships.size(); i++) {
            int user1 = friendships[i][0] - 1;
            int user2 = friendships[i][1] - 1;
            bool canCommunicate = false;
            for(int lang1 : languages[user1]) {
                for(int lang2 : languages[user2]) {
                    if(lang1 == lang2) {
                        canCommunicate = true;
                        break;
                    }
                }
                if(canCommunicate) break;
            }
            if(!canCommunicate) {
                usersToTeach.insert(user1);
                usersToTeach.insert(user2);
            }
        }
        int minUsersToTeach = languages.size() + 1;
        for(int i=1; i<=n; i++) {
            int cnt = 0;
            for(int user : usersToTeach) {
                bool knowLang = false;
                for(int lang : languages[user]) {
                    if(lang == i) {
                        knowLang = true;
                        break;
                    }
                }
                if(!knowLang) cnt++;
            }
            minUsersToTeach = min(minUsersToTeach, cnt);
        }
        return minUsersToTeach;
    }
};