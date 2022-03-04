class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>>pascal(query_row+1,vector<double>(query_glass+2,0.0));
        pascal[0][0]=poured;
        for(int i=0;i<query_row;i++)
            for(int j=0;j<=query_glass;j++)
            {
                pascal[i+1][j]+=max(0.0,(pascal[i][j]-1)/2.0);
                pascal[i+1][j+1]+=max(0.0,(pascal[i][j]-1)/2.0);
            }
        return min(1.0,pascal[query_row][query_glass]);
    }
};