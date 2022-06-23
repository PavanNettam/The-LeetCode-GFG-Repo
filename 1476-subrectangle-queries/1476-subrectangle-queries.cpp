class SubrectangleQueries {
public:
    vector<vector<int>> store;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        int r = rectangle.size();
        int c = rectangle[0].size();
        store.resize(r,vector<int>(c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                store[i][j] = rectangle[i][j];
            }
        }
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i=row1;i<=row2;i++){
            for(int j=col1;j<=col2;j++){
                store[i][j] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return store[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */