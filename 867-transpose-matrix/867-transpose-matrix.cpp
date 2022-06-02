class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows=matrix.size(), cols = matrix[0].size(), r, c;
        vector<vector<int>> res(cols, vector<int>(rows, 0));
        for(r=0;r<rows;++r){
            for(c=0;c<cols;++c){
                res[c][r]=matrix[r][c];
            }
        }
        return res;
    }
};