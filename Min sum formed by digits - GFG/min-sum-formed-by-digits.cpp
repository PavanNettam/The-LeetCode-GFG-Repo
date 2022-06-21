// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        sort(arr,arr+n);
        long long f = 0;
        long long s = 0;
        for(int i=0;i<n;i++){
            if(i%2 == 0){
                f *= 10;
                f += arr[i];
            }else{
                s*=10;
                s += arr[i];
            }
        }
        return f+s;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends