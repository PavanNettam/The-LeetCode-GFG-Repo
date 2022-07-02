class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int l = horizontalCuts[1] - horizontalCuts[0];
        int b = verticalCuts[1] - verticalCuts[0];
        for(int i=1;i<horizontalCuts.size();i++){
            l = max(l,horizontalCuts[i] - horizontalCuts[i-1]);
        }
        for(int i=1;i<verticalCuts.size();i++){
            b = max(b,verticalCuts[i] - verticalCuts[i-1]);
        }
        long long x = (long long)(l)*(long long)(b);
        return (x%1000000007);
    }
};