class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size(), cols = matrix[0].size(), r, c, up, down, left, right, i, j;
        
        vector<vector<bool>> flags(rows, vector<bool>(cols, true));
        
        for(r=0; r<rows; ++r){
            for(c=0; c<cols; ++c){
                if(!flags[r][c]){
                    continue;
                }
                if(matrix[r][c]==0){
                    up=r-1;
                    while(up>-1 && matrix[up][c]!=0){
                        flags[up][c]=false;
                        up--;
                    }
                    down = r+1;
                    while(down<rows && matrix[down][c]!=0){
                        flags[down][c]=false;
                        down++;
                    }
                    right = c+1;
                    while(right<cols && matrix[r][right]!=0){
                        flags[r][right]=false;
                        right++;
                    }
                    left = c-1;
                    while(left>-1 && matrix[r][left]!=0){
                        flags[r][left]=false;
                        left--;
                    }
                }
            }
        }
        
        
        for(i=0; i<rows; ++i){
            for(j=0; j<cols; ++j){
                if(flags[i][j]==false){
                    matrix[i][j]=0;
                }
            }
        }
    }
};