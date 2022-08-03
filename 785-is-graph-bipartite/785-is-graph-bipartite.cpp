class Solution {
public:
    int bfsColor(int curr,vector<vector<int>> graph, vector<int>& color){
        queue<int> q;
        q.push(curr);
        color[curr] = 0;
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            for(int i=0;i<graph[ele].size();i++){
                if(color[graph[ele][i]] == -1){
                    color[graph[ele][i]] = (color[ele]==0)?1:0;
                    q.push(graph[ele][i]);
                }else{
                    if(color[graph[ele][i]] == color[ele]){
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(!bfsColor(i,graph,color)){
                    return 0;
                }
            }
        }
        return 1;
    }
};

/*
Performed a bfs:
Idea is to color the graph is opposite colors for adjacent nodes, if we once we visit a node we check all its adjacent nodes and see if they are colored.
(1) If they are not colored then color oppositely 
(2) else check the already existing color if its not opposite then reutrn false.
*/