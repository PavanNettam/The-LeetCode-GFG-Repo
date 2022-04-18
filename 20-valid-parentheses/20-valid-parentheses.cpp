#include<cstring>

class Solution {
public:
    bool isValid(string s) {
        int i=0;
        //cout<<s<<endl;
        stack<char> st;
        while(s[i]!='\0'){
            //cout<<s[i]<<" "<<i<<endl;
            char c = s[i];
            i++;
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }
            else if(c == ')' || c == '}' || c == ']'){
                if(st.empty()) return 0;
                char copen = st.top();
                st.pop();
                if(c == ')' && copen == '(') continue;
                else if(c == ']' && copen == '[') continue;
                else if(c == '}' && copen == '{') continue;
                else return 0;
            }
            
        }
        if(st.empty()){
            return 1;
        }else{
            return 0;
        }
    }
};