class Solution {
public:
    int countCollisions(string directions) {
        int left = 0, right = directions.size()-1;
        while(left < directions.size() && directions[left] == 'L') left++;
        while(right >= 0 && directions[right] == 'R') right--;
        cout << left << " " << right;
        int collides = 0;
        for(int i=left; i<=right; i++) {
            if(directions[i] != 'S') collides++;
        }
        return collides;
    }
};