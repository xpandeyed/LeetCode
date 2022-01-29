class Solution {
public:
    int helper(int m, int n, int r, int c, vector<vector<int>> &res){
        if(r==m-1 && c==n-1){
            return res[r][c] = 1;
        }
        if(res[r][c]!=-1){
            return res[r][c];
        }
        if(r==m-1){
            return res[r][c] =helper(m, n, r, c+1, res);
        }
        if(c==n-1){
            return res[r][c] =helper(m, n, r+1, c, res);
        }
        return res[r][c] = (helper(m, n, r, c+1, res) + helper(m, n, r+1, c, res));
        
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        return helper(m, n, 0, 0, res);
    }
};