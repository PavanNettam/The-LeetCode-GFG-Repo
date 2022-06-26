class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int l=0;
        int r = rows-1;
        int note = -1;
        while(l<=r){
            //cout<<l<<r<<endl;
            int mid = (l+r)/2;
            if(matrix[mid][0] == target) return 1;
            else if(matrix[mid][0] > target){
                if(mid-1 >= 0 && target>matrix[mid-1][0]){
                    note = mid-1;
                    break;
                }
                if(mid-1 == 0){
                    note = mid-1;
                    break;
                }
                r = mid-1;
            }else{
                if(mid+1 < rows && target<matrix[mid+1][0]){
                    note = mid;
                    break;
                }
                if(mid+1 == rows){
                    note = mid;
                    break;
                }
                l = mid+1;
            }
        }
        //cout<<"note"<<note<<endl;
        if(note == -1){
            return 0;
        }
        l = 0;
        r = cols-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(matrix[note][mid] == target){
                return 1;
            }else if(matrix[note][mid] < target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return 0;
    }
};