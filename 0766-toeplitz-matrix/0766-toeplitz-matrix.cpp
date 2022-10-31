class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& m) {
        int rows = m.size(), cols = m[0].size();
        for(int i=0;i<cols; ++i){
            int ele = m[0][i], c = i;
            for(int j=0;j<rows and c<cols; ++j){
                if(m[j][c]!=ele) return false;
                ++c;
            }
        }
        // cout << "rows done" << endl;
        for(int i=1;i<rows;++i){
            int ele = m[i][0], r = i;
            // cout << ele << endl;
            for(int j=0; j<cols and r<rows; ++j){
                // cout << j << " " << r << endl;
                if(m[r][j]!=ele) return false;
                ++r;
            }
        }
        
        return true;
    }
};