class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        sort(people.begin(), people.end(), [](const vector<int> &v1, const vector<int> &v2) {
            if (v1[1] != v2[1]) return v1[1] < v2[1];
            return v1[0] < v2[0];
        });
        
        for (int i = 0; i < people.size(); i++) {
            int j = 0, count = 0;
            while (j < res.size()) {
                if (res[j][0] >= people[i][0]) count++;
                if (count > people[i][1]) break;
                j++;
            }
            res.insert(res.begin() + j, people[i]);
        }
        return res;
    }
};