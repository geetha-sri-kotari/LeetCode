class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        vector<int> v2;
        string temp = "";
        for(int i=0; i<version1.size(); i++) {
           if(version1[i] != '.') temp += version1[i];
            if(version1[i] == '.') {
                v1.push_back(stoi(temp));
                //cout << stoi(temp) << " ";
                temp = "";
            }
        }
        v1.push_back(stoi(temp));
        //cout << stoi(temp) << endl;
        temp = "";
        for(int i=0; i<version2.size(); i++) {
            if(version2[i] != '.') temp += version2[i];
            if(version2[i] == '.') {
                v2.push_back(stoi(temp));
                //cout << stoi(temp) << " ";
                temp = "";
            }
        }
        v2.push_back(stoi(temp));
        //cout << stoi(temp) << endl;
        if(v1.size() < v2.size()) {
            while(v1.size() < v2.size()) v1.push_back(0);
        }
        if(v2.size() < v1.size()) {
            while(v2.size() < v1.size()) v2.push_back(0);
        }
        int idx1 = 0, idx2 = 0;
        while(idx1 < v1.size() && idx2 < v2.size()) {
            if(v1[idx1] < v2[idx2]) return -1;
            else if(v1[idx1] > v2[idx2]) return 1;
            idx1++;
            idx2++;
        }
        return 0;
    }
};