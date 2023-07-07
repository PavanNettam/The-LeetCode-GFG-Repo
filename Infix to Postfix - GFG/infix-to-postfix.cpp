//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    int prec(char ch){
        if(ch == '^'){
            return 3;
        }else if(ch == '*' || ch == '/'){
            return 2;
        }else if(ch == '+' || ch == '-'){
            return 1;
        }else{
            return 0;
        }
    }
    public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        string ans = "";
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(c == '('){
                st.push(c);
            }else if(c == ')'){
                while(st.top()!='('){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }else if(c == '^' || c == '/' || c == '*' || c == '+' || c == '-'){
                while(!st.empty() && prec(c) <= prec(st.top())){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(c);
            }else{
                ans.push_back(c);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends