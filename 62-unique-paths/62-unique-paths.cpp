class Solution {
public:
    
    
    int dynamic(int m, int n){
        vector<vector<int>> res(m, vector<int>(n, 1));
        int i, j;
        for(i=m-1; i>=0; --i){
            for(j=n-1; j>=0; --j){
                if(i==m-1 && j==n-1){
                    continue;
                }
                if(i==m-1){
                    res[i][j] = res[i][j+1];
                    continue;
                }
                if(j==n-1){
                    res[i][j] = res[i+1][j];
                    continue;
                }
                res[i][j] =res[i+1][j] +res[i][j+1];
            }
        }
        return res[0][0];
    }
    
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
        //Memo code
        //vector<vector<int>> res(m, vector<int>(n, -1));
        //return helper(m, n, 0, 0, res);
        
        return dynamic(m, n);
    }
};