class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size(), i, j;
        vector<vector<int>> res(n+1, vector<int>(amount+1, 0));
        for(i=0; i<n+1; ++i){
            for(j=0; j<amount+1; ++j){
                if(j==0){
                    res[i][j]=1;
                    continue;
                }
                if(i==0){
                    res[i][j]=0;
                    continue;
                }
                if(coins[i-1]>j){
                    res[i][j]=res[i-1][j];
                }
                else{
                    res[i][j] = res[i-1][j] + res[i][j-coins[i-1]];
                }
            }
        }
        return res[n][amount];
    }
};