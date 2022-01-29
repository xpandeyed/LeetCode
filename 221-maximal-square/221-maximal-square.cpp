class Solution {
public:
    int helper(vector<vector<char>>& matrix, int r, int c, vector<vector<int>>& res){
        if(r==matrix.size() || c==matrix[0].size() ){
            return 0;
        }
        if(res[r][c]!=-1){
            return res[r][c];
        }
        if(matrix[r][c]=='0'){
            return res[r][c]=0;
        }
        return  res[r][c]=1+min(helper(matrix, r+1, c+1, res), min(helper(matrix, r, c+1, res), helper(matrix, r+1, c, res)));
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        int rows = matrix.size(), cols = matrix[0].size(), i, j ;
        vector<vector<int>> results(rows, vector<int>(cols, -1));
        for(i=0; i<rows; ++i){
            for(j=0; j<cols; ++j){
                res = max(res, helper(matrix, i, j, results));
            }
        }
        return res*res;
    }
};