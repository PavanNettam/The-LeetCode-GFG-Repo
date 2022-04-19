

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    int new[matrixSize][*matrixColSize];int maxi=0;
    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<*(matrixColSize);j++){
            if(i==0 || j==0){
                if(matrix[i][j]=='1'){
                    new[i][j]=1;
                }else{
                    new[i][j]=0;
                }
            }else{
                if(matrix[i][j]=='1'){
                    int temp = (new[i-1][j]<new[i][j-1])?new[i-1][j]:new[i][j-1];
                    temp = (temp<new[i-1][j-1])?temp:new[i-1][j-1];
                    new[i][j] = temp+1;
                }else{
                    new[i][j]=0;
                }
            }
            maxi = (maxi>new[i][j])?maxi:new[i][j];
        }
    }
    return maxi*maxi;
}