class NumMatrix {
public:    
    vector<vector<int>> m;
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size(), r, c;
        for(c=0;c<cols; ++c){
            for(r=1;r<rows; ++r){
                matrix[r][c]+=matrix[r-1][c];
            }
        }
        m=matrix;
    }
    
    int sumRegion(int row1, int c1, int row2, int c2) {
        int res = 0, c;
        for(c=c1; c<=c2; ++c){
            res+=m[row2][c];
            if(row1-1>-1){
                res-=m[row1-1][c];
            }
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */