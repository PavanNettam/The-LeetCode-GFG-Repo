class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<int>> v( n+1 , vector<int> (n+1, 6001)),temp; 
        
        for(int i=0;i<times.size();i++){
            v[times[i][0]][times[i][1]] = times[i][2];
        }
        for(int i=1;i<=n;i++){
            v[i][i] = 0;
        
        }
        temp = v;
    
        for(int x=1;x<=n;x++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(v[i][x]+v[x][j] < v[i][j]){
                        temp[i][j] = v[i][x]+v[x][j];
                    }
                }
            }
            
            v = temp;
        }
        
    
        int maxi = v[k][1];
        for(int i=1;i<=n;i++){
            maxi = max(maxi,v[k][i]);
        }
        if(maxi >= 6001){
            return -1;
        }
        
        return maxi;
    }
};