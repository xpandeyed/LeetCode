class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows=matrix.size(), cols=matrix[0].size(), r, c, res=0;
        for(r=1;r<rows;++r){
            for(c=1;c<cols;++c){
                if(matrix[r][c]==0) continue;
                matrix[r][c]+=min({matrix[r][c-1], matrix[r-1][c], matrix[r-1][c-1]});
                res+=matrix[r][c];
            }
        }
        // for(auto x: matrix){
        //     for(auto y: x){
        //         cout << y << ' ';
        //     }
        //     cout << endl;
        // }
        for(c=0;c<cols;++c) res+=matrix[0][c];
        for(r=1;r<rows;++r) res+=matrix[r][0];
        return res;
    }
};