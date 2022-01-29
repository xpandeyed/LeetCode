class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), i, j;
        vector<vector<int>> res(rows, vector<int>(cols, 0));
        for(i=rows-1; i>=0; --i){
            for(j=cols-1; j>=0; --j){
                if(i==rows-1 && j==cols-1){
                    res[i][j] = grid[i][j];
                    continue;
                }
                if(i==rows-1){
                    res[i][j] = res[i][j+1]+grid[i][j];
                    continue;
                }
                if(j==cols-1){
                    res[i][j] = res[i+1][j]+grid[i][j];
                    continue;
                }
                res[i][j]=grid[i][j]+min(res[i][j+1], res[i+1][j]);
            }
        }
        return res[0][0];
    }
};