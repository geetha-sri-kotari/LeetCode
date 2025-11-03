class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int min_sum = 0, i = 0;
        while(i < neededTime.size()-1) {
            if(colors[i] == colors[i+1]) {
                int max_color = neededTime[i], color_sum = 0;
                while(colors[i] == colors[i+1]) {
                    color_sum += neededTime[i];
                    max_color = max(max_color, neededTime[i+1]);
                    i++;
                }
                color_sum += neededTime[i];
                //cout << color_sum << " " << max_color << endl;
                color_sum -= max_color;
                min_sum += color_sum;
            }
            else i++;
        }
        return min_sum;
    }
};