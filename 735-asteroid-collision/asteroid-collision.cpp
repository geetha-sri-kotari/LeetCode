class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> positives;
        vector<int> res;
        for(int i=0; i<asteroids.size(); i++) {
            if(asteroids[i] > 0) positives.push(asteroids[i]);
            else {
                if(positives.empty()) {
                    res.push_back(asteroids[i]);
                }
                else {
                    while(!positives.empty() && positives.top() < abs(asteroids[i]))
                    positives.pop();
                    if(!positives.empty() && positives.top() == abs(asteroids[i])) {
                        positives.pop();
                        continue;
                    }
                    else if(positives.empty()) {
                        res.push_back(asteroids[i]);
                    }
                    else {
                        continue;
                        // vector<int> temp;
                        // while(!positives.empty()) {
                        //     temp.push_back(positives.top());
                        //     positives.pop();
                        // }
                        // reverse(temp.begin(), temp.end());
                        // for(auto it : temp) res.push_back(it);
                    }
                }
            }
        }
        vector<int> temp;
        while(!positives.empty()) {
            temp.push_back(positives.top());
            positives.pop();
        }
        reverse(temp.begin(), temp.end());
        for(auto it : temp) res.push_back(it);
        return res;
    }
};