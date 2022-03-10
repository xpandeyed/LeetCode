class Solution {
public:
     int help(int row, int col, int rows, int cols, vector<vector<int>> &grid){
        if((row>=rows or col>=cols) or (row<0 or col<0)){
            return -1;
        }
        if(grid[row][col]==2){
            return 0;
        }
         if(grid[row][col]==0){
             return 0;
         }
         grid[row][col]=2;
         int r = help(row, col+1, rows, cols, grid);
         int l = help(row, col-1, rows, cols, grid);
         int t = help(row+1, col, rows, cols, grid);
         int d = help(row-1, col, rows, cols, grid);
        if(r==-1 or l==-1 or t==-1 or d==-1){
            return -1;
        }
         return 1+t+d+l+r;
    }
    
    
    int numEnclaves(vector<vector<int>>& grid) {
        int rows=grid.size(), cols = grid[0].size(), i, j;
        int res = 0;
        for(i=0; i<rows; ++i){
            for(j=0; j<cols ; ++j){
                if(grid[i][j]==1){
                    int temp = help(i, j, rows, cols, grid);
                    if(temp!=-1){
                        res+=temp;
                    }
                }
            }
        }
        return res;
    }
};