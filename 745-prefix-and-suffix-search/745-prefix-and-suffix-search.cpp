class WordFilter 
{
public:
    
    unordered_map<string, int> m;
    WordFilter(vector<string>& words) 
    {
        for (int k = 0; k < words.size(); k++)
        {
            string wrd = words[k];
            int n = wrd.size();
            for (int i = 1; i <= n; i++)  //prefix len
            {
                string temp = wrd.substr(0, i) + ".";
                for (int j = 1; j <= n; j++) //suffix len
                {
                    m[temp+ wrd.substr(n-j, j)] = k;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) 
    {
        return m.count(prefix + "." + suffix) == 0 ? -1 : m[prefix + "." + suffix];
    }
};
/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */