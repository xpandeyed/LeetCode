class Solution {
public:
    
    
    void dfs(vector<vector<int>> &matrix, int i, int j, int rows, int cols){
        if((i<0 || i>=rows) || (j<0 || j>=cols)){
            return ;
        }
        
        if(matrix[i][j]!=1){
            return ;
        }
        
        matrix[i][j]=2;
        dfs(matrix, i+1, j, rows, cols);
        dfs(matrix, i, j+1, rows, cols);
        dfs(matrix, i, j-1, rows, cols);
        dfs(matrix, i-1, j, rows, cols);
    }
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        int rows =grid.size(), cols=grid[0].size(), i, j, res=0;
        
        vector<vector<int>> matrix(rows, vector<int>(cols));
        
        for(i=0; i<rows; ++i){
            for(j=0; j<cols; ++j){
                matrix[i][j] = (grid[i][j]-'0');
            }
        }
        
        
        
        
        for(i=0; i<rows; ++i){
            for(j=0; j<cols; ++j){
                if(matrix[i][j]==1){
                    res++;
                    dfs(matrix, i, j, rows, cols);
                }
            }
        }
        
        
        return res;
        
    }
};