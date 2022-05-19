class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>> &dp, int rows, int cols, int r, int c, int prev){
        if((r<0 or c<0) or (r>=rows or c>=cols)){
            return 0;
        }
        if(prev>=matrix[r][c]){
            return 0;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int r1 = dfs(matrix, dp, rows, cols, r+1, c, matrix[r][c]);
        int r2 = dfs(matrix, dp, rows, cols, r-1, c, matrix[r][c]);
        int r3 = dfs(matrix, dp, rows, cols, r, c+1, matrix[r][c]);
        int r4 = dfs(matrix, dp, rows, cols, r, c-1, matrix[r][c]);
        
        return dp[r][c]=1+max({r1, r2, r3, r4});
        
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int r, c, rows=matrix.size(), cols = matrix[0].size(), res=0;
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        for(r=0; r<rows; ++r){
            for(c=0;c<cols; ++c){
                
                res=max(res, dfs(matrix, dp, rows, cols, r, c, -1));
            }
        }
        return res;
    }
};