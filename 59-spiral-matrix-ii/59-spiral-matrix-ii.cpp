class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int t=n*n;
        int val =1;
        int topRow=0;
        int firstColumn = 0;
        int lastColumn = n-1;
        int bottomRow = n-1;
        while(t>0){
            for(int i=firstColumn; i<=lastColumn && t>0; ++i){
                res[topRow][i]=val;
                t--;
                val++;
            }
            topRow++;
            for(int i=topRow; i<=bottomRow && t>0; ++i){
                res[i][lastColumn]=val;
                t--;
                val++;
            }
            lastColumn--;
            for(int i=lastColumn; i>=firstColumn && t>0; --i){
                res[bottomRow][i]=val;
                t--;
                val++;
            }
            bottomRow--;
            for(int i=bottomRow; i>=topRow && t>0; --i){
                res[i][firstColumn]=val;
                t--;
                val++;
            }
            firstColumn++;
        }
        return res;
    }
};