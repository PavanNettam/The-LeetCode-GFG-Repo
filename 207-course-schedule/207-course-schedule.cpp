class Solution {
public:
    int dfsCycle(vector<int> graph[],int cur,vector<int>& v,vector<int>& temp){
        v[cur] = 1;
        temp[cur] = 1;
        for(auto i:graph[cur]){
            if(!v[i]){
                if(dfsCycle(graph,i,v,temp)){
                    return 1;
                }
            }else{
                if(temp[i] == 1){
                    return 1;
                }
            }
        }
        temp[cur] = 0;
        return 0;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> v(numCourses,0);
        vector<int> temp(numCourses,0);
        vector<int> graph[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(!v[i]){
                if(dfsCycle(graph,i,v,temp)){
                    return 0;
                }
            }
        }
        return 1;
    }
};