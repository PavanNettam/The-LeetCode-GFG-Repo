class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        while(k != 1){
            int i=n-2;
            while(v[i]>v[i+1]){
                i--;
            }
            int j=n-1;
            while(v[j]<v[i]){
                j--;
            }
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            reverse(v.begin()+i+1,v.end());
            k--;
        }
        string s;
        for(int i=0;i<v.size();i++){
            s.push_back(v[i] + '0');
        }
        return s;
    }
};