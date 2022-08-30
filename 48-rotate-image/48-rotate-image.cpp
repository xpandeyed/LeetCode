class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {        
        int n = matrix.size(), l, h, i, j;
        for(i=0; i<n; ++i){
            for(j=i+1; j<n; ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(i=0; i<n; ++i){
            l=0;
            h=n-1;
            while(l<h){
                swap(matrix[i][l], matrix[i][h]);
                l++;
                h--;
            }
        }
    }
};