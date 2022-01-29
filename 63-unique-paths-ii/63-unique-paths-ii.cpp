class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size(), i, j;
        
        if(obstacleGrid[0][0]==1 || obstacleGrid[rows-1][cols-1]==1){
            return 0;
        }
        
        vector<vector<long long int>> res(rows, vector<long long int>(cols, 0));
        
        for(i=rows-1; i>=0; --i){
            for(j=cols-1; j>=0; --j){
                if(i==rows-1 && j==cols-1){
                    res[i][j]=1;
                    continue;
                }
                if(obstacleGrid[i][j]==1){
                    continue;
                }
                if(i==rows-1){
                    res[i][j] = res[i][j+1];
                    continue;
                }
                if(j==cols-1){
                    res[i][j] = res[i+1][j];
                    continue;
                }
                res[i][j] = res[i+1][j]+res[i][j+1];
                
            }
        }
        return res[0][0];
        
    }
};