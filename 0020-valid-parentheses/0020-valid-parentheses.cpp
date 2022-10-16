class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }else{
                if(st.empty()){
                    return 0;
                }
                char ele = st.top();
                st.pop();
                if(c == ')' && ele != '('){
                    return 0;
                }
                if(c == '}' && ele != '{'){
                    return 0;
                }
                if(c == ']' && ele != '['){
                    return 0;
                }
            }
        }
        if(st.size() == 0){
            return 1;
        }
        return 0;
    }
};