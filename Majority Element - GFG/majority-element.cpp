// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        int freq[1000001];
        for(int i=0;i<1000001;i++){
            freq[i] = 0;
        }
        for(int i=0;i<size;i++){
            freq[a[i]]++;
        }
        for(int i=0;i<1000001;i++){
            if(freq[i] > size/2) return i;
        }
        return -1;
        // your code here
        
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends