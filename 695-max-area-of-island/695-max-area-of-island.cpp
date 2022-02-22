class Solution {
public:
    int help(vector<vector<int>>& grid, int r, int c, int rows, int cols){
        if((r<0 || c<0 )||(r>=rows || c>=cols)){
            return 0;
        }
        
        if(grid[r][c]!=1){
            return 0;
        }
        
        grid[r][c] = 2;
        int l, ri, t, d;
        l=help(grid, r, c-1, rows, cols);
        ri=help(grid, r, c+1, rows, cols);
        t=help(grid, r-1, c, rows, cols);
        d=help(grid, r+1, c, rows, cols);
        
        return 1+l+ri+t+d;
        
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=INT_MIN, rows=grid.size(), cols=grid[0].size(), i, j;
        
        for(i=0; i<rows; ++i){
            for(j=0; j<cols; ++j){
                res=max(res, help(grid, i, j, rows, cols));
            }
        }
        
        return res;
        
    }
};