class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int count = 0;
        int mod = 1000000007;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i=0;i<n;i++){
            int t = target - arr[i];
            int j = i+1;
            int k = n-1;
            while(j<k){
                if(arr[j]+arr[k] < t){
                    j++;
                }else if(arr[j]+arr[k] > t){
                    k--;
                }else if(arr[j] != arr[k]){
                    int left = 1;
                    int right = 1;
                    while(j+1<k && arr[j] == arr[j+1]){
                        left++;
                        j++;
                    }
                    while(k-1>j && arr[k] == arr[k-1]){
                        right++;
                        k--;
                    }
                    count += right*left;
                    count %= mod;
                    j++;
                    k--;
                }else{
                    count += (k-j+1)*(k-j)/2;
                    count %= mod;
                    break;
                }
            }
            
        }
        return count;
    }
};