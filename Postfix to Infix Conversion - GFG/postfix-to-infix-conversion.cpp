//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        stack<string> s;
        for(int i=0;i<exp.size();i++){
            char ch = exp[i];
            if(ch == '^' || ch == '/' || ch == '*' || ch == '+' || ch == '-'){
                string first = s.top();
                s.pop();
                string second = s.top();
                s.pop();
                s.push("(" + second + ch + first + ")");
            }else{
                string temp;
                temp.push_back(ch);
                s.push(temp);
            }
        }
        return s.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends