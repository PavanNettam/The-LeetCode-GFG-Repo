class Solution {
public:
  int maxWidthOfVerticalArea(vector<vector<int>> &points) {

    set<int> xs;
    for (auto &p : points) xs.insert(p.front());
    int res = 0, prev = *xs.begin();
    for (auto it = xs.begin(); it != xs.end(); it++) {
      res = max(res, *it - prev);
      prev = *it;
    }
    return res;
  }
};