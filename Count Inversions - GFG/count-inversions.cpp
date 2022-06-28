// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[], long long l,long long mid, long long r,long long n1){
        long long res = 0;
        long long temp[n1];
        long long i = l;
        long long n = mid+1;
        long long j = mid+1;
        long long m = r+1;
        long long k = 0;
        while(i<n && j<m){
            if(arr[i]<=arr[j]){
                temp[k++] = arr[i++];
            }else{
                temp[k++] = arr[j++];
                res += (n-i);
            }
        }
        while(i<n){
            temp[k++] = arr[i++];
        }
        while(j<m){
            temp[k++] = arr[j++];
        }
        i=l;
        for(long long l=0;l<k;l++){
            arr[i++] = temp[l];
        }
        return res;
    }
    long long int mergeSort(long long arr[], long long l,long long r,long long n){
        long long res = 0;
        if(l<r){
            long long mid = (l+r)/2;
            res += mergeSort(arr,l,mid,n);
            res += mergeSort(arr,mid+1,r,n);
            res += merge(arr,l,mid,r,n);
        }
        return res;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(arr,0,N-1,N);
    }

};
//inversionCount

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends