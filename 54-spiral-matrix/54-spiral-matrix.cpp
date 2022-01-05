class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size();
        int m = matrix[0].size();
        int t= m*n;
        int topRow=0;
        int firstColumn = 0;
        int lastColumn = m-1;
        int bottomRow = n-1;
        while(t>0){
            for(int i=firstColumn; i<=lastColumn && t>0; ++i){
                int val = matrix[topRow][i];
                res.push_back(val);
                t--;
            }
            topRow++;
            for(int i=topRow; i<=bottomRow && t>0; ++i){
                int val = matrix[i][lastColumn];
                res.push_back(val);
                t--;
            }
            lastColumn--;
            for(int i=lastColumn; i>=firstColumn && t>0; --i){
                int val = matrix[bottomRow][i];
                res.push_back(val);
                t--;
            }
            bottomRow--;
            for(int i=bottomRow; i>=topRow && t>0; --i){
                int val = matrix[i][firstColumn];
                res.push_back(val);
                t--;
            }
            firstColumn++;
        }
        return res;
    }
};