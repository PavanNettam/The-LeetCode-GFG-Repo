// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        int ans = 1;
        for(int i=1;i<D;i++){
            ans *= 10;
        }
        S -= 1;
        int temp,addi,x = 1;
        while(S>0){
            if(S<9){
                temp = S;
                S = 0;
            }else{
                temp = 9;
                S-=9;
            }
            addi = temp*x;
            x *= 10;
            ans += addi;
            //cout<<S<<" "<<ans<<endl;
        }
        //cout<<S<<endl;
        if(S<0) ans = -1;
        string stri = to_string(ans);
        if(stri.size() != D) return "-1";
        return stri;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends