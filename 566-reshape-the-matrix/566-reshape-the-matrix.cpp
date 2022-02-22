class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rows=mat.size(), cols=mat[0].size();
        if(r*c!=rows*cols){
            return mat;
        }
        vector<vector<int>> res;
        
        vector<int> temp;
        
        for(auto x: mat){
            for(auto y: x){
                temp.push_back(y);
                if(temp.size()==c){
                    res.push_back(temp);
                    temp.clear();
                }
            }
        }
        
        return res;
    }
};