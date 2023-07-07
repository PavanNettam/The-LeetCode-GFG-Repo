//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        reverse(pre_exp.begin(),pre_exp.end());
        stack<string> s;
        for(int i=0;i<pre_exp.size();i++){
            char ch = pre_exp[i];
            if(ch == '^' || ch == '/' || ch == '*' || ch == '+' || ch == '-'){
                string first = s.top();
                s.pop();
                string second = s.top();
                s.pop();
                string comb = first + second + ch;
                s.push(comb);
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
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends