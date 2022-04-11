class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows=grid.size(), cols=grid[0].size(), i, j;
        k=(k%(rows*cols));
        vector<vector<int>> res(rows, vector<int>(cols, 0));
        for(i=0; i<rows; ++i){
            for(j=0; j<cols; ++j){
                res[(i+((j+k)/cols))%rows][(j+k)%cols]=grid[i][j];
            }
        }
        return res;
    }
};