class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair <float,int>> p;
        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            float dist = sqrt(((x)*(x)) + ((y)*(y)));
            //cout<<"dist = "<<dist<<" i= "<<i<<endl;
            p.push_back(make_pair(dist,i));
        }
        sort(p.begin(),p.end());
        int temp = 0;
        vector<vector<int>> ret;
        for(int i=0;i<p.size();i++){
            if(temp>=k) break;
            vector<int> ele;
            ele.push_back(points[p[i].second][0]);
            ele.push_back(points[p[i].second][1]);
            ret.push_back(ele);
            temp++;
        }
        return ret;
    }
};