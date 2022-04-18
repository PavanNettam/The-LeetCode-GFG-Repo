class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> h;
        for(int i=0;i<stones.size();i++){
            h.push(stones[i]);
        }
        int y,x;
        while(!h.empty()){
            y = h.top();
            h.pop();
            if(h.empty()) return y;
            x = h.top();
            h.pop();
            if(x!=y)  h.push(y-x);
        }
        return 0;
    }
};