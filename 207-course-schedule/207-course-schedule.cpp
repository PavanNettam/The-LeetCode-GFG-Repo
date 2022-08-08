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

/*
If we use the undirected graph alogo to find cycles then it detects cycle even though there is no cycle.
Thus to avoid this we use two visited vectors and update the second to unvisited while we back track.
Here v is the first visited array,
and temp is the second visited array.
temp will be updated to not visited while we backtrack.
*/