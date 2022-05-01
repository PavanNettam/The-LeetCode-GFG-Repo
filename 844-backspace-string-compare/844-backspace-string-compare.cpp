class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> t1;
        int i=0;
        while(s[i] != '\0'){
            if(s[i] == '#' && !s1.empty()){
                s1.pop();
            }else if(s[i]!='#'){
                s1.push(s[i]);
            }
            i++;
            
        }
        i = 0 ;
        while(t[i] != '\0'){
            if(t[i] == '#' && !t1.empty()){
                t1.pop();
            }else if(t[i]!='#') {
                t1.push(t[i]);
            }
            i++;
            
        }
        while(!s1.empty() && !t1.empty()){
            if(s1.top() != t1.top()) return 0;
            s1.pop();
            t1.pop();
        }
        if(s1.empty() && t1.empty())
            return 1;
        else
            return 0;
    }
};