//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        int n = x.size();
        for(int i=0;i<n;i++){
            char ele = x[i];
            if(ele == '(' || ele == '[' || ele == '{'){
                s.push(ele);
            }else if(ele == ')'){
                if(s.empty()) return 0;
                else{
                    if(s.top()!='(') return 0;
                    else s.pop();
                }
            }
            else if(ele == ']'){
                if(s.empty()) return 0;
                else{
                    if(s.top()!='[') return 0;
                    else s.pop();
                }
            }
            else if(ele == '}'){
                if(s.empty()) return 0;
                else{
                    if(s.top()!='{') return 0;
                    else s.pop();
                }
            }
        }
        if(!s.empty()) return 0;
        return 1;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends