// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       if(n==1){
           nums[0] = 1;
           return nums;
       } 
       
       
       vector<long long int> left(n);
       vector<long long int> right(n);
       left[0] = 1;
       for(int i=1;i<n;i++){
           left[i] = nums[i-1]*left[i-1];
       }
       //for(int i=0;i<n;i++) cout<<left[i]<<" ";
       right[n-1]=1;
       for(int i=n-2;i>=0;i--){
           right[i] = nums[i+1]*right[i+1];
       }
       vector<long long int> ans(n);
       for(int i=0;i<n;i++){
           ans[i] = left[i]*right[i];
       }
       return ans;
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends