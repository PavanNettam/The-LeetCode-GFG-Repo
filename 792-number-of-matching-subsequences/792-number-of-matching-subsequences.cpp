class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
    int n = s.size();
    int m = words.size();
    int ans = 0;
    
    unordered_map<int,set<int>> mp;
    
    for(int i=0;i<n;i++)
    {
        int no = s[i] - 'a';
        mp[no].insert(i);
    }
    
    
    for(auto it:words)
    {
        int i=0;
        int currind = -1;
        int flag = 0;
        
        while(i<it.size())
        {
            int no = it[i]-'a';
            auto x = mp[no].upper_bound(currind);
            
            if(x==mp[no].end())
            {
                break;
            }
            if(currind==-1||*x>currind)
            {
                currind = *x;
            }
            i++;
        }
        if(i==it.size())
        {
            ans++;
        }
    }
    return ans;
    }
};