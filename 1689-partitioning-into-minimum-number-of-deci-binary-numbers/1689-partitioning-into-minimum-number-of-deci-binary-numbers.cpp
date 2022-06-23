class Solution {
public:
    int minPartitions(string n) {
        int i=1;
        int ans = n[0]-'0';
        while(i<n.size()){
            //cout<<ans<<" "<<int(n[i]-'0')<<endl;
            ans = (int(n[i]-'0')>ans)?int(n[i]-'0'):ans;
            i++;
        }
        return ans;
    }
};