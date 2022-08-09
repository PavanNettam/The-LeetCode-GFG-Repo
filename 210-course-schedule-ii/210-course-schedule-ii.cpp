class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        for(int i=0; i<prerequisites.size() ;i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> ind(numCourses);
        for(int i=0;i<numCourses;i++){
            for(auto j:graph[i]){
                ind[j]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(ind[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            count++;
            for(auto i:graph[node]){
                ind[i]--;
                if(ind[i] == 0){
                    q.push(i);
                }
            }
        }
        if(count == numCourses){
            return ans;
        }
        ans.clear();
        return ans;
    }
};