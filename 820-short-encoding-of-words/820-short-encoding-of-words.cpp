class Solution {
    private :
    struct trie{
        bool isend;
        struct trie* ch[26];
    };
    trie* node=new trie();
public:
    int ans=0;
    void insert(string s){
        trie* temp=node;
        for(int i=s.length()-1 ;i>=0;i--){
            if(!temp->ch[s[i]-'a']) {
                temp->ch[s[i]-'a']=new trie();
            }
            temp=temp->ch[s[i]-'a'];
        }
        temp->isend=true;
    }
    
    void dfs(trie* temp,int c){
        int fl=0;
        for(int i=0;i<26;i++){
            if(temp->ch[i]!=NULL){
                dfs( temp->ch[i] , c+1);
                fl=1;
            }
        }
        if(fl==0) ans+=c+1;
    }
    
    int minimumLengthEncoding(vector<string>& w) {
        
        if(w.size()==1) return w[0].size()+1;
        
        for(string st : w) insert(st);
        
        dfs(node,0);
        return ans;
    }
};