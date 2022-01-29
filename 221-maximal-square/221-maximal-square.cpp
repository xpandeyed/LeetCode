class Solution {
public:
    
    int dynamic(vector<vector<char>>& matrix){
        int res = 0;
        int rows = matrix.size(), cols = matrix[0].size(), i, j, top, left, dig ;
        vector<vector<int>> results(rows, vector<int>(cols, 0));
        
        for(i=0; i<rows; ++i){
            for(j=0; j<cols; ++j){
                
                results[i][j]=matrix[i][j]-48;
                // cout << results[i][j] << " ";
                if(i==0 || j==0){
                    res = max(res, results[i][j]);
                    continue;
                }
                if(results[i][j]==0){
                    continue;
                }
                
                top = results[i-1][j];
                left = results[i][j-1];
                dig = results[i-1][j-1];
                results[i][j]+=min(top, min(left, dig));
                // cout << results[i][j] << " ";
                res=max(res, results[i][j]);
            }
            // cout << endl;
        }
        
        // cout << endl << endl;
        // for(auto x: results){
        //     for(auto y: x){
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }
        return res*res;
    }
    
    
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
        
        
        //For memo solution
        // int res = 0;
        // int rows = matrix.size(), cols = matrix[0].size(), i, j ;
        // vector<vector<int>> results(rows, vector<int>(cols, -1));
        // for(i=0; i<rows; ++i){
        //     for(j=0; j<cols; ++j){
        //         res = max(res, helper(matrix, i, j, results));
        //     }
        // }
        // return res*res;
        
        return dynamic(matrix);
    }
};