class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int r = bank.size();
        int c = bank[0].size();
        int ans = 0;
        int prev = 0;
        for(int i=0;i<r;i++){
            int sum = 0;
            for(int j=0;j<c;j++){
                if(bank[i][j] == '1'){
                    sum++;
                }
            }
            if(sum != 0){
                ans += sum*prev;
                prev = sum;
            }
        }
        return ans;
    }
};