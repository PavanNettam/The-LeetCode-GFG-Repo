class Solution {
public:
    int dfsColor(vector<vector<int>> graph,vector<int>& color,int curPos,int curCol){
        color[curPos] = curCol;
        for(auto i:graph[curPos]){
            if(color[i] == -1){
                int nextCol = (curCol==0)?1:0;
                if (!dfsColor(graph,color,i,nextCol)){
                    return 0;
                }
            }else{
                if(curCol == color[i]){
                    return 0;
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
                if(!dfsColor(graph,color,i,0)){
                    return 0;
                }
            }
        }
        return 1;
    }
};

/*
Using DFS:
Traverse and check for opposite color
*/