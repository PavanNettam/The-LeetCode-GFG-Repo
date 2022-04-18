
int arr[5000001];
int countPrimes(int n){
    int count = 0;
    for(int i=2;i<n;i++){
        if(arr[i]==0){
            count++;
            for(int j=i*2;j<=n;j+=i){
                arr[j] = 1;
            }
        }
    }
    return count;
}